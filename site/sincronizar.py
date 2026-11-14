"""Mantém site/dados.json em sincronia com os arquivos do repositório.

Uso (da raiz do repo):
    python site/sincronizar.py                      # sincroniza dados.json com o disco
    python site/sincronizar.py --semente inv.json   # recria dados.json a partir de um inventário

O que faz:
  1. remove do JSON arquivos que não existem mais;
  2. coloca cada arquivo novo no tópico cujos arquivos têm a pasta mais parecida
     (maior prefixo de caminho em comum); sem parentesco, vai para "Extras · Outros arquivos";
  3. recalcula slugs e totais.
Resumos, conceitos e destaques escritos à mão são preservados.
"""
import json, os, re, sys, unicodedata
from datetime import date

RAIZ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DADOS = os.path.join(RAIZ, 'site', 'dados.json')

# o site mostra conteúdo de estudo; spec de agente, build e binário ficam de fora
IGNORAR_DIR = {'.git', 'site', '.vscode', '.settings', 'bin', 'output', 'node_modules', '.planning'}
IGNORAR_NOME = {'CLAUDE.md', 'index.html', '.nojekyll', '.gitignore', '.gitattributes', '.classpath', '.project'}
IGNORAR_EXT = {'.class', '.exe', '.prefs', '.o', '.pyc'}

DESTAQUES = [  # usados só com --semente; depois vivem no dados.json
    {"titulo": "Transpilador MineonScript → Python", "sem": "8", "disc": "Compiladores",
     "texto": "Uma linguagem criada em aula e o tradutor inteiro: BNF, lexer com regex, parser por descida recursiva, AST, gerador de código e CST sem perdas.",
     "tags": ["Python", "BNF", "AST", "CST"]},
    {"titulo": "Análise espectral de áudio", "sem": "8", "disc": "Processamento de Sinais Multimídia",
     "texto": "Espectrograma via STFT, chirp, frequência média e mediana (MNF/MDF) e estimadores de Bartlett e Welch, com relatório e código.",
     "tags": ["MATLAB", "STFT", "Welch"]},
    {"titulo": "Grafos de verdade", "sem": "6", "disc": "Teoria dos Grafos",
     "texto": "Lista e matriz de adjacência, isomorfismo, coloração, Dijkstra, Bellman-Ford e Kruskal, com atividades semanais em networkx.",
     "tags": ["Python", "networkx", "Dijkstra"]},
    {"titulo": "Programação dinâmica e complexidade", "sem": "5", "disc": "Análise de Dados e Algoritmos Avançados",
     "texto": "Mochila 0/1, LCS, Fibonacci com memória, ordenação, busca binária e análise de custo em Big-O.",
     "tags": ["Python", "C", "Big-O"]},
    {"titulo": "Sistemas orientados a objetos", "sem": "4", "disc": "Programação Orientada a Objetos",
     "texto": "Herança, polimorfismo, interfaces, exceções e UML aplicados em projetos de hotel, clínica veterinária e e-commerce.",
     "tags": ["Java", "UML", "MVC"]},
    {"titulo": "Estruturas de dados na unha", "sem": "3", "disc": "Estrutura de Dados",
     "texto": "Pilha, fila, listas ligadas, árvores binárias e AVL e os algoritmos clássicos de ordenação, mais desafios do BeeCrowd.",
     "tags": ["C", "C++", "AVL"]},
    {"titulo": "Computação gráfica em MATLAB", "sem": "3", "disc": "Computação Gráfica",
     "texto": "Rasterização de segmentos, espectro de cores, processamento de imagem e gráficos 2D e 3D.",
     "tags": ["MATLAB", "Rasterização"]},
    {"titulo": "Maratona Fraldinha 2023", "sem": "extras", "disc": "Maratona Fraldinha 2023",
     "texto": "14 problemas de maratona de programação resolvidos em Python, cada um com o enunciado.",
     "tags": ["Python", "Maratona"]},
]


def slug(texto, limite=48):
    s = unicodedata.normalize('NFKD', texto).encode('ascii', 'ignore').decode().lower()
    s = re.sub(r'[^a-z0-9]+', '-', s).strip('-')
    return s[:limite].rstrip('-') or 'x'


def ignorado(rel):
    partes = rel.split('/')
    nome = partes[-1]
    return (any(p in IGNORAR_DIR for p in partes[:-1]) or nome in IGNORAR_NOME
            or os.path.splitext(nome)[1].lower() in IGNORAR_EXT
            or '.' not in nome)  # sem extensão = executável compilado


def arquivos_do_disco():
    achados = set()
    for pasta, dirs, nomes in os.walk(RAIZ):
        dirs[:] = [d for d in dirs if d not in IGNORAR_DIR]
        for n in nomes:
            rel = os.path.relpath(os.path.join(pasta, n), RAIZ).replace(os.sep, '/')
            # soltos na raiz e o README-placeholder de cada semestre não entram
            if rel.count('/') >= 1 and not ignorado(rel) and not re.fullmatch(r'[^/]*Semestre/README\.md', rel):
                achados.add(rel)
    return achados


def tipo(path):
    ext = os.path.splitext(path)[1].lower().lstrip('.')
    return ext or 'outro'


def prefixo_comum(a, b):
    n = 0
    for x, y in zip(a.split('/')[:-1], b.split('/')[:-1]):
        if x != y:
            break
        n += 1
    return n


def de_semente(inv):
    sems = inv['semestres'] + [{"id": "extras", "titulo": "Extras", "status": "concluido",
                                "resumo": "Maratona de programação e materiais fora das disciplinas.",
                                "disciplinas": [d for d in inv.get('extras', []) if d['nome'] != 'Documentos gerais']}]
    destaques = DESTAQUES
    return {"repo": "G2Martins/Faculdade", "branch": "main", "semestres": sems, "destaques": destaques}


def main():
    if '--semente' in sys.argv:
        dados = de_semente(json.load(open(sys.argv[sys.argv.index('--semente') + 1], encoding='utf-8')))
    else:
        dados = json.load(open(DADOS, encoding='utf-8'))

    disco = arquivos_do_disco()
    vistos, topicos = set(), []
    for s in dados['semestres']:
        s['id'] = str(s['id'])
        for d in s['disciplinas']:
            d['slug'] = slug(re.split(r'\s[—(]', d['nome'])[0])
            usados = set()
            for t in d['topicos']:
                base = slug(t['titulo'])
                t['slug'] = base if base not in usados else f'{base}-{len(usados)}'
                usados.add(t['slug'])
                t['arquivos'] = [a for a in t['arquivos'] if a['path'] in disco and a['path'] not in vistos]
                for a in t['arquivos']:
                    a['tipo'] = tipo(a['path'])
                    vistos.add(a['path'])
                topicos.append(t)

    # pasta-raiz de cada disciplina = maior pasta em comum entre os arquivos dela
    raizes = []
    for s in dados['semestres']:
        for d in s['disciplinas']:
            ps = [a['path'].split('/')[:-1] for t in d['topicos'] for a in t['arquivos']]
            if ps:
                k = 0
                while all(len(x) > k for x in ps) and len({x[k] for x in ps}) == 1:
                    k += 1
                raizes.append((ps[0][:k], d))

    novos = sorted(disco - vistos)
    sobra = []
    for p in novos:
        item = {"path": p, "tipo": tipo(p), "resumo": ""}
        pastas = p.split('/')[:-1]
        cands = [(r, d) for r, d in raizes if r and pastas[:len(r)] == r]
        if not cands:
            sobra.append(item)
            continue
        raiz, d = max(cands, key=lambda c: len(c[0]))
        melhor, nota = None, len(raiz)
        for t in d['topicos']:  # tópico que já tem arquivo na mesma subpasta
            for a in t['arquivos']:
                n = prefixo_comum(p, a['path'])
                if n > nota:
                    melhor, nota = t, n
        if not melhor:  # pasta nova dentro da disciplina vira tópico novo
            titulo = pastas[len(raiz)] if len(pastas) > len(raiz) else 'Arquivos gerais'
            melhor = next((t for t in d['topicos'] if t['titulo'] == titulo), None)
            if not melhor:
                melhor = {"titulo": titulo, "slug": slug(titulo), "resumo": "", "conceitos": [], "arquivos": []}
                d['topicos'].append(melhor)
                topicos.append(melhor)
        melhor['arquivos'].append(item)
    if sobra:
        ext = next(s for s in dados['semestres'] if s['id'] == 'extras')
        outros = next((d for d in ext['disciplinas'] if d['nome'] == 'Outros arquivos'), None)
        if not outros:
            outros = {"nome": "Outros arquivos", "slug": "outros-arquivos", "linguagens": [], "conceitos": [],
                      "resumo": "Arquivos que ainda não foram encaixados numa disciplina.", "topicos": []}
            ext['disciplinas'].append(outros)
        if not outros['topicos']:
            outros['topicos'].append({"titulo": "Sem classificação", "slug": "sem-classificacao",
                                      "resumo": "", "conceitos": [], "arquivos": []})
        outros['topicos'][0]['arquivos'] += sobra

    for s in dados['semestres']:  # tópico que perdeu todos os arquivos sai do site
        for d in s['disciplinas']:
            d['topicos'] = [t for t in d['topicos'] if t['arquivos']]
        s['disciplinas'] = [d for d in s['disciplinas'] if d['topicos'] or s['id'] != 'extras']

    for t in topicos:
        t['arquivos'].sort(key=lambda a: (a['tipo'] != 'md', a['path'].lower()))

    # README do semestre = apresentação do mini-site do semestre (placeholder "em desenvolvimento" não entra)
    for s in dados['semestres']:
        s.pop('readme', None)
        p = f"{s['id']}° Semestre/README.md"
        if os.path.isfile(os.path.join(RAIZ, p)) and 'Conteúdo em desenvolvimento' not in open(os.path.join(RAIZ, p), encoding='utf-8').read():
            s['readme'] = p

    tot = lambda f: sum(f(d) for s in dados['semestres'] for d in s['disciplinas'])
    dados['totais'] = {
        "semestres": sum(1 for s in dados['semestres'] if s['id'] != 'extras'),
        "disciplinas": tot(lambda d: 1),
        "topicos": tot(lambda d: len(d['topicos'])),
        "arquivos": tot(lambda d: sum(len(t['arquivos']) for t in d['topicos'])),
    }
    dados['gerado_em'] = date.today().isoformat()
    json.dump(dados, open(DADOS, 'w', encoding='utf-8'), ensure_ascii=False, indent=1)
    print(f"ok · {dados['totais']} · {len(novos)} novo(s), {len(sobra)} sem tópico")


if __name__ == '__main__':
    main()
