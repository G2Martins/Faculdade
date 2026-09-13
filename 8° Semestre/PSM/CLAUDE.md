# CLAUDE.md — PSM (Processamento de Sinais Multimídia)

> **Spec viva.** Porta-de-entrada lida pelo agente toda sessão. Não duplica os PDFs da disciplina — **aponta** pra eles. Atualize a cada atividade nova, mudança de convenção ou armadilha descoberta.
>
> **Última revisão:** 2026-08-30
> **Fonte única de regras acadêmicas:** [Docs Gerais/Plano de Ensino.pdf](Docs%20Gerais/Plano%20de%20Ensino.pdf) · **Enunciados/resoluções/códigos:** uma pasta por atividade (§2)

---

## 1. O que é

Repositório das atividades da disciplina **Processamento de Sinais Multimídia** (ENG149, turma ENGNM4B, 9º período, Eng. da Computação — IESB). Professor: **Thiago Raposo Milhomem de Carvalho**. Currículo 2026/2. Pré-requisito ENG131 (PDS).

Entregável de cada atividade = **relatório PDF** + **código `.m`**. Ferramenta: **MATLAB** (ou Octave). Envio via Google Classroom.

## 2. Estrutura + convenções

```
PSM/
├── CLAUDE.md                  # este arquivo (spec viva)
├── Docs Gerais/               # plano de ensino + slides das aulas
├── Atividade 13 Ago 26/       # Lab n. 01 — enunciado, resolução, códigos
├── Atividade 20 Ago 26/       # exercício do chirp
├── Atividade 27 Ago 26/       # exercício teórico (MNF/MDF analítico)
└── Atividade 03 Set 26/       # Lab n. 02 parte 2 — Bartlett/Welch
```

- **Uma pasta por atividade**, nomeada `Atividade <DD> <Mes> <AA>`. Dentro dela ficam o enunciado, a resolução e os `.m` daquela atividade — tudo que é preciso pra revisar a atividade sem abrir outra pasta.
- **Nomes de arquivo sem acento e sem espaço duplo.** Os PDFs originais do professor vinham com dois espaços antes do hífen (`Atividade 03_set  - ...`); foram renomeados no padrão `Enunciado - <descrição> (<DD> <mes>).pdf` e `Resolucao - <descrição> (<DD> <mes>).pdf`.
- **Uma função por arquivo `.m`**, nome do arquivo = nome da função (exigência do MATLAB).
- **Funções reusáveis moram na pasta da atividade que as criou.** `meu_espectrograma.m` e `freq_para_nota.m` nasceram no Lab n. 01 e continuam em `Atividade 13 Ago 26/`. Scripts de atividades posteriores as alcançam com `addpath` relativo (ver §5) — não duplicar o arquivo.
- Scripts de atividade rodam do começo ao fim, sem input manual (`clear; close all; clc`), e começam com o `addpath` relativo das funções de que dependem — sem isso o MATLAB não acha `meu_espectrograma.m`, que mora na pasta da Atividade 13 Ago 26.
- Comentários e identificadores **sem acento** (compatibilidade de encoding do MATLAB no Windows).
- Toda figura gerada com `xlabel`/`ylabel`/`title` preenchidos — o relatório depende delas.
- Relatório entregue em **`.md` (versionado, com LaTeX que o GitHub renderiza) + `.docx`** (para importar no Google Docs e exportar o PDF do Classroom).

## 3. Mapa de atividades

| Data | Tema | Pasta | Códigos | Status |
|---|---|---|---|---|
| 13-ago | **Atividade Lab. n. 01** — espectrograma via STFT; nota de piano + sinal de voz; frequência de pico por janela | [Atividade 13 Ago 26](Atividade%2013%20Ago%2026) | `meu_espectrograma.m`, `freq_para_nota.m` | ✅ entregue |
| 20-ago | **Exercício** — chirp linear `ω(t)=(ω_s/2)t`, fs=8 kHz, 2 s; obter espectrograma e explicá-lo | [Atividade 20 Ago 26](Atividade%2020%20Ago%2026) | `atividade_20ago.m` | ✅ entregue |
| 27-ago | **Exercício teórico** — (i) qual espectrograma usa a janela mais longa; (ii) MNF e MDF analíticas de `x(t) = (1/πt)(sen5πt − sen4πt)` | [Atividade 27 Ago 26](Atividade%2027%20Ago%2026) | — (sem código) | ⚠️ **sem resolução** |
| 03-set | **Atividade Lab. n. 02, Parte 2** — Bartlett e Welch; MNF e MDF sobre as estimativas x sinal completo; erro percentual | [Atividade 03 Set 26](Atividade%2003%20Set%2026) | `espectro_medio.m`, `mnf_mdf.m`, `atividade_03set.m` | 🔄 código pronto · relatório com lacunas |

**Pendências conhecidas:**

- O **Lab n. 01 (13/ago) não tem script principal** no repo — só as duas funções. O script que gerou as figuras e a lista de notas do relatório nunca foi commitado. Não dá para reproduzir aquela atividade rodando o que está aqui.
- A **27/ago não tem resolução** — o enunciado é teórico (duas questões dissertativas) e nada foi escrito ainda.
- A **03/set precisa dos áudios da Parte 1** (`notas_musicais.wav` e `voz.wav`) na pasta da atividade. Sem eles o script roda só o Sinal 1 (ruído sintético) e as tabelas do relatório ficam vazias para os Sinais 2 e 3.
- A pasta vazia `Codigos/` sobrou da estrutura antiga e precisa ser apagada à mão (o agente não tem permissão de deleção). Como o git não versiona pasta vazia, ela não aparece em commit.

## 4. Regras SEMPRE-ATIVAS

- **Reusar antes de reescrever.** O professor pede explicitamente que a atividade nova use o algoritmo da anterior. `atividade_20ago.m` chama `meu_espectrograma.m` sem alterá-lo; `atividade_03set.m` o chama para calcular a variante "Bartlett direto da STFT". Mudança na função = re-verificar as atividades anteriores.
- **Generalizar, não bifurcar.** Quando o enunciado pede uma variação do algoritmo (sobreposição, outra janela), escrever **uma** função com parâmetros que reduza ao comportamento antigo nos valores padrão — foi o que `espectro_medio.m` fez com Bartlett e Welch. Duas funções quase iguais divergem na primeira correção.
- **Fase é a integral da frequência.** `x(t) = sin(θ(t))` com `dθ/dt = ω(t)`. Escrever `sin(ω(t)·t)` é o erro clássico → dobra a frequência instantânea. Sempre integrar analiticamente e comentar a integração no código.
- **Todo experimento leva um caso de controle com resposta conhecida.** Na 03/set é o ruído filtrado em banda plana, cuja MNF e MDF teóricas são o centro da banda: valida a implementação antes de aplicá-la a sinais reais, onde um erro produziria números plausíveis e silenciosamente errados.
- **Verificar contra a teoria.** Todo resultado numérico é conferido contra a expressão fechada (ex.: `f_pico` medida × `f_i(t)` teórica no mesmo gráfico). Figura sem referência teórica não fecha a atividade.
- **Nyquist é premissa, não detalhe.** Qualquer sinal sintetizado tem sua frequência instantânea comparada com `fs/2` antes de interpretar o espectrograma (ver §5).
- **Relatório > código.** Peso da avaliação está nos **comentários e na interpretação**, não no algoritmo (o enunciado desconsidera relatório só com figuras/código). Cada figura entregue vem com parágrafo explicando o que se observa e por quê.
- **Caveman full sempre** — respostas comprimidas. Código, textos do relatório e comentários = escrita normal, pt-BR.
- **Sem co-author em commits** — nunca adicionar `Co-Authored-By: Claude…`.
- **Nunca commitar nem dar push sem pedido explícito.**

## 5. Common Hurdles (armadilhas conhecidas)

### Estrutura e caminhos

- **`addpath` é relativo ao diretório de trabalho, não ao arquivo.** `atividade_03set.m` faz `addpath(fullfile('..','Atividade 13 Ago 26'))` para achar `meu_espectrograma.m`. Isso só funciona se o MATLAB estiver **com a pasta da atividade como Current Folder**. Rodando de outro lugar, o `addpath` aponta para o vazio e o erro que aparece é `Undefined function 'meu_espectrograma'` — que parece arquivo faltando, mas é caminho errado.
- **Nomes de pasta têm `°` e espaço** (`8° Semestre`). Todo comando de shell precisa do caminho **entre aspas duplas**. `git config core.quotepath false` resolve a exibição dos escapes octais no `git log`.

### Atividade 03/set — Bartlett, Welch, MNF e MDF

- **`k_MDF` quase nunca é inteiro.** Arredondar para a raia mais próxima introduz erro de até meia raia — com `N=256` e `fs=8k`, isso é ±15,6 Hz, da mesma ordem dos erros que se quer medir. `mnf_mdf.m` **interpola linearmente** a soma acumulada entre as duas raias que cercam a metade da potência.
- **`N_dft` errado = número plausível e errado.** As estimativas usam `N` (tamanho do trecho) e o sinal completo usa `L` (comprimento do sinal) para converter índice em Hertz. Passar o valor errado não gera erro nenhum: gera um resultado com aparência normal. É por isso que `mnf_mdf` recebe `N_dft` explícito em vez de deduzi-lo de `length(P)`.
- **Promediar a STFT da Parte 1 NÃO dá Bartlett estrito.** `meu_espectrograma.m` aplica janela de **Hamming** internamente; Bartlett usa janela retangular. A média das colunas de `|X|²` da Parte 1 é, a rigor, um **Welch sem sobreposição**, e cai entre o Bartlett estrito e o Welch completo. O script calcula as duas variantes separadamente e o relatório registra a diferença — não "consertar" achando que é bug.
- **A normalização `U = sum(w.^2)` não muda MNF nem MDF.** É fator constante, aparece no numerador e no denominador das duas definições. Serve só para pôr Bartlett e Welch na mesma escala num gráfico comum. Removê-la não altera número nenhum das tabelas.
- **Espera-se MNF > MDF em sinais reais de áudio.** O espectro tem cauda à direita (harmônicos, fricativas), e a média ponderada é puxada por ela enquanto a mediana não é. MNF ≈ MDF só no ruído de banda plana. Se der o contrário num sinal de áudio, suspeitar da implementação.
- **A MDF costuma ter o maior erro percentual** entre as duas medidas nas estimativas. Não contradiz a robustez dela a ruído: robustez a ruído espectral e sensibilidade à resolução em frequência são propriedades distintas, e a MDF, definida por cruzamento de limiar, sofre mais com a redução do número de raias.

### Atividades anteriores

- **O espectrograma de 20/ago é um "Λ", não uma rampa — e isso está CERTO.** `f_i(t) = (fs/2)·t` chega a **8000 Hz = fs** em t=2 s, cruzando Nyquist (**4000 Hz**) em **t = 1 s**. Depois disso o sinal amostrado é **aliasado**: a frequência observada rebate como `fs − f_i(t)`, caindo de 4000 Hz de volta a 0 Hz. Não "consertar" — é exatamente o fenômeno que o exercício demonstra.
- **`f_pico` só varre até `fs/2`.** `meu_espectrograma` devolve `X` com `N/2` linhas — por construção nunca reporta acima de Nyquist. É consistente com o item acima, não é bug.
- **Janela sem sobreposição em `meu_espectrograma`.** A segmentação é `floor(L/N)` trechos justapostos (hop = N). Amostras do rabo do sinal que não completam um trecho são **descartadas**. Quem precisa de sobreposição usa `espectro_medio.m`.
- **`duracao_trecho` em ms exige o 4º argumento.** `meu_espectrograma(x, 30, fs)` interpreta 30 **amostras**; o correto é `meu_espectrograma(x, 30, fs, true)`.
- **`N` é forçado a par** dentro das funções (`N = N-1` se ímpar). Com fs "quebrado" o N efetivo pode não ser o esperado — conferir `size(X,1)*2` antes de montar o eixo de frequência.
- **`20*log10(X + eps)`** — o `eps` evita `-Inf` em bins nulos. Sem ele o `imagesc` estoura a escala de cor.
- **⚠️ Divergência aberta na resolução de 13/ago.** O PDF entregue lista `Do4 (433.7 Hz)` e `Sol5 (1301.0 Hz)`, mas o `freq_para_nota.m` que está no repo devolve **La4** para 433,7 Hz e **Mi6** para 1301 Hz — e a própria conclusão do relatório fala em "La4, ~433,7 Hz". Ou o PDF saiu de uma versão antiga da função, ou a lista foi editada à mão. Conferir antes de usar aqueles números como referência.

### Compatibilidade

- **Octave vs MATLAB:** `yline` não existe em Octave antigo; substituir por `plot([t0 t1],[fs/2 fs/2],':k')`. `rng(42)` também é do MATLAB — em Octave usar `rand('seed',42)`.
- **Sem Signal Processing Toolbox:** `espectro_medio.m` gera Hamming e Hann pela fórmula fechada justamente para não depender de `hamming()`/`hann()`. `meu_espectrograma.m`, da Parte 1, **ainda usa `hamming()`** e mantém a dependência.

## 6. Antes de fechar qualquer atividade

- [ ] Arquivos na pasta da atividade, no padrão de nome da §2
- [ ] Script roda limpo do zero (`clear; close all; clc`) sem input manual
- [ ] Reusa a função da atividade anterior, sem modificá-la
- [ ] Resultado numérico conferido contra a expressão teórica (ou contra o caso de controle)
- [ ] Figuras com eixos rotulados + título + colorbar quando aplicável
- [ ] Relatório com: introdução · procedimento · resultados comentados · conclusão · códigos no final (itens i–v do enunciado)
- [ ] Nome/matrícula de todos os integrantes no relatório
- [ ] Tabela (§3), pendências e Hurdles (§5) atualizados
- [ ] Sem commit/push sem pedido explícito · sem trailer de co-author

## 7. Índice de navegação

- **Plano de ensino / avaliação / cronograma** → [Docs Gerais/Plano de Ensino.pdf](Docs%20Gerais/Plano%20de%20Ensino.pdf)
- **Teoria da STFT** → [Docs Gerais/Aula dia 20.08.pdf](Docs%20Gerais/Aula%20dia%2020.08.pdf)
- **Bartlett, Welch, MNF e MDF** → [Docs Gerais/Aula dia 27.08.pdf](Docs%20Gerais/Aula%20dia%2027.08.pdf) (slides 102–115)
- **Atividade ativa** → [Atividade 03 Set 26](Atividade%2003%20Set%2026)
- **Regras globais do repositório** → [../../CLAUDE.md](../../CLAUDE.md)
