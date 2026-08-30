# CLAUDE.md — PSM (Processamento de Sinais Multimídia)

> **Spec viva.** Porta-de-entrada lida pelo agente toda sessão. Não duplica os PDFs da disciplina — **aponta** pra eles. Atualize a cada atividade nova, mudança de convenção ou armadilha descoberta.
>
> **Última revisão:** 2026-08-21
> **Fonte única de regras acadêmicas:** [Docs/Plano de Ensino.pdf](Docs/Plano%20de%20Ensino.pdf) · **Enunciados/resoluções:** [Docs/](Docs/) · **Código:** [Codigos/](Codigos/)

---

## 1. O que é

Repositório das atividades da disciplina **Processamento de Sinais Multimídia** (ENG149, turma ENGNM4B, 9º período, Eng. da Computação — IESB). Professor: **Thiago Raposo Milhomem de Carvalho**. Currículo 2026/2. Pré-requisito ENG131 (PDS).

Entregável de cada atividade = **relatório PDF** + **código `.m`**. Ferramenta: **MATLAB** (ou Octave). Envio via Google Classroom.

## 2. Estrutura + convenções

```
PSM/
├── CLAUDE.md            # este arquivo (spec viva)
├── Docs/                # PDFs: plano de ensino, slides, enunciados, resoluções
└── Codigos/             # fontes .m — um script por atividade + funções reusáveis
```

- **Uma função por arquivo `.m`**, nome do arquivo = nome da função (exigência do MATLAB).
- Scripts de atividade: `atividade_<DD>ago.m` — rodam do começo ao fim, sem input manual.
- Funções reusáveis ficam soltas em `Codigos/` e são **reaproveitadas entre atividades** (o professor pede explicitamente que a atividade nova use o algoritmo da anterior).
- Comentários e identificadores **sem acento** (compatibilidade de encoding do MATLAB no Windows).
- Toda figura gerada com `xlabel`/`ylabel`/`title` preenchidos — o relatório depende delas.

## 3. Mapa de atividades

| Data | Tema | Enunciado | Código | Status |
|---|---|---|---|---|
| 13-ago | **Atividade Lab. n. 01** — espectrograma via STFT; nota de piano + sinal de voz; frequência de pico por janela | [Enunciado 13/ago](Docs/) | [`meu_espectrograma.m`](Codigos/meu_espectrograma.m), `freq_para_nota.m` | ✅ entregue ([Resolução](Docs/)) |
| 20-ago | **Exercício** — chirp linear `ω(t)=(ω_s/2)t`, fs=8 kHz, 2 s; obter espectrograma e explicá-lo | [Enunciado 20/ago](Docs/) | [`atividade_20ago.m`](Codigos/atividade_20ago.m) | ✅ código pronto |
| 27-ago | Unidade 1 (a definir) | — | — | ⏳ |

## 4. Regras SEMPRE-ATIVAS

- **Reusar antes de reescrever.** O enunciado de 20/ago diz "utilize *seu* algoritmo de espectrograma": `atividade_20ago.m` chama `meu_espectrograma.m` sem alterá-lo. Mudança na função = re-verificar a atividade anterior.
- **Fase é a integral da frequência.** `x(t) = sin(θ(t))` com `dθ/dt = ω(t)`. Escrever `sin(ω(t)·t)` é o erro clássico → dobra a frequência instantânea. Sempre integrar analiticamente e comentar a integração no código.
- **Verificar contra a teoria.** Todo resultado numérico é conferido contra a expressão fechada (ex.: `f_pico` medida × `f_i(t)` teórica no mesmo gráfico). Figura sem referência teórica não fecha a atividade.
- **Nyquist é premissa, não detalhe.** Qualquer sinal sintetizado tem sua frequência instantânea comparada com `fs/2` antes de interpretar o espectrograma (ver §5).
- **Relatório > código.** Peso da avaliação está nos **comentários e na interpretação**, não no algoritmo (o enunciado desconsidera relatório só com figuras/código). Cada figura entregue vem com parágrafo explicando o que se observa e por quê.
- **Caveman full sempre** — respostas comprimidas. Código, textos do relatório e comentários = escrita normal, pt-BR.
- **Sem co-author em commits** — nunca adicionar `Co-Authored-By: Claude…`.

## 5. Common Hurdles (armadilhas conhecidas)

- **O espectrograma de 20/ago é um "Λ", não uma rampa — e isso está CERTO.** `f_i(t) = (fs/2)·t` chega a **8000 Hz = fs** em t=2 s, cruzando Nyquist (**4000 Hz**) em **t = 1 s**. Depois disso o sinal amostrado é **aliasado**: a frequência observada rebate como `fs − f_i(t)`, caindo de 4000 Hz de volta a 0 Hz. Não "consertar" — é exatamente o fenômeno que o exercício demonstra. Verificado numericamente: pico medido bate na teoria até t≈0,99 s (máx. ≈3967 Hz) e desce simetricamente depois.
- **`f_pico` só varre até `fs/2`.** `meu_espectrograma` devolve `X` com `N/2` linhas — por construção nunca reporta acima de Nyquist. É consistente com o item acima, não é bug.
- **Janela sem sobreposição.** A segmentação é `floor(L/N)` trechos justapostos (hop = N). Amostras do rabo do sinal que não completam um trecho são **descartadas** — com fs=8k, 2 s e janela de 30 ms, sobra resíduo. Se precisar de resolução temporal melhor, mudar o hop implica revisar `eixo_tempo`.
- **`duracao_trecho` em ms exige o 4º argumento.** `meu_espectrograma(x, 30, fs)` interpreta 30 **amostras**; o correto é `meu_espectrograma(x, 30, fs, true)`.
- **`N` é forçado a par** dentro da função (`N = N-1` se ímpar). Com fs "quebrado" o N efetivo pode não ser o esperado — conferir `size(X,1)*2` antes de montar o eixo de frequência.
- **`20*log10(X + eps)`** — o `eps` evita `-Inf` em bins nulos. Sem ele o `imagesc` estoura a escala de cor.
- **Octave vs MATLAB:** `yline` não existe em Octave antigo; substituir por `plot([t0 t1],[fs/2 fs/2],':k')` se rodar em Octave.

## 6. Antes de fechar qualquer atividade

- [ ] Script roda limpo do zero (`clear; close all; clc`) sem input manual
- [ ] Reusa a função da atividade anterior, sem modificá-la
- [ ] Resultado numérico conferido contra a expressão teórica
- [ ] Figuras com eixos rotulados + título + colorbar quando aplicável
- [ ] Relatório com: introdução · procedimento · resultados comentados · conclusão · códigos no final (itens i–v do enunciado)
- [ ] Nome/matrícula de todos os integrantes no relatório
- [ ] Esta tabela (§3) e os Hurdles (§5) atualizados

## 7. Índice de navegação

- **Plano de ensino / avaliação / cronograma** → `Docs/Plano de Ensino.pdf`
- **Teoria da STFT (slides 20/08)** → `Docs/Aula dia 20.08.pdf`
- **Enunciados** → `Docs/Enunciado Atividade *.pdf`
- **Resoluções entregues** → `Docs/Resolução Atividade *.pdf`
- **Códigos** → `Codigos/`
