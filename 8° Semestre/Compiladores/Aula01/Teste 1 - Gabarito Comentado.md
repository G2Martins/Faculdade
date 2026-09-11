# Teste 1 — Conceitos Fundamentais (Google Forms) — Gabarito comentado

**Resultado:** 35/38 · aplicado no Google Forms · conteúdo = Slide 1 (Fundamentos: SI, dados, memórias, redes, conversão de bases, fluxogramas).
**Fonte de estudo usada:** [../CLAUDE.md](../CLAUDE.md), Anexo A → "Slide 1 — Fundamentos".

> Este arquivo existe porque o conteúdo do Teste 1 volta na **P1 (22/09/2026)**. Os três erros abaixo são os únicos pontos perdidos; o resto do gabarito está registrado para releitura rápida.

---

## 1. Os três erros

### Erro 1 — "Os componentes de hardware básicos de um sistema computacional são" (0/1)

| | |
|---|---|
| **Marcado** | CPU · Dispositivo de Entrada · Memória Principal |
| **Correto** | CPU · Dispositivo de Entrada · **Dispositivo de Saída** · Memória Principal |
| **Causa** | Omissão. Faltou marcar "Dispositivo de saída". |

O `CLAUDE.md` estava certo e completo: *"Sistema de Informação (SI): Hardware (CPU, memórias, **E/S**)"*. "E/S" é entrada **e** saída — as duas contam como componente básico. Sistema Operacional ficou corretamente de fora, porque é software.

**Regra para a P1:** hardware básico = CPU + memória principal + E/S (as duas pontas). Se a alternativa separa entrada de saída, marque as duas.

---

### Erro 2 — "Um conjunto de informações forma:" (0/1)

| | |
|---|---|
| **Marcado** | Um conhecimento |
| **Correto** | **Uma inteligência** |
| **Causa** | Resposta contra a fonte. O `CLAUDE.md` já trazia a cadeia certa e ela foi ignorada na hora da prova. |

O Anexo A registra textualmente: *"Cadeia da IA: **Dado → Informação → Inteligência → Conhecimento**"*.

Aplicando a cadeia do professor:

| Nível | Formado por |
|---|---|
| Dado | símbolo isolado, sem contexto (`a`, `1`, `Km`, `80`) |
| Informação | dado **com contexto** ("80 km/h na placa") |
| **Inteligência** | **conjunto de informações** |
| Conhecimento | conjunto de inteligências |

A pegadinha é que a pirâmide clássica da literatura (DIKW — *data, information, knowledge, wisdom*) coloca conhecimento logo depois de informação. **A cadeia do professor não é a DIKW.** Ele insere "inteligência" entre informação e conhecimento, e é a ordem dele que vale na prova.

---

### Erro 3 — "Sobre o *checklist*" (0/1)

As alternativas são quatro:

| | Alternativa |
|---|---|
| **A** | Pode ser feito em anonimato. |
| **B** | Exige-se estar em sequência cronológica ou por atividade. |
| **C** | Exige-se possuir marcadores de "feito" ou "pronto" para cada uma das atividades. |
| **D** | A lista de atividades sempre é aleatória. |

**Duas combinações já descartadas pelo próprio formulário:**

| Tentativa | Marcado | Resultado |
|---|---|---|
| 1ª | A + B + C | 0/1 |
| 2ª | B + C | 0/1 |
| 3ª | A + C | 0/1 |
| **4ª** | **C sozinha** | **1/1 ✅** |

**Resposta correta: apenas C — "Exige-se possuir marcadores de 'feito' ou 'pronto' para cada uma das atividades".** Confirmada pelo formulário.

As três primeiras tentativas eliminaram os pares e a trinca. A quarta fechou: das quatro alternativas, só C é verdadeira.

- **C é verdadeira.** Marcador de conclusão por item é o que separa um checklist de uma lista qualquer.
- **B é falsa.** Ordem cronológica ou por atividade é característica do modelo "Passo a Passo", cobrado na questão imediatamente anterior do mesmo teste ("as atividades podem ser numeradas", "sempre possui um início e um fim"). No checklist a ordem é indiferente: o que importa é nenhum item ficar sem marcação.
- **A é falsa.** O checklist existe para responsabilizar quem executou cada item. Sem identificação de quem marcou, não há a quem perguntar se o item foi de fato feito, e o artefato perde a função de controle.
- **D é falsa** por ser absoluta: "sempre aleatória" impõe desordem obrigatória, o que nenhum material sustenta.

**Para a P1:** a pegadinha é confundir checklist com passo a passo. O **passo a passo** é ordenado — numeração, início e fim, cabeçalho opcional. O **checklist** não exige ordem nem dispensa responsável; o que ele exige é marcador de conclusão em cada item. Custou quatro tentativas para descobrir, mas é uma linha para lembrar.

**Lacuna no material:** o `CLAUDE.md` não cobre checklist nem o modelo "Passo a Passo" — as duas questões do teste sobre esses temas vieram do Slide 1 e não estavam resumidas no Anexo A.

---

## 2. Gabarito completo (23 itens · 38 pontos)

| # | Questão | Resposta correta | Pts |
|---|---|---|---|
| 1 | Binário do decimal 62 | `00111110` | 1/1 |
| 2 | Conceito de arquivo integrado | Disponibilizar uma fonte de informação comum a um grupo de usuários requisitantes | 1/1 |
| 3 | Uma mili mega hora equivale a | `1Kh` — uma kilo hora (10⁻³ × 10⁶ = 10³) | 1/1 |
| 4 | Características do S.O. | Compartilhar recursos · Administrar o hardware · Facilitar a operação | 1/1 |
| 5 | Papel das memórias | Buffer = transmissão entre dispositivos · RAM = programas e aplicativos abertos · Registradora = dados de e para execução do processador | 3/3 |
| 6 | **Componentes de hardware básicos** | **CPU · Entrada · Saída · Memória Principal** | **0/1** |
| 7 | Modos de transmissão | Mouse = Simplex · Walkie-talkie = Half-Duplex · Telefone = Full-Duplex | 3/3 |
| 8 | Equivalências numéricas | 200B=0,2KB · 20000b=20Kb · 4000B=32Kb · 2KB=2000 bytes · 2Kb=2000 bits · 0,32Km=320m · 20B=20 bytes · 32000m=32Km · 3,20Km=3200m · 256Kb = sem par | 10/10 |
| 9 | Modelo "Passo a Passo" | Permite cabeçalho · Atividades podem ser numeradas · Sempre tem início e fim | 1/1 |
| 10 | Dois componentes do SI na imagem | Peopleware e Hardware | 1/1 |
| 11 | Com quem a CPU se comunica | Dispositivos de entrada · Dispositivos de saída · Memória principal | 1/1 |
| 12 | Equipamentos de rede | Modem = conexão entre computadores · Switch = rede LAN · Roteador = rotas de envio | 3/3 |
| 13 | O que é BIOS | Basic Input Output System — inicia o SO e as tarefas mais importantes | 1/1 |
| 14 | O que compõe um SI | Peopleware, hardware e software | 1/1 |
| 15 | Tempo p/ gravar 2MB a 32KB/s | `62s` (2000 ÷ 32 = 62,5) | 1/1 |
| 16 | Memórias de maior velocidade | Principal | 1/1 |
| 17 | Binário do hexadecimal FD | `11111101` (F=1111, D=1101) | 1/1 |
| 18 | **Sobre o checklist** | **Apenas** "exige-se possuir marcadores de 'feito' ou 'pronto'" | **0/1** |
| 19 | **Conjunto de informações forma** | **Uma inteligência** | **0/1** |
| 20 | Velocidade média: 1GB em 6min | `22Mbps` (8000Mb ÷ 360s ≈ 22,2) | 1/1 |
| 21 | Exemplos de informação | "O dia de hoje é um dia depois de ontem" · placa de proibido fumar · botão de power | 1/1 |
| 22 | Exemplos de dados computacionais | `43` · `Opa.` · a imagem do triângulo | 1/1 |
| 23 | Bytes em 12s a 2Mbps | `3MB` (2Mbps × 12s = 24Mb = 3MB) | 1/1 |

---

## 3. Contas que caem de novo

As três questões de cálculo seguiram a mesma fórmula do Anexo A (`volume = velocidade × tempo`, `1 MB/s ≈ 8 Mbps`). Vale decorar o encadeamento:

```
Q15  2MB ÷ 32KB/s      = 2000KB ÷ 32KB/s  = 62,5s        → 62s
Q20  1GB em 6min       = 8000Mb ÷ 360s    = 22,2Mbps     → 22Mbps
Q23  2Mbps × 12s       = 24Mb ÷ 8         = 3MB          → 3MB
```

O professor usa prefixos decimais (1K = 1000), não binários (1K = 1024). Com 1024 a Q15 daria 64s, que **não** está entre as alternativas — é a confirmação de que a base é decimal.

Unidade em maiúscula é byte (`B`, `KB`, `MB`); em minúscula é bit (`b`, `Kb`, `Mb`). Metade dos erros possíveis nessas três questões é troca de `b` por `B`.

---

## 4. O que o material precisa ganhar antes da P1

1. **Cadeia Dado → Informação → Inteligência → Conhecimento** — já está no Anexo A, mas precisa de destaque como pegadinha, porque contraria a pirâmide DIKW que qualquer outra fonte ensina. Registrado nos *Common Hurdles* do [../CLAUDE.md](../CLAUDE.md).
2. **Checklist e modelo "Passo a Passo"** — o Slide 1 cobra os dois e o Anexo A não os resume. Se voltarem na P1, hoje não há de onde reler. A diferença que o teste cobra: o **passo a passo** é ordenado (numeração, início e fim, cabeçalho opcional); o **checklist** não exige ordem, exige marcador de conclusão por item e dispensa identificação do autor.
