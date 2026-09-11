# CLAUDE.md — Sistemas Lineares (8° Semestre · ENG029)

> **Spec viva.** Contexto da disciplina lido pelo agente em toda sessão. Não duplica os PDFs — **aponta** pra eles. Atualizar no mesmo commit que adiciona aula, lista, atividade prática ou armadilha descoberta.
>
> **Última revisão:** 2026-09-08
> **Regras do repositório inteiro:** [../../CLAUDE.md](../../CLAUDE.md) · **Fonte única de regras acadêmicas:** [Docs/Plano de Ensino Completo - Sistemas Lineares - 2026-2 - Ter-19h15 - ENG029-ENGNM3B.pdf](Docs/Plano%20de%20Ensino%20Completo%20-%20Sistemas%20Lineares%20-%202026-2%20-%20Ter-19h15%20-%20ENG029-ENGNM3B.pdf) · **Anotações de aula:** [Docs/Resumo P1.pdf](Docs/Resumo%20P1.pdf)

---

## 0. Para que serve

Passar em Sistemas Lineares com nota e sair sabendo **modelar um sistema LTI e resolvê-lo nos três domínios** (tempo, Laplace, frequência) — que é exatamente o que a prova cobra e o que a disciplina inteira gira em torno.

**Placar:** anotações da Unidade 1 + Unidade 2 consolidadas (9 páginas) · 2 simulados de P1 com gabarito · **P1 em 15/09/2026** (próxima aula) · 0 atividades práticas registradas.

## 1. O que é

- **Curso:** Engenharia da Computação / Engenharia Elétrica (IESB) · **Ano/Semestre:** 2026/2
- **Disciplina:** Sistemas Lineares — **ENG029** · **Turma:** ENGNM3B · **Período no currículo:** 6º
- **CH:** 60h (45h teórica + 15h prática) · **Horário:** terça, 19h15
- **Pré-requisito:** ENG024 (Análise de Sinais)
- **Professor:** Thiago Raposo Milhomem de Carvalho — **o mesmo de PSM** (ver [../PSM/CLAUDE.md](../PSM/CLAUDE.md); estilo de avaliação e ferramenta prática são idênticos)
- **Material:** Google Classroom · **Ferramenta prática:** MATLAB ou Octave

**Ementa / Unidades:**

1. **Unidade 1** — Análise e modelagem de sistemas lineares, Parte 1: classificação de sinais e sistemas, impulso e resposta ao impulso, autofunções, função de transferência, resposta em frequência, impedâncias em Laplace, estabilidade, filtros analógicos passivos e ativos.
2. **Unidade 2** — Parte 2: relação h(t) ↔ H(s), transformada de Laplace (uni e bilateral) e propriedades, modelagem por EDOs (equação característica, resposta homogênea/particular/forçada/geral), polos × resposta natural, transformada de sinais periódicos, teoremas do valor inicial e final, diagramas de blocos, espaço de estados contínuo.
3. **Unidade 3** — Sinais e sistemas de **tempo discreto**: propriedades, resposta ao impulso, equações de diferenças, diagramas de blocos, solução homogênea, autofunções.
4. **Unidade 4** — Análise de sistemas discretos: **transformada Z**, propriedades e inversão, funções de transferência discretas, h[n] via Z, diagramas de bloco, espaço de estados discreto.

**P1 = Unidades 1 e 2** (contínuo/Laplace). **P2 = Unidades 3 e 4** (discreto/Z). **P3 = tudo.**

## 2. Como roda (avaliação e calendário)

```
A1 = 0,8*P1 + 0,2*TE1
A2 = 0,8*P2 + 0,2*TE2
MF = 0,4*A1 + 0,6*A2          → aprovado se MF ≥ 5,0 e frequência ≥ 75%

P3 (substitutiva, se MF < 5,0):
MF = máximo{ 0,4*P3 + 0,6*A2 ; 0,4*A1 + 0,6*P3 }
```

- **P1/P2:** individuais, escritas, **sem consulta**.
- **TE1/TE2:** média das demais atividades do bimestre. Composição: **50% síncronas + 50% assíncronas**, média aritmética simples dentro de cada modalidade. Exercício avaliativo pode cair a qualquer momento da aula e **não tem reposição por falta** — presença é nota.
- **Menções:** SS ≥ 9,0 · MS 7,0–8,9 · MM 5,0–6,9 (aprovado) · MI 3,0–4,9 · II < 3,0 · SR (frequência < 75%, independente da nota).

**Datas-chave:** **P1 15/09/2026** · P2 17/11/2026 · P3 08/12/2026 · 13/10 sem aula.

| Data | Conteúdo |
|---|---|
| 04/08 | Plano de ensino, conceitos e definições · Unidade 1 |
| 11/08 | Unidade 1 |
| 18/08 | Unidade 1 + Unidade 2 |
| 25/08 | Unidade 1 + Unidade 2 |
| 01/09 | Unidade 1 + Unidade 2 |
| **08/09** | Unidade 1 + Unidade 2 · **Revisão e resolução de exercícios** |
| **15/09** | **P1** |
| 22/09 | Devolutiva P1 · Unidades 1 e 2 · possível atividade prática |
| 29/09 | Unidade 3 + Unidade 4 |
| 06/10 | Unidade 4 |
| 13/10 | *sem aula* |
| 20/10 | Unidade 4 |
| 27/10 | Unidades 3 e 4 · possível atividade prática |
| 03/11 | Unidades 3 e 4 · possível atividade prática |
| 10/11 | Unidades 3 e 4 · revisão e exercícios |
| **17/11** | **P2** |
| 24/11 | Devolutiva P2 · possível atividade prática |
| 01/12 | Todas as unidades · dúvidas |
| **08/12** | **P3** (substitutiva) |

## 3. Mapa da pasta

```
Sistemas Lineares/
├── CLAUDE.md   # este arquivo (spec viva)
└── Docs/       # plano de ensino, anotações, simulados e gabaritos
```

| Arquivo | O que é | Uso |
|---|---|---|
| [Plano de Ensino Completo…pdf](Docs/Plano%20de%20Ensino%20Completo%20-%20Sistemas%20Lineares%20-%202026-2%20-%20Ter-19h15%20-%20ENG029-ENGNM3B.pdf) | Ementa, avaliação, cronograma, bibliografia | Fonte de verdade acadêmica. §1 e §2 aqui são resumo; se divergir, o PDF manda |
| [Resumo P1.pdf](Docs/Resumo%20P1.pdf) | **9 páginas** de anotações de aula (manuscritas + fotos do quadro) — cobre EDOs até resposta em frequência e amp op | Fonte de verdade do que **caiu em aula**. Mapa página a página no Anexo A |
| [Simulado P1 (B) - 2026-2.pdf](Docs/Simulado%20P1%20(B)%20-%20Sistemas%20Lineares%202026-2.pdf) + [Gabarito](Docs/Simulado%20P1%20(B)%20-%20Sistemas%20Lineares%202026-2%20-%20Gabarito.pdf) | Simulado **deste** semestre: 5 objetivas + 5 discursivas | Formato-espelho da P1. Ver §5 |
| [Simulado P1 - 2025-2.pdf](Docs/Simulado%20P1%20-%20Sistemas%20Lineares%202025-2.pdf) + [Gabarito](Docs/Simulado%20P1%20-%20Sistemas%20Lineares%202025-2%20-%20Gabarito.pdf) | Simulado do semestre passado — **QO1–QO5 e QD1 são idênticos** ao de 2026-2 | Confirma que o professor reaproveita enunciado. Estudar por ele é estudar pela prova |
| [Gabarito - 2025-2 - P1 v.pdf](Docs/Gabarito%20-%20Sistemas%20Lineares%20-%202025-2%20-%20P1%20v.pdf) | Gabarito da **P1 real** de 2025-2 (2 partes/versões) | Referência do nível e do estilo de correção esperado |

## 4. Regras SEMPRE-ATIVAS

Herda tudo de [../../CLAUDE.md §4](../../CLAUDE.md). Específico desta disciplina:

- **Prova é escrita e sem consulta.** Toda resolução aqui tem que ser reproduzível **na mão**, com as contas visíveis. Fechar em decimal só no último passo; resultado que só existe como número de calculadora não serve de estudo.
- **Sempre dizer em que domínio se está.** `x(t)`/`h(t)`/`y(t)` = tempo · `X(s)`/`H(s)` = Laplace · `H(jω)` = frequência. Misturar `s` e `jω` na mesma linha é a origem de metade dos erros — trocar de domínio é passo explícito, com `H(jω) = H(s)|s=jω` escrito.
- **Todo resultado de estabilidade é justificado pelos polos.** "Estável" sozinho não vale nota: localizar as raízes da equação característica e afirmar `Re{s_k} < 0 ∀k`, ou desenhar o plano complexo com os ×.
- **Duas rotas para H(s), e vale conferir com as duas.** (i) montar a EDO no tempo e transformar; (ii) impedâncias `Z_R = R`, `Z_L = sL`, `Z_C = 1/(sC)` + divisor de tensão. A segunda é muito mais rápida na prova; a primeira é o que a questão "determine a equação diferencial" pede. Chegar em H(s) diferente pelas duas = erro em uma delas.
- **Unidade nas respostas.** O professor escreve `[V]`, `[m]`, `N.s/m` nos enunciados; resposta final leva unidade.
- **Nunca inventar enunciado.** Se o PDF/foto do quadro estiver ilegível ou ambíguo, perguntar antes de resolver.
- **Questão de múltipla escolha: só o gabarito**, sem comentário nem análise dos distratores — a menos que peça explicitamente.
- **Caveman full sempre** na conversa. Resolução escrita, demonstração e este arquivo = escrita normal, pt-BR — comprimir doc de estudo esconde o passo que custa a questão.
- **Sem commit/push sem pedido explícito · sem trailer de co-author.**

## 5. Helpers canônicos — o "kit da P1"

Resumo operacional. Detalhe e origem no [Resumo P1.pdf](Docs/Resumo%20P1.pdf) (Anexo A).

**EDO geral do sistema LTI:**

```
Σ(k=0..N) a_k · d^k/dt^k y(t) = Σ(k=0..M) b_k · d^k/dt^k x(t)
```

**Resposta forçada = natural + particular:** `y_F(t) = y_N(t) + y_P(t)`

| Peça | Como se obtém |
|---|---|
| `y_N(t)` (natural / homogênea) | Entrada nula. Substituir `y = e^{st}` na homogênea → **equação característica** `Σ a_k s^k = 0` → N raízes. Distintas: `y_N = K₁e^{s₁t} + … + K_N e^{s_N t}`. Raiz de multiplicidade M: `(a₀ + a₁t + … + a_{M-1}t^{M-1})e^{st}` |
| `y_P(t)` (particular) | Mesma **forma** da entrada. `x = A sen(ωt)` → `y_P = A cos(ωt) + B sen(ωt)`; `x = Σ c_i e^{s_i t}` → soma de exponenciais de mesmos expoentes; `x` polinômio grau n → polinômio grau n. Substituir na EDO e casar coeficientes |
| Constantes `K_i` | **Depois** de somar `y_N + y_P`, impondo as condições iniciais — que na resposta forçada são **nulas** (`y_F(0)=0`, `y_F'(0)=0`, …) |

**Estabilidade:** todas as raízes da equação característica (= **polos de H(s)**) no **semiplano esquerdo**, `Re{s_k} < 0`. Consequência: `lim(t→∞) y_N(t) = 0` ⇒ passado o **regime transitório**, `y_F(t) ≃ y_P(t)` (**regime permanente**).

**Função de transferência — três definições equivalentes:**

```
H(s) = L{h(t)} = Y(s)/X(s) = (Σ b_k s^k)/(Σ a_k s^k)
```

Polos = raízes do denominador = raízes da equação característica. `H(s)` ⇄ EDO é conversão mecânica nos dois sentidos (`s^k ↔ d^k/dt^k`).

**Autofunção (o atalho que a prova adora):** `e^{st}` é autofunção de todo sistema LTI —

```
x(t) = e^{s₀t}  ⇒  y(t) = H(s₀) · e^{s₀t}
```

Serve para exponencial real (`s₀ = a`), para senoide via `s₀ = jω`, e é o caminho de 2 linhas para "resposta em regime permanente a x(t) = e^{at}".

**Impedâncias em Laplace:** `Z_R = R` · `Z_L = sL` · `Z_C = 1/(sC)`. Divisor de tensão direto: `Y(s) = X(s) · Z_saída / Z_total`.

**Amp op ideal (inversor):** `H(s) = − Z_out / Z_in` — vem de `I_in(s) = I_out(s)` com terra virtual. Integrador (`Z_in = R`, `Z_out = 1/sC`): `H(s) = −1/(sRC)`, polo em `s = 0`.

**Resposta em frequência:**

```
H(jω) = H(s)|s=jω = |H(jω)| · e^{jφ(ω)}
```

`|H(jω)|` = resposta em amplitude (ganho) · `φ(ω) = arg{H(jω)}` = resposta em fase (defasagem).
Para `x(t) = A cos(ω₀t)`: `y(t) = A·|H(jω₀)|·cos(ω₀t + φ(ω₀))`.
**Frequência de corte:** `|H(jω_c)| = H_máx/√2`.

**Transformadas usadas (as únicas que caem na P1):**

| `x(t)` | `X(s)` | RC |
|---|---|---|
| `δ(t)` | `1` | todo o plano |
| `u(t)` | `1/s` | `Re{s} > 0` |
| `u(t)e^{at}` | `1/(s−a)` | `Re{s} > Re{a}` |
| `x^{[k]}(t)` (integrais) | `X(s)/s^k` | — |
| `d^k/dt^k x(t)` | `s^k X(s)` | — |
| `x₁(t) * x₂(t)` | `X₁(s)·X₂(s)` | — |
| `x(t − t₀)` | `e^{−st₀} X(s)` | — |

Inversão de `H(s)` racional = **frações parciais** e voltar pela tabela (ex.: `1/(s(s+1)) = 1/s − 1/(s+1)` → `h(t) = u(t)[1 − e^{−t}]`).

**Conexões de blocos:**

```
cascata:      H(s) = H₁(s)·H₂(s)…H_N(s)
paralelo:     H(s) = H₁(s) + H₂(s) + … + H_N(s)
realimentação: H(s) = H₁(s) / (1 − H₁(s)H₂(s))
```

## 6. Common Hurdles (armadilhas conhecidas)

- **"Resposta forçada" ≠ "resposta em regime permanente".** Forçada = `y_N + y_P` **com condições iniciais nulas** (inclui o transitório). Regime permanente = só `y_P`, e só faz sentido porque o sistema é estável. O simulado usa os dois termos em questões vizinhas (QD1 pede forçada, QO2/QD4/QD5 pedem regime permanente) — ler qual é.
- **Resposta natural com condição inicial ≠ resposta forçada.** Na QO4 do simulado, `y_N(0)=0,1` e `y_N'(0)=0` são as condições iniciais **do teste**, não zeros. Só a resposta *forçada* usa condições iniciais nulas.
- **Autofunção só entrega o regime permanente.** `y = H(s₀)e^{s₀t}` é a solução particular. Se a questão pedir a resposta *completa* / *forçada*, ainda falta `y_N` e a imposição das condições iniciais.
- **Se a entrada tem um `s₀` que é raiz da equação característica, a forma de `y_P` muda** — multiplicar por `t` (ressonância). Casar coeficientes sem isso dá sistema impossível (`0 = c`); quando o sistema linear não fechar, checar isso primeiro.
- **Circuito LC puro é instável, não "estável no limite".** `1 + s²LC = 0` → `s = ±j/√(LC)`: polos **em cima** do eixo imaginário, `Re{s} = 0`, logo **fora** do semiplano esquerdo aberto. `h(t)` oscila para sempre e `∫|h(t)|dt = ∞`. O resumo (p. 6) marca explicitamente "**Instável**" — não trocar por "marginalmente estável" na prova.
- **`s` do resumo às vezes parece `∂`/`ə` na letra manuscrita.** É sempre a variável de Laplace. Do mesmo jeito, `∫|h(t)|dt < ∞` é o critério BIBO — equivalente aos polos no semiplano esquerdo, não um segundo critério independente.
- **Fase do amp op inversor não é `−arctg(ωR₂C)`.** O sinal negativo do ganho vale 180°: `φ(ω) = 180° − arctg(ωR₂C)`. Esquecer os 180° é erro recorrente na questão de resposta em fase.
- **`H(jω)` pede módulo de número complexo, não do numerador.** `|H(jω)| = |num|/|den|`, com `|a + jb| = √(a² + b²)`. Ex.: `H(jω) = (R₂/R₁)/(1 + jωR₂C)` → `|H| = (R₂/R₁)/√(1 + (ωR₂C)²)`.
- **Período `2π` s significa `ω = 1 rad/s`, não `f = 2π`.** `ω = 2π/T`. Aparece direto na QO3.
- **Resposta a `e^{at}` com `a > 0` não é "regime permanente" no sentido usual** — a entrada cresce. A conta `y = H(a)e^{at}` continua valendo (autofunção), desde que `a` esteja na região de convergência / não seja polo. QD4 do simulado 2026-2 usa `x(t) = e^{0,1t}` justamente por isso.
- **Os dois simulados são o mesmo enunciado.** QO1–QO5 e QD1 de [2026-2 (B)](Docs/Simulado%20P1%20(B)%20-%20Sistemas%20Lineares%202026-2.pdf) são idênticos aos de [2025-2](Docs/Simulado%20P1%20-%20Sistemas%20Lineares%202025-2.pdf); a versão 2026-2 acrescenta QD2–QD5 sobre o filtro passivo. Não são listas diferentes — não "resolver as duas" achando que dobrou o treino.
- **O gabarito da P1 2025-2 tem as fórmulas como imagem.** `pdftotext` devolve parênteses vazios; para ler as expressões é preciso **renderizar as páginas** (`pdftoppm -r 150 -png`) e olhar. Vale para o [Resumo P1.pdf](Docs/Resumo%20P1.pdf) também — são fotos, **não tem camada de texto**.
- **Caminho da pasta tem `°` e espaço** — todo comando de shell precisa de aspas duplas. Ver [../../CLAUDE.md §6](../../CLAUDE.md).

## 7. Antes de fechar alteração

- [ ] Resolução com os passos visíveis, reproduzível à mão, na notação do professor
- [ ] Domínio explícito em cada etapa (`t` / `s` / `jω`)
- [ ] Estabilidade justificada pelos polos, não afirmada
- [ ] `H(s)` conferida pelas duas rotas (EDO e impedâncias) quando o circuito permitir
- [ ] Unidade na resposta final
- [ ] Mapa de aulas (§2) e Hurdles (§6) atualizados se a aula trouxe conteúdo/armadilha nova
- [ ] `**Última revisão:**` do topo atualizada
- [ ] Sem commit/push sem pedido explícito · sem trailer de co-author

## 8. Inventário

| Ref | Item | Status |
|---|---|---|
| Anotações U1+U2 | 9 páginas de resumo manuscrito, EDOs → resposta em frequência → amp op | ✅ [Docs/Resumo P1.pdf](Docs/Resumo%20P1.pdf) |
| Simulado P1 2026-2 (B) | 5 objetivas + 5 discursivas (filtro ativo, suspensão veicular, filtro passivo) | ⏳ a resolver |
| Simulado P1 2025-2 | mesmo enunciado, sem QD2–QD5 | ⏳ a resolver |
| P1 | Prova 15/09/2026 | ⏳ |
| Atividades TE1 | nenhuma registrada até aqui | — |

## 9. Índice de navegação

- **Ementa / avaliação / cronograma** → [Docs/Plano de Ensino…pdf](Docs/Plano%20de%20Ensino%20Completo%20-%20Sistemas%20Lineares%20-%202026-2%20-%20Ter-19h15%20-%20ENG029-ENGNM3B.pdf)
- **Teoria vista em aula (P1)** → [Docs/Resumo P1.pdf](Docs/Resumo%20P1.pdf) + Anexo A abaixo
- **Formulário operacional** → §5 deste arquivo
- **Treino de prova** → `Docs/Simulado P1*.pdf` + gabaritos
- **Disciplina do mesmo professor** → [../PSM/CLAUDE.md](../PSM/CLAUDE.md)
- **Regras do repositório** → [../../CLAUDE.md](../../CLAUDE.md)

---

## Anexo A — Mapa do `Resumo P1.pdf` (página a página)

São fotos/scans sem camada de texto. Renderizar com `pdftoppm -r 150 -png "Docs/Resumo P1.pdf" p` antes de tentar ler.

| Pág. | Conteúdo |
|---|---|
| 1 | **EDOs.** Forma geral · resposta forçada `y_F = y_N + y_P` · método `y = e^{st}` → equação característica · raízes distintas e com multiplicidade · **critério de estabilidade** (semiplano esquerdo) · forma de `y_P` por tipo de entrada (3 exemplos) · exemplo RC completo com `x(t) = 5cos(2t)` |
| 2 | **Exemplo RLC completo (a–e):** obter a EDO · classificar estabilidade (raízes `−1/2 ± j√3/2`) · `y_N` · `y_P` para `x = 5cos(2t)` (`y_P = −5/7 cos2t + 10/7 sen2t`) · `y_F` com condições iniciais nulas e solução do sistema em `K₁, K₂` |
| 3 | **Consolidação:** resposta forçada (natural = entrada nula/condições iniciais; particular = entrada específica) · equação característica e polos · regime transitório × permanente · autofunções e `y = H(s)e^{st}` · **duas definições de `H(s)`** · **transformada de Laplace bilateral** e o par `u(t) ↔ 1/s`, `Re{s} > 0`, com região de convergência no plano |
| 4 | **Tabela de propriedades da transformada** · **sistema integrador** (`H(s) = 1/s`) · exemplo numérico com `h(t)` pulso e `x = e^{2t}` (`y = 0,091e^{2t}`) · `H(s) = Y(s)/X(s)` a partir da EDO · **definição de polo** (`lim|H(s)| = ∞`) e critério de estabilidade por polos · exemplo `h(t) = u(t)e^{−t}` com `∫|h|dt = 1 < ∞` |
| 5 | **Função de transferência e impedâncias** `Z_R = R`, `Z_L = sL`, `Z_C = 1/(sC)` · **1º método** (EDO) × **2º método** (divisor de tensão) no mesmo circuito, chegando em `H(s) = 1/(1 + 0,2s + 0,5s²)` · exemplo com duas malhas · `Z_R ∥ Z_C` e volta de `H(s)` para a EDO |
| 6 | **Circuito LC** — `H(s) = 1/(1 + s²LC)`, polos em `±j/√(LC)`, **instável** · **resposta em frequência**: `H(ω) = F{h(t)}`, `H(jω) = |H(jω)|e^{jφ(ω)}` · exemplo LC com `x = e^{j0,2t}` (`|H| ≈ 1,042`, `φ = 0`) · `H(jω) = H(s)|s=jω` · ressonância em `ω₀ = 1/√(LC)` · **cascata** (produto das `H`) |
| 7 | **Paralelo** (soma das `H`) e **realimentação** (`H = H₁/(1 − H₁H₂)`) · exercício completo de malha fechada: `H = 1/(s² + s)`, polos `0` e `−1` → **instável**, `y` para `x = e^{2t}`, `H(jω)`, `|H(jω)|`, `h(t)` por frações parciais (`u(t)[1 − e^{−t}]`) · fase `φ(ω) = 180° − arctg(ωR₂C)` · **frequência de corte** `|H| = H_máx/√2` · **amp op inversor** com `R₂ ∥ C`: `H(s) = −(R₂/R₁)/(1 + sR₂C)`, polo `−1/(R₂C)`, estável |
| 8 | Resposta em amplitude do amp op (`|H| = (R₂/R₁)/√(1 + (ωR₂C)²)`) · **integrador com amp op** (`H = −1/(sRC)`, polo em 0, passa-baixa) · dedução geral `H(s) = −Z_out/Z_in` · RLC série: `1 + sRC + s²LC = 0`, raízes `−R/2L ± √((R/2L)² − 1/LC)` e prova de que ficam sempre no semiplano esquerdo |
| 9 | RLC com resistência em série (`H = 1/(1 + sRC + s²LC)`) · **frequência de corte do filtro passa-baixa** `ω_c = 1/(R₂C)` a partir de `ωR₂C = 1` |

## Anexo B — Bibliografia

**Básica:**

- HAYKIN, S.; VAN VEEN, B. **Sinais e Sistemas**. Porto Alegre: Bookman, 2002.
- LATHI, B. P. **Sinais e Sistemas Lineares**, 2. ed. Porto Alegre: Bookman, 2007.
- OPPENHEIM, A.; WILLSKY, A. **Sinais e Sistemas**. São Paulo: Pearson Prentice Hall, 2010.

**Complementar:** ROBERTS (Fundamentos em Sinais e Sistemas) · OPPENHEIM & SCHAFER (Discrete-Time Signal Processing) · GILAT (Matlab com aplicações em engenharia) · HANSELMAN (Matlab 6) · PHILLIPS, PARR & RISKIN (Signals, Systems, and Transforms) · GIROD, RABENSTEIN & STENGER (Sinais e Sistemas) · anotações das aulas.
