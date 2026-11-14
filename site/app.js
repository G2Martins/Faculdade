/* Faculdade · Árvore de Derivação
   Roteador por hash: #/  ·  #/s/<semestre>  ·  #/s/<sem>/<disciplina>  ·  #/s/<sem>/<disc>/<tópico>  ·  #/f/<arquivo>
   Todo texto vindo de dados passa por esc(); markdown passa por DOMPurify antes de entrar no DOM. */
'use strict';
(() => {
  const REPO = 'G2Martins/Faculdade', BRANCH = 'main';
  const COR = { 1: '#d4482b', 2: '#b7790a', 3: '#2f8f5b', 4: '#2463a8', 5: '#8a4fb3', 6: '#c23a6b', 7: '#7a7568', 8: '#0e7c76', extras: '#7a6232' };
  const LING = { c: 'c', h: 'c', cpp: 'cpp', hpp: 'cpp', java: 'java', py: 'python', m: 'matlab', json: 'json', js: 'javascript', sql: 'sql', mines: '', txt: '', csv: '' };
  const ROTULO = { c: 'C', h: 'C', cpp: 'C++', java: 'Java', py: 'Python', m: 'MATLAB', md: 'Markdown', pdf: 'PDF', tldr: 'tldraw', png: 'Imagem', jpg: 'Imagem', jpeg: 'Imagem', ipynb: 'Notebook', mines: 'MineonScript', html: 'HTML', json: 'JSON', txt: 'Texto' };
  const KATEX = 'https://cdn.jsdelivr.net/npm/katex@0.16.10/dist/';
  const MERMAID = 'https://cdn.jsdelivr.net/npm/mermaid@10.9.1/dist/mermaid.min.js';

  const app = document.getElementById('app');
  const trilha = document.getElementById('trilha');
  const rodape = document.getElementById('rodape');

  const esc = s => String(s ?? '').replace(/[&<>"']/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' })[c]);
  const url = p => p.split('/').map(encodeURIComponent).join('/');
  const gh = (p, modo = 'blob') => `https://github.com/${REPO}/${modo}/${BRANCH}/${url(p)}`;
  const rota = (...p) => '#/' + p.map(encodeURIComponent).join('/');
  const nome = p => p.split('/').pop();
  const norm = s => String(s ?? '').normalize('NFD').replace(/[̀-ͯ]/g, '').toLowerCase();
  const slug = s => norm(s).replace(/[^a-z0-9]+/g, '-').replace(/^-|-$/g, '');
  const curto = n => n.split(/\s[—(]/)[0];
  const ext = p => (nome(p).includes('.') ? nome(p).split('.').pop() : '').toLowerCase();
  const tipoDe = t => t === 'md' ? 'md' : t === 'pdf' ? 'pdf' : (t in LING) ? 'code'
    : ['png', 'jpg', 'jpeg', 'gif', 'svg', 'webp'].includes(t) ? 'img' : ['mp4', 'webm'].includes(t) ? 'video'
    : ['wav', 'mp3', 'ogg'].includes(t) ? 'audio' : t === 'html' ? 'html' : 'outro';
  const semNome = s => s.id === 'extras' ? 'Extras' : `${s.id}° Semestre`;
  const semNt = s => s.id === 'extras' ? '<extras>' : `<semestre-${s.id}>`;
  const nArq = d => d.topicos.reduce((n, t) => n + t.arquivos.length, 0);
  const nArqS = s => s.disciplinas.reduce((n, d) => n + nArq(d), 0);
  const chips = (lista, forte = false) => lista?.length ? `<ul class="chips${forte ? ' forte' : ''}">${lista.map(c => `<li>${esc(c)}</li>`).join('')}</ul>` : '';
  const tipoTag = t => `<span class="tipo t-${tipoDe(t)}">${esc(t || '—')}</span>`;

  let D;
  const ARQ = new Map();          // path → { s, d, t, a }
  const SEM = id => D.semestres.find(s => s.id === id);

  /* ---------- carregamento de texto e libs ---------- */
  const cacheTexto = new Map();
  function texto(path) {
    if (!cacheTexto.has(path)) {
      cacheTexto.set(path, fetch(url(path)).then(async r => {
        if (!r.ok) throw new Error(`HTTP ${r.status} ao buscar ${path}`);
        const buf = await r.arrayBuffer();
        try { return new TextDecoder('utf-8', { fatal: true }).decode(buf); }
        catch { return new TextDecoder('windows-1252').decode(buf); }   // códigos antigos salvos no Windows
      }).catch(e => { cacheTexto.delete(path); throw e; }));
    }
    return cacheTexto.get(path);
  }
  const libs = {};
  function carregar(src) {
    return libs[src] ??= new Promise((ok, falha) => {
      const css = src.endsWith('.css');
      const el = css ? Object.assign(document.createElement('link'), { rel: 'stylesheet', href: src })
        : Object.assign(document.createElement('script'), { src });
      el.onload = ok; el.onerror = () => falha(new Error('falha ao carregar ' + src));
      document.head.append(el);
    });
  }
  const escuro = () => (document.documentElement.dataset.theme || (matchMedia('(prefers-color-scheme: dark)').matches ? 'dark' : 'light')) === 'dark';

  /* ---------- markdown ---------- */
  function resolver(base, rel) {
    const partes = base.split('/').slice(0, -1);
    for (const seg of rel.split('/')) {
      if (seg === '..') partes.pop();
      else if (seg && seg !== '.') partes.push(seg);
    }
    return partes.join('/');
  }
  function protegerMath(md) {   // tira $…$ do alcance do markdown (senão _ e * viram ênfase)
    const guarda = [];
    const pedacos = md.split(/(```[\s\S]*?```|`[^`\n]*`)/g);
    const out = pedacos.map((p, i) => i % 2 ? p : p.replace(/\$\$[\s\S]+?\$\$|(?<![\\\w$])\$(?=\S)[^$\n]+?(?<=\S)\$(?![\d$])/g, m => {
      guarda.push(m); return `@@MATH${guarda.length - 1}@@`;
    })).join('');
    return { out, guarda };
  }
  async function renderMd(path, alvo) {
    try {
      const { out, guarda } = protegerMath(await texto(path));
      let html = DOMPurify.sanitize(marked.parse(out, { gfm: true }));
      html = html.replace(/@@MATH(\d+)@@/g, (_, i) => {
        const m = guarda[+i], bloco = m.startsWith('$$');
        return `<span class="math" data-bloco="${bloco ? 1 : ''}">${esc(bloco ? m.slice(2, -2) : m.slice(1, -1))}</span>`;
      });
      alvo.innerHTML = html;
      ajustarMd(alvo, path);
      if (guarda.length) await math(alvo);
      await diagramas(alvo);
    } catch (e) {
      alvo.innerHTML = `<p class="erro">Não consegui carregar este arquivo (${esc(e.message)}). <a href="${gh(path)}" target="_blank" rel="noopener">Ver no GitHub ↗</a></p>`;
    }
  }
  function ajustarMd(el, path) {
    el.querySelectorAll('h1, h2, h3, h4').forEach(h => { h.id = 'h-' + slug(h.textContent); });
    el.querySelectorAll('a[href]').forEach(a => {
      const h = a.getAttribute('href');
      if (/^[a-z][a-z0-9+.-]*:/i.test(h)) { a.target = '_blank'; a.rel = 'noopener'; return; }
      if (h.startsWith('#')) { a.dataset.ancora = h.slice(1); a.setAttribute('href', location.hash || '#/'); return; }
      let alvo; try { alvo = resolver(path, decodeURI(h.split('#')[0])); } catch { return; }
      if (ARQ.has(alvo)) a.setAttribute('href', rota('f', alvo));
      else { a.href = gh(alvo, ext(alvo) ? 'blob' : 'tree'); a.target = '_blank'; a.rel = 'noopener'; }
    });
    el.querySelectorAll('img[src]').forEach(img => {
      const s = img.getAttribute('src');
      if (!/^[a-z][a-z0-9+.-]*:/i.test(s)) { try { img.src = url(resolver(path, decodeURI(s))); } catch { /* deixa como está */ } }
      img.loading = 'lazy';
    });
    el.querySelectorAll('pre code').forEach(code => {
      const lang = (code.className.match(/language-([\w-]+)/) || [])[1];
      if (lang === 'mermaid') {
        const div = document.createElement('div'); div.className = 'mermaid'; div.textContent = code.textContent;
        code.parentElement.replaceWith(div);
      } else if (lang && hljs.getLanguage(lang)) hljs.highlightElement(code);
    });
  }
  async function math(el) {
    try {
      await Promise.all([carregar(KATEX + 'katex.min.css'), carregar(KATEX + 'katex.min.js')]);
      el.querySelectorAll('span.math').forEach(s => katex.render(s.textContent, s, { displayMode: !!s.dataset.bloco, throwOnError: false }));
    } catch { /* sem KaTeX, a fórmula fica como texto */ }
  }
  async function diagramas(el) {
    const nos = el.querySelectorAll('.mermaid');
    if (!nos.length) return;
    try {
      await carregar(MERMAID);
      mermaid.initialize({ startOnLoad: false, securityLevel: 'strict', theme: 'neutral' });
      await mermaid.run({ nodes: nos });
    } catch { /* sem Mermaid, o diagrama fica como texto */ }
  }

  /* ---------- outros visualizadores ---------- */
  async function renderCodigo(path, alvo) {
    try {
      const txt = await texto(path), lang = LING[ext(path)];
      const code = document.createElement('code');
      if (lang && hljs.getLanguage(lang)) code.innerHTML = hljs.highlight(txt, { language: lang, ignoreIllegals: true }).value;
      else code.textContent = txt;
      const n = txt.replace(/\n$/, '').split('\n').length;
      alvo.innerHTML = `<div class="codigo"><div class="gutter" aria-hidden="true">${Array.from({ length: n }, (_, i) => i + 1).join('\n')}</div><pre></pre></div>`;
      alvo.querySelector('pre').append(code);
    } catch (e) {
      alvo.innerHTML = `<p class="erro">Não consegui carregar este arquivo (${esc(e.message)}).</p>`;
    }
  }
  function visualizador(path) {   // HTML do corpo conforme o tipo; md e código são preenchidos depois
    const t = tipoDe(ext(path)), src = esc(url(path)), n = esc(nome(path));
    switch (t) {
      case 'md': return `<div class="doc-corpo md" data-md="${esc(path)}"><p class="carregando">derivando</p></div>`;
      case 'code': return `<div data-code="${esc(path)}"><p class="carregando" style="padding:1rem">carregando código</p></div>`;
      case 'pdf': return `<iframe class="pdf" src="${src}" title="${n}" loading="lazy"></iframe>`;
      case 'img': return `<div class="midia"><img src="${src}" alt="${n}" loading="lazy"></div>`;
      case 'video': return `<div class="midia"><video src="${src}" controls preload="metadata"></video></div>`;
      case 'audio': return `<div class="midia"><audio src="${src}" controls preload="metadata"></audio></div>`;
      case 'html': return `<iframe class="pdf" src="${src}" title="${n}" sandbox="allow-scripts" loading="lazy"></iframe>`;
      default: return `<p class="aviso-arquivo">Este tipo de arquivo (<b>${esc(ext(path) || 'sem extensão')}</b>) não abre no navegador. <a href="${src}" download>Baixar</a> ou <a href="${gh(path)}" target="_blank" rel="noopener">ver no GitHub ↗</a>.</p>`;
    }
  }
  function preencher(el) {
    el.querySelectorAll('[data-md]').forEach(n => renderMd(n.dataset.md, n));
    el.querySelectorAll('[data-code]').forEach(n => renderCodigo(n.dataset.code, n));
  }

  /* ---------- views ---------- */
  function capa({ numeral, eyebrow, titulo, lead, extra = '' }) {
    return `<section class="capa${numeral ? '' : ' sem-numeral'}">
      ${numeral ? `<div class="numeral" aria-hidden="true">${esc(numeral)}</div>` : ''}
      <div><p class="eyebrow">${esc(eyebrow)}</p><h1>${esc(titulo)}</h1>${lead ? `<p class="lead">${esc(lead)}</p>` : ''}${extra}</div>
      <span class="faixa" aria-hidden="true"></span></section>`;
  }

  function home() {
    const t = D.totais;
    const ramos = D.semestres.map((s, i) => {
      const ult = i === D.semestres.length - 1;
      const desc = s.disciplinas.length ? s.disciplinas.map(d => curto(d.nome)).join(' · ') : 'em andamento';
      return `<li><a class="ramo${s.disciplinas.length ? '' : ' vazio-ramo'}" data-acc style="--acc:${COR[s.id]};--i:${i}" href="${rota('s', s.id)}">
        <span class="g">${ult ? '└──' : '├──'}</span><span class="nt">${esc(semNt(s))}</span><span class="d">${esc(desc)}</span><span class="n">${nArqS(s)} folhas</span></a></li>`;
    }).join('');
    const destaques = (D.destaques || []).map(h => {
      const s = SEM(String(h.sem)), d = s?.disciplinas.find(x => x.nome === h.disc);
      if (!d) return '';
      return `<a class="cartao" data-acc style="--acc:${COR[s.id]}" href="${rota('s', s.id, d.slug)}"><span class="seta-c">↗</span>
        <p class="eyebrow">${esc(semNome(s))} · ${esc(curto(d.nome))}</p><h3>${esc(h.titulo)}</h3><p>${esc(h.texto)}</p>${chips(h.tags)}</a>`;
    }).join('');
    const conta = {};
    for (const [p] of ARQ) { const r = ROTULO[ext(p)] || 'Outros'; conta[r] = (conta[r] || 0) + 1; }
    const ranking = Object.entries(conta).sort((a, b) => b[1] - a[1]).slice(0, 9);
    const max = ranking[0]?.[1] || 1;
    const barras = ranking.map(([r, n]) => `<div class="barra"><span>${esc(r)}</span><span class="trilho"><span class="cheio" style="--w:${(n / max * 100).toFixed(1)}%"></span></span><span class="q">${n}</span></div>`).join('');
    return {
      acc: COR[8], titulo: '',
      html: `<section class="hero">
        <div>
          <p class="eyebrow">Engenharia da Computação · IESB · 2023 → 2026</p>
          <h1>Faculdade<span class="caret">_</span></h1>
          <p class="lead">A graduação inteira como uma <em>árvore de derivação</em>: cada semestre é uma regra, cada disciplina é uma subárvore e cada arquivo é uma folha. Tudo aqui é o conteúdo real do repositório, aberto para estudar.</p>
          <div class="cta"><a class="btn" href="${rota('s', '8', 'compiladores')}">Ver o transpilador →</a><button class="btn fantasma" type="button" data-busca>Buscar <kbd>/</kbd></button></div>
        </div>
        <figure class="deriv"><figcaption>&lt;graduacao&gt;<span class="meta">::= semestre*</span></figcaption><ol>${ramos}</ol></figure>
      </section>
      <section class="numeros" aria-label="Números do repositório">
        <div><b>${t.semestres}</b><span>semestres</span></div><div><b>${t.disciplinas}</b><span>disciplinas</span></div>
        <div><b>${t.topicos}</b><span>tópicos</span></div><div><b>${t.arquivos}</b><span>folhas · arquivos</span></div>
      </section>
      <h2 class="secao" data-nt="&lt;destaques&gt;">O que foi construído</h2><div class="grade">${destaques}</div>
      <h2 class="secao" data-nt="&lt;folhas&gt;">Do que a árvore é feita</h2><div class="barras">${barras}</div>`,
    };
  }

  function semestre(id) {
    const s = SEM(id); if (!s) return null;
    const langs = [...new Set(s.disciplinas.flatMap(d => d.linguagens || []))];
    const cards = s.disciplinas.map(d => `<a class="cartao" href="${rota('s', s.id, d.slug)}"><span class="seta-c">↗</span>
      <p class="eyebrow">${esc(d.codigo || semNome(s))}</p><h3>${esc(d.nome)}</h3><p>${esc(d.resumo)}</p>
      <p class="conta">${d.topicos.length} tópicos · ${nArq(d)} folhas</p>${chips((d.conceitos || []).slice(0, 6))}</a>`).join('');
    const status = s.status === 'andamento' ? 'em andamento' : 'concluído';
    return {
      acc: COR[s.id], titulo: semNome(s), trilha: [[semNt(s)]],
      html: capa({
        numeral: s.id === 'extras' ? '+' : s.id + '°', eyebrow: `${semNt(s)} · ${status}`, titulo: semNome(s), lead: s.resumo,
        extra: `<p class="meta-linha"><span><b>${s.disciplinas.length}</b> disciplinas</span><span><b>${nArqS(s)}</b> folhas</span>${langs.length ? `<span>${esc(langs.join(' · '))}</span>` : ''}</p>`,
      }) + `<h2 class="secao" data-nt="&lt;disciplinas&gt;">Disciplinas</h2>
        <div class="grade">${cards || '<p class="vazio">Semestre em andamento: nenhuma disciplina registrada ainda.</p>'}</div>`
        + (s.readme ? `<h2 class="secao" data-nt="README.md">Diário do semestre</h2>
          <article class="doc"><div class="doc-cab"><span class="nome">${esc(s.readme)}</span><a href="${gh(s.readme)}" target="_blank" rel="noopener">GitHub ↗</a></div>${visualizador(s.readme)}</article>` : ''),
    };
  }

  function disciplina(sid, dslug) {
    const s = SEM(sid), d = s?.disciplinas.find(x => x.slug === dslug); if (!d) return null;
    const nos = d.topicos.map(t => `<article class="no">
      <header class="no-cab"><div><span class="nt">&lt;${esc(t.slug)}&gt;</span><h3><a href="${rota('s', s.id, d.slug, t.slug)}">${esc(t.titulo)}</a></h3>${t.resumo ? `<p>${esc(t.resumo)}</p>` : ''}${chips((t.conceitos || []).slice(0, 8))}</div>
        <a class="btn fantasma ir" href="${rota('s', s.id, d.slug, t.slug)}">Estudar →</a></header>
      <ol class="folhas-lista">${t.arquivos.map((a, i) => `<li class="folha"><span class="g">${i === t.arquivos.length - 1 ? '└─' : '├─'}</span>${tipoTag(a.tipo)}
        <span><a href="${rota('f', a.path)}">${esc(nome(a.path))}</a>${a.resumo ? `<span class="r">${esc(a.resumo)}</span>` : ''}</span></li>`).join('')}</ol>
    </article>`).join('');
    return {
      acc: COR[s.id], titulo: curto(d.nome), trilha: [[semNt(s), rota('s', s.id)], [`<${d.slug}>`]],
      html: capa({
        eyebrow: `${semNome(s)}${d.codigo ? ' · ' + d.codigo : ''}`, titulo: d.nome, lead: d.resumo,
        extra: `<p class="meta-linha"><span><b>${d.topicos.length}</b> tópicos</span><span><b>${nArq(d)}</b> folhas</span>${d.linguagens?.length ? `<span>${esc(d.linguagens.join(' · '))}</span>` : ''}</p>${chips(d.conceitos, true)}`,
      }) + `<h2 class="secao" data-nt="&lt;${esc(d.slug)}&gt;">Árvore da disciplina</h2>${nos}`,
    };
  }

  function topico(sid, dslug, tslug) {
    const s = SEM(sid), d = s?.disciplinas.find(x => x.slug === dslug), t = d?.topicos.find(x => x.slug === tslug);
    if (!t) return null;
    const docs = t.arquivos.map((a, i) => {
      const tipo = tipoDe(a.tipo), cab = `<div class="doc-cab"><span class="nome">${tipoTag(a.tipo)} ${esc(nome(a.path))}</span><a href="${rota('f', a.path)}">abrir →</a></div>`;
      if (tipo === 'md') return `<article class="doc" id="doc-${i}">${cab}${visualizador(a.path)}</article>`;
      if (tipo === 'img' || tipo === 'audio' || tipo === 'video') return `<article class="doc" id="doc-${i}">${cab}${visualizador(a.path)}</article>`;
      return `<details class="doc" id="doc-${i}" data-lazy="${esc(a.path)}"><summary>${cab}</summary><div class="corpo-lazy"></div></details>`;
    }).join('');
    return {
      acc: COR[s.id], titulo: t.titulo,
      trilha: [[semNt(s), rota('s', s.id)], [`<${d.slug}>`, rota('s', s.id, d.slug)], [`<${t.slug}>`]],
      html: capa({ eyebrow: `${semNome(s)} · ${curto(d.nome)}`, titulo: t.titulo, lead: t.resumo, extra: chips(t.conceitos, true) })
        + `<div class="layout-topico"><aside><h2>${t.arquivos.length} folhas</h2><ol>${t.arquivos.map((a, i) =>
          `<li><a href="${rota('f', a.path)}" data-alvo="doc-${i}">${esc(nome(a.path))}</a></li>`).join('')}</ol></aside><div>${docs}</div></div>`,
      depois: el => el.querySelectorAll('details[data-lazy]').forEach(det => det.addEventListener('toggle', () => {
        const corpo = det.querySelector('.corpo-lazy');
        if (det.open && !corpo.dataset.ok) { corpo.dataset.ok = 1; corpo.innerHTML = visualizador(det.dataset.lazy); preencher(corpo); }
      })),
    };
  }

  function arquivo(path) {
    const ref = ARQ.get(path);
    if (!ref && !D.semestres.some(s => s.readme === path)) return null;
    const lista = ref?.t.arquivos || [], i = lista.findIndex(a => a.path === path);
    const ant = lista[i - 1], prox = lista[i + 1];
    const tr = ref ? [[semNt(ref.s), rota('s', ref.s.id)], [`<${ref.d.slug}>`, rota('s', ref.s.id, ref.d.slug)], [`<${ref.t.slug}>`, rota('s', ref.s.id, ref.d.slug, ref.t.slug)], [nome(path)]] : [[nome(path)]];
    return {
      acc: COR[ref?.s.id ?? 8], titulo: nome(path), trilha: tr,
      html: capa({
        eyebrow: `${ROTULO[ext(path)] || ext(path) || 'arquivo'}${ref ? ' · ' + ref.t.titulo : ''}`, titulo: nome(path), lead: ref?.a.resumo,
        extra: `<p class="meta-linha"><span>${esc(path)}</span></p><div class="cta"><a class="btn fantasma" href="${gh(path)}" target="_blank" rel="noopener">Ver no GitHub ↗</a><a class="btn fantasma" href="${esc(url(path))}" target="_blank" rel="noopener">Arquivo bruto ↗</a></div>`,
      }) + `<article class="doc" style="margin-top:2rem">${visualizador(path)}</article>
        <nav class="vizinhos" aria-label="Folhas vizinhas">${ant ? `<a href="${rota('f', ant.path)}">← ${esc(nome(ant.path))}</a>` : '<span></span>'}${prox ? `<a href="${rota('f', prox.path)}">${esc(nome(prox.path))} →</a>` : '<span></span>'}</nav>`,
    };
  }

  function naoAchei(h) {
    return {
      acc: COR[1], titulo: 'Derivação impossível',
      html: capa({ eyebrow: 'Erro sintático', titulo: 'Derivação impossível', extra: `<p class="lead">esperado <code>&lt;rota&gt;</code>, encontrado <code>${esc(h)}</code>.</p><div class="cta"><a class="btn" href="#/">Voltar à raiz</a></div>` }),
    };
  }

  /* ---------- roteador ---------- */
  function rotear() {
    const partes = location.hash.replace(/^#\/?/, '').split('/').filter(Boolean).map(p => { try { return decodeURIComponent(p); } catch { return p; } });
    let v = null;
    if (!partes.length) v = home();
    else if (partes[0] === 's') v = partes.length === 2 ? semestre(partes[1]) : partes.length === 3 ? disciplina(partes[1], partes[2]) : partes.length === 4 ? topico(...partes.slice(1)) : null;
    else if (partes[0] === 'f') v = arquivo(partes.slice(1).join('/'));
    v ??= naoAchei(location.hash);

    document.body.style.setProperty('--acc', v.acc);
    document.title = v.titulo ? `${v.titulo} · Faculdade` : 'Faculdade · Árvore de Derivação';
    trilha.innerHTML = v.trilha ? [['<graduacao>', '#/'], ...v.trilha].map(([r, h], i, l) =>
      (i ? '<span class="seta">›</span>' : '') + (h && i < l.length - 1 ? `<a href="${h}">${esc(r)}</a>` : `<span class="atual">${esc(r)}</span>`)).join('') : '';
    app.innerHTML = v.html;
    preencher(app);
    v.depois?.(app);
    window.scrollTo(0, 0);
    app.focus({ preventScroll: true });
  }

  /* ---------- busca ---------- */
  const dlg = document.getElementById('busca'), q = document.getElementById('busca-q'), res = document.getElementById('busca-res');
  let IDX = [], sel = 0;
  function indexar() {
    for (const s of D.semestres) {
      IDX.push({ k: 'semestre', t: semNome(s), s: s.resumo, r: rota('s', s.id), x: norm(`${semNome(s)} ${s.resumo}`) });
      for (const d of s.disciplinas) {
        IDX.push({ k: 'disciplina', t: d.nome, s: `${semNome(s)} · ${(d.conceitos || []).slice(0, 5).join(', ')}`, r: rota('s', s.id, d.slug),
          x: norm([d.nome, d.codigo, d.resumo, ...(d.conceitos || []), ...(d.linguagens || [])].join(' ')) });
        for (const t of d.topicos) {
          IDX.push({ k: 'tópico', t: t.titulo, s: `${semNome(s)} · ${curto(d.nome)}`, r: rota('s', s.id, d.slug, t.slug),
            x: norm([t.titulo, t.resumo, ...(t.conceitos || []), d.nome].join(' ')) });
          for (const a of t.arquivos) {
            ARQ.set(a.path, { s, d, t, a });
            IDX.push({ k: a.tipo || 'arq', t: nome(a.path), s: a.path, r: rota('f', a.path), x: norm(`${a.path} ${a.resumo || ''}`) });
          }
        }
      }
    }
  }
  const ORDEM = { semestre: 0, disciplina: 1, 'tópico': 2 };
  function mostrar() {
    const termos = norm(q.value).split(/\s+/).filter(Boolean);
    sel = 0;
    if (!termos.length) { res.innerHTML = '<li class="dica">Ex.: <b>dijkstra</b>, <b>ponteiros</b>, <b>cst</b>, <b>welch</b>, <b>lexer.py</b></li>'; return; }
    const achados = IDX.filter(e => termos.every(t => e.x.includes(t))).sort((a, b) => (ORDEM[a.k] ?? 3) - (ORDEM[b.k] ?? 3)).slice(0, 60);
    res.innerHTML = achados.length ? achados.map((e, i) => `<li><a href="${e.r}" aria-selected="${i === 0}"><span>${tipoTag(e.k)}</span><span><span class="t">${esc(e.t)}</span><span class="s">${esc(e.s)}</span></span></a></li>`).join('')
      : '<li class="dica">Nada derivou daqui. Tente outro termo.</li>';
  }
  function abrirBusca() { if (!dlg.open) { dlg.showModal(); q.select(); mostrar(); } }
  q.addEventListener('input', mostrar);
  q.addEventListener('keydown', e => {
    const links = [...res.querySelectorAll('a')];
    if (e.key === 'ArrowDown' || e.key === 'ArrowUp') {
      e.preventDefault(); if (!links.length) return;
      sel = (sel + (e.key === 'ArrowDown' ? 1 : -1) + links.length) % links.length;
      links.forEach((l, i) => l.setAttribute('aria-selected', i === sel)); links[sel].scrollIntoView({ block: 'nearest' });
    } else if (e.key === 'Enter') {
      e.preventDefault(); if (links[sel]) { location.hash = links[sel].getAttribute('href'); dlg.close(); }
    }
  });
  res.addEventListener('click', e => { if (e.target.closest('a')) dlg.close(); });
  dlg.addEventListener('click', e => { if (e.target === dlg) dlg.close(); });

  /* ---------- eventos globais ---------- */
  document.addEventListener('keydown', e => {
    if (e.key === '/' && !/^(INPUT|TEXTAREA)$/.test(document.activeElement?.tagName)) { e.preventDefault(); abrirBusca(); }
  });
  document.addEventListener('click', e => {
    if (e.target.closest('[data-busca]')) { abrirBusca(); return; }
    const alvo = e.target.closest('a[data-alvo]');
    if (alvo && !e.ctrlKey && !e.metaKey) {
      e.preventDefault();
      const doc = document.getElementById(alvo.dataset.alvo);
      if (doc?.tagName === 'DETAILS') doc.open = true;
      doc?.scrollIntoView({ behavior: 'smooth', block: 'start' });
      return;
    }
    const anc = e.target.closest('a[data-ancora]');
    if (anc) {
      e.preventDefault();
      document.getElementById('h-' + slug(decodeURIComponent(anc.dataset.ancora)))?.scrollIntoView({ behavior: 'smooth', block: 'start' });
    }
  });
  document.getElementById('tema').addEventListener('click', () => {
    const novo = escuro() ? 'light' : 'dark';
    document.documentElement.dataset.theme = novo;
    try { localStorage.setItem('tema', novo); } catch { /* sem armazenamento: vale só nesta visita */ }
  });

  /* ---------- início ---------- */
  hljs.configure({ ignoreUnescapedHTML: true });
  fetch('site/dados.json', { cache: 'no-cache' })
    .then(r => { if (!r.ok) throw new Error('HTTP ' + r.status); return r.json(); })
    .then(dados => {
      D = dados;
      indexar();
      rodape.innerHTML = `<span>&lt;graduacao&gt; · ${D.totais.arquivos} folhas · atualizado em ${esc(D.gerado_em)}</span>
        <span>Conteúdo real do <a href="https://github.com/${REPO}" target="_blank" rel="noopener">repositório no GitHub ↗</a></span>`;
      addEventListener('hashchange', rotear);
      rotear();
    })
    .catch(e => { app.innerHTML = `<p class="erro">Não consegui carregar o mapa do repositório (${esc(e.message)}).</p>`; });
})();
