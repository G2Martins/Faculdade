# CLAUDE.md — Compiladores (8° Semestre · MDC168)

> **Spec viva.** Contexto da disciplina lido pelo agente em toda sessão. Atualizar no mesmo commit que adiciona aula, exercício ou extensão de sintaxe.
>
> **Última revisão:** 2026-08-25
> **Regras do repositório inteiro:** [../../CLAUDE.md](../../CLAUDE.md) · **Linguagem da disciplina:** [Aula02/Sintaxe MineonScript.md](Aula02/Sintaxe%20MineonScript.md)

---

## 0. Para que serve

Passar em Compiladores com nota e sair com um **transpilador MineonScript → Python** funcionando (Unidade IV). Todo exercício semanal resolvido aqui vale nota na avaliação contínua **e** é peça do tradutor final.

**Placar:** 3 aulas registradas · 10 exercícios entregues · 0 pendentes · próxima prova **P1 em 22/09/2026**.

## 1. O que é

- **Curso:** 2130 — Ciência da Computação (IESB) · **Ano/Semestre:** 2026/2
- **Disciplina:** Compiladores — **MDC168** · **Turma:** ENGCDM4B · **CH:** 60h semestral
- **Professor:** Roger Rocha Ferreira · roger.ferreira@iesb.br
- **Material:** Google Sala de Aula (slides por encontro) + exercícios semanais pontuados

**Ementa / Unidades:**

1. **Unidade I** — Introdução a compiladores e interpretadores
2. **Unidade II** — Análise léxica, sintática e semântica
3. **Unidade III** — Sínteses e código objeto (código intermediário, otimização, gerência de memória)
4. **Unidade IV** — Tradutor de códigos (projeto e implementação de um tradutor)

## 2. Como roda (avaliação e calendário)

```
A1 = P1*0,8 + T1*0,2
A2 = P2*0,8 + T2*0,2
MF = A1*0,4 + A2*0,6          → aprovado se MF ≥ 5,0 e frequência ≥ 75%

P3 (substitutiva, se MF < 5,0):
MF = max{ P3*0,4 + A2*0,6 ; A1*0,4 + P3*0,6 }
```

Provas individuais sem consulta; conteúdo = ementa dada até a data da prova. Exercícios semanais contam na avaliação contínua (o `T` da fórmula).

**Datas-chave:** P1 **22/09/2026** · P2 **24/11/2026** · P3 **08/12/2026**

| Data | Tópico | Assunto |
|---|---|---|
| 04/08 | Introdução e Arquitetura | Compilação vs interpretação, fases, pipeline de tradução |
| 11/08 | Análise Léxica: Fundamentos | Tokens, lexemas, padrões; expressões regulares e autômatos finitos |
| 18/08 | Análise Léxica: Implementação | Desenvolvimento de analisador léxico; tratamento/recuperação de erros léxicos |
| **25/08** | **Análise Sintática: Fundamentos** | Gramáticas livres de contexto; árvores sintáticas e ambiguidade; top-down |
| 08/09 | Análise Sintática: Estruturas | AST; mapeamento de regras gramaticais em nós |
| 15/09 | Análise Sintática: Implementação | Analisador sintático preditivo por descida recursiva |
| **22/09** | **Avaliação** | **P1** |
| 29/09 | Tabela de Símbolos | Organização, gerenciamento, resolução de escopo |
| 06/10 | Análise Semântica: Fundamentos | Checagem de tipos, verificação de declarações, regras de validação |
| 20/10 | Análise Semântica: Implementação | Validação sobre a AST; integração com tabela de símbolos |
| 27/10 | Gerência de Memória | Ambiente de execução, pilha, registradores de ativação, memória dinâmica |
| 03/11 | Execução e Interpretação | Caminhamento em árvores sintáticas; avaliação e execução de código |
| 10/11 | Integração do Tradutor | Conexão do pipeline e testes de integração |
| 17/11 | Integração do Tradutor | Validação do fluxo completo |
| **24/11** | **Avaliação** | **P2** |
| **08/12** | **Avaliação** | **P3** (substitutiva) |

## 3. Mapa de módulos (pasta)

Padrão: `AulaXX/Exercicio X.md` — um arquivo por exercício, código MineonScript em bloco de código.

| Pasta | Conteúdo | Saída |
|---|---|---|
| [Aula01/](Aula01) | Exercicio B (notas/conceito) · C (jogo adivinhação) · D (máquina R$ 5,00 com loop) · E (fila com prioridades) | 4 algoritmos em MineonScript; origem das extensões `senao`, `enquanto`, listas |
| [Aula02/](Aula02) | [Sintaxe MineonScript.md](Aula02/Sintaxe%20MineonScript.md) · Exercicio A (3 produtos: soma+média) · B (5 aleatórios, >10 e <20) · C (máquina R$ 4,50) · [Fluxograma Tradutor Python.md](Aula02/Fluxograma%20Tradutor%20Python.md) · [Questionario.md](Aula02/Questionario.md) | **Definição da linguagem** + desenho do transpilador (Mermaid) + gabarito comentado (fases da tradução, compilador vs interpretador) |
| [Aula03/](Aula03) | Aula03.pdf (slides BNF) · [Exercicio BNF KK-102.md](Aula03/Exercicio%20BNF%20KK-102.md) | Gramática BNF completa da calculadora, com precedência embutida |

**Fonte de verdade da linguagem** = `Aula02/Sintaxe MineonScript.md`. O §5 aqui é resumo; se divergir, o arquivo de sintaxe manda.

## 4. Regras SEMPRE-ATIVAS

Herda tudo de [../../CLAUDE.md §4](../../CLAUDE.md). Específico desta disciplina:

- **Exercício se resolve em MineonScript, não em Python.** O professor avalia a linguagem da disciplina; Python só aparece como **alvo** da tradução (Unidade IV), nunca como solução do enunciado.
- **Toda palavra reservada ou operador novo é extensão nossa até prova em contrário.** Antes de usar, registrar em `Aula02/Sintaxe MineonScript.md` com a justificativa, e anotar no §5 daqui. Sintaxe não documentada quebra o tradutor da Unidade IV, que vai ser escrito a partir dessa lista.
- **Toda decisão de gramática é justificada por escrito.** Ambiguidade em gramática é exatamente o que a prova cobra; a seção "Decisões de projeto" de cada arquivo é o que se relê antes da P1.
- **Extensão pendente é rastreada, não esquecida.** Se um exercício precisou de algo que a linguagem não tem e nós não formalizamos, entra na lista de pendências do §5 — hoje `!=` e `cancelar`.
- **Nunca inventar enunciado.** Se o PDF/slide não estiver claro, perguntar antes de resolver.

## 5. Helpers canônicos — MineonScript

Resumo operacional. Detalhe e histórico em [Aula02/Sintaxe MineonScript.md](Aula02/Sintaxe%20MineonScript.md).

**Sintaxe base (slide original do professor):**

```
declarar a, b, r
a = 2
b = -1
r = 2 * a + b
mostrar "Resultado: "
mostrar r
```

**Palavras reservadas:** `declarar`, `mostrar`, `ler`, `aleatorio`, `se`, `entao`, `senao`, `fim`, `enquanto`, `faca`

**Símbolos:** `=` (atribuição) · `+ - * /` · `> < == >= <=` (comparação) · `,` (separador) · `" "` (texto) · `( )` (agrupamento) · `[ ]` (lista)

**Extensões propostas por nós** (todas documentadas nos arquivos de origem): `ler` (entrada), `aleatorio` (random), `se/entao/senao/fim` (condicional), `enquanto ... faca ... fim` (laço), `==`/`>=`/`<=`, listas com `tamanho(l)`, `contem(l, x)`, `remover_primeiro(l, x)` (Exercicio E).

**Pendências de sintaxe:** `!=` (surgiu no Exercicio C) · `cancelar` (surgiu no Exercicio D). Formalizar antes de escrever o lexer.

**Tabela de tradução → Python** (base do transpilador, ver [Aula02/Fluxograma Tradutor Python.md](Aula02/Fluxograma%20Tradutor%20Python.md)):

| MineonScript | Python |
|---|---|
| `mostrar` | `print` |
| `ler` | `float(input())` |
| `aleatorio` | `random.randint(0, 100)` |
| `se ... entao` | `if ...:` + indentação |
| `fim` | dedent |
| `declarar x` | `x = 0` |

## 6. Common Hurdles

Antes de "consertar" algo abaixo, saiba que é intencional / já resolvido:

- **A BNF do KK-102 diverge da proposta do slide — de propósito.** O slide deixa `<operacao_binaria>` ambígua; a nossa embute precedência em camadas `<expressao>` → `<termo>` → `<potencia>` → `<fator>`, então `2 + 3 * 4` deriva sem regra extra de desambiguação. Exponenciação ficou associativa à direita (`2^3^2 = 512`), o resto à esquerda. Não "simplificar" de volta pro modelo do slide.
- **`Aula02/Exercicio C.md` é a máquina de R$ 4,50; `Aula01/Exercicio D.md` é a de R$ 5,00 com loop.** São exercícios diferentes, de aulas diferentes, com o mesmo tema. Confundir os dois já causou erro de inventário neste arquivo (a versão anterior apontava a máquina de R$ 4,50 para `Aula03/`, pasta onde ela nunca esteve).
- **A numeração dos exercícios é do professor, não sequencial na pasta.** `Aula01` tem B, C, D, E (sem A); `Aula02` tem A, B, C. Não renomear pra "arrumar" — a letra é a referência usada em aula.
- **Os slides não seguem a ordem das pastas.** O "Slide 1" (fundamentos: SI, dados, fluxogramas) é material de base, não conteúdo da Aula01. O mapeamento correto está no Anexo A.
- **Caminho da pasta tem `°` e espaço** — todo comando de shell precisa de aspas duplas. Ver [../../CLAUDE.md §6](../../CLAUDE.md).

## 7. Antes de fechar alteração

- [ ] Arquivo em `AulaXX/Exercicio Y.md`, com enunciado transcrito e seção "Decisões de projeto"
- [ ] Código em **MineonScript** (não Python), usando só sintaxe documentada
- [ ] Extensão de sintaxe nova registrada em `Aula02/Sintaxe MineonScript.md` **e** no §5 daqui
- [ ] Inventário do §8 atualizado com a linha nova
- [ ] `**Última revisão:**` do topo atualizada
- [ ] Sem commit/push sem pedido explícito · sem trailer de co-author

## 8. Inventário de exercícios

| Ref | Enunciado | Status |
|---|---|---|
| PB1 | 3 produtos → soma + média | ✅ [Aula02/Exercicio A.md](Aula02/Exercicio%20A.md) |
| PB2 | 5 aleatórios → exibir >10, depois <20 | ✅ [Aula02/Exercicio B.md](Aula02/Exercicio%20B.md) |
| Tradutor | Fluxograma MineonScript → Python + condicionalidade estrutural | ✅ [Aula02/Fluxograma Tradutor Python.md](Aula02/Fluxograma%20Tradutor%20Python.md) |
| Questionário | Fases da tradução · compilador vs interpretador | ✅ [Aula02/Questionario.md](Aula02/Questionario.md) |
| A | Máquina de refrigerante R$ 4,50 (troco / igual / insuficiente) | ✅ [Aula02/Exercicio C.md](Aula02/Exercicio%20C.md) |
| B | Notas: 3 notas (0–10), média → Aprovado ≥7 / Recuperação 5–6,9 / Reprovado <5. Extra: validar nota inválida | ✅ [Aula01/Exercicio B.md](Aula01/Exercicio%20B.md) |
| C | Jogo de adivinhação 1–100: maior/menor/bem maior/bem menor/acertou ("memória curta") | ✅ [Aula01/Exercicio C.md](Aula01/Exercicio%20C.md) |
| D | Máquina R$ 5,00 com loop: se insuficiente, aguarda o restante. Extra: e se não tiver mais dinheiro? | ✅ [Aula01/Exercicio D.md](Aula01/Exercicio%20D.md) |
| E | Fila de banco com prioridades G > I > P > N, desempate por chegada. `[P,I,G,N,I]` → ordem de atendimento. Extra: evitar espera eterna do Normal | ✅ [Aula01/Exercicio E.md](Aula01/Exercicio%20E.md) |
| BNF | Gramática BNF da calculadora KK-102 (soma, sub, mult, div, exp, raiz, média, áreas) | ✅ [Aula03/Exercicio BNF KK-102.md](Aula03/Exercicio%20BNF%20KK-102.md) |

## 9. Índice de navegação

- **Base teórica dos slides** → Anexo A (abaixo)
- **Bibliografia** → Anexo B (abaixo)
- **Definição da linguagem** → [Aula02/Sintaxe MineonScript.md](Aula02/Sintaxe%20MineonScript.md)
- **Desenho do transpilador** → [Aula02/Fluxograma Tradutor Python.md](Aula02/Fluxograma%20Tradutor%20Python.md)
- **Regras do repositório** → [../../CLAUDE.md](../../CLAUDE.md)

---

## Anexo A — Base teórica (slides)

### Slide 2 — Compiladores e Interpretadores (núcleo da disciplina)

**Objetivo:** diferenciar interpretar vs compilar; mapear como um arquivo texto vira executável nas 4 fases clássicas.

**Compilação vs Interpretação (analogia do livro de receitas FR→PT):**

- **Intérprete** = tradutor simultâneo: lê linha, traduz, executa, segue. Vantagem: executa imediatamente. Desvantagem: laço de mil repetições traduz a mesma linha mil vezes.
- **Compilador** = tradutor do livro: traduz tudo antes, gera "novo livro" (executável). Vantagem: execução rápida e independente do compilador. Desvantagem: etapa prévia obrigatória.

**Execução de um programa (cadeias):**

- Compilado: Código Fonte → Compilador → Ligador → Código Exec. → Montador → Assembly → CPU
- Interpretado: Código Fonte → Interpretador → Ligador → Montador → Assembly → CPU (sem executável persistido)
- Compilado multiplataforma: Código Fonte → Compilador → **Código Objeto** → Ligador → Montador → Assembly → CPU

**Transpilador (source-to-source compiler):** traduz código-fonte de uma linguagem de alto nível pra outra de nível parecido, mantendo lógica e funcionalidade. Usos: recursos novos em ambientes antigos (Babel: ES6+ → retrocompatível), migrar projetos legados, criar linguagens sobre sistemas prontos. **Nosso tradutor MineonScript → Python é um transpilador.**

**Pipeline de compilação (3 macro-etapas):**

```text
Alto nível → [TRADUÇÃO] → Código Objeto → [LIGAÇÃO] → Assembly → [MONTAGEM] → Linguagem de Máquina
```

- **Tradução:** Léxica → Sintática → Semântica (opcional) → Codificação
- **Ligação:** resolver referências externas → codificação
- **Montagem:** léxica → sintática → codificação

**4 fases clássicas da Tradução:**

| Fase | Nome | Faz |
|---|---|---|
| 1 | Análise Léxica (Leitor) | Transforma texto em **tokens** |
| 2 | Análise Sintática | Monta a árvore da estrutura → **AST (Árvore Sintática Abstrata)** |
| 3 | Análise Semântica (opcional) | Valida regras e variáveis |
| 4 | Codificação / Geração de Código | Escreve o arquivo final |

### Slide 3 — BNF (Backus–Naur Form)

Criado em **1959 por John Backus**, aprimorado em **1960 por Peter Naur**; nasceu para definir a sintaxe do **ALGOL 60**. Gramática formal sem ambiguidades.

**Notação:** cada linha = uma regra · `< >` = categoria (não-terminal) · `" "` = literal · `|` = "ou" · `{ }` = repetição.

**Gramática MineonScript do slide (resumo):** `<programa> ::= <instrucoes> <retorno>`; instruções = atribuição | saída (`print`) | entrada (`input`) | condicional (`se`/`senao` com `{ }`) | loop (`enquanto`); expressões em camadas `<expressao>` → `<termo>` → `<fator>` (precedência de `*` `/` sobre `+` `-`); `<condicao>` usa `==`, `<`, `>` e `!`; `<retorno> ::= "retorna" <numero>`. O slide também mostra o início do LEXER em Python (`re` + lista `TOKENS_FONTE` de pares nome/regex).

**Exercício resolvido:** BNF da calculadora KK-102 → [Aula03/Exercicio BNF KK-102.md](Aula03/Exercicio%20BNF%20KK-102.md) (versão com precedência embutida na gramática, melhor que a proposta do slide, que deixa `<operacao_binaria>` ambígua).

### Slide 1 — Fundamentos (SI, dados, fluxogramas)

**Sistema de Informação (SI):** Hardware (CPU, memórias, E/S) → Dados → Software (aplicativos, utilitários, SO, ling. programação) → Processos → Peopleware (operadores, técnicos, administradores) → Rede.

**Dado vs Informação:** dado = símbolo isolado sem contexto (`a`, `1`, `Km`, `80`); informação = dado com contexto ("80 km/h na placa"). Cadeia da IA: **Dado → Informação → Inteligência → Conhecimento**. Computacional: bit ≅ dado; byte/word ≅ informação. Word = tamanho da palavra do sistema (8, 16, 32, 64 bits...).

**SIC (Sistema de Informação Computacional):** Central de processamento = CPU (registradores + cache) ↔ B.P. ↔ RAM, buffers de E/S, M.S. (memória secundária). Unidades: Hz, bps, B/s.

**Memórias:** Primárias (registradores, caches, buffers, RAM, ROM/BIOS) · Secundárias (HD, SSD) · Terciárias/backup (DVD, cartões).

**CPU vs FPU:** FPU = coprocessador de ponto flutuante (i387/i487 históricos; hoje integrado no core: ALU + FPU + RegFile + cache).

**Sistemas numéricos:** DEC ↔ BIN ↔ HEX. Conversão: posicional (soma de pesos) pra decimal; divisões sucessivas (resto) pra sair do decimal. Ex: 63₁₀ = 00111111₂ = 3F₁₆. ASCII = tabela dec/hex/char. Paradigma SIC: hardware↔binário, software↔hexadecimal, peopleware↔decimal. Base64 pra 64b+.

**Velocidade e taxas:**

```
volume = velocidade × tempo
velocidade = volume / tempo
tempo = volume / velocidade
1 MB/s ≈ 8 Mbps
```

Taxa de transmissão ≠ taxa de recebimento dessincronizadas = bug → solução: **bufferização** (buffer de saída/entrada entre dispositivos). Gargalo: o destino precisa de taxa de armazenamento ≥ taxa de recebimento. Ex. praticado: pacote de 20KB a 8B/s.

**Software:** Básicos (BIOS, interpretadores, **compiladores**, drivers, SO) · SO (interface usuário↔máquina, gerencia recursos) · Aplicativos (programas de usuário) · Utilitários (suprem deficiências do SO). Classificação: proprietário, gratuito, open source, livre (GPL).

**Redes:** Simplex / Half-Duplex / Full-Duplex · Topologia ponto-a-ponto e barramento · Modem, Hub/Switch, Roteador · LAN / MAN / WAN.

**Eng. de Software:** áreas (requisitos, projeto, construção, teste, manutenção, configuração, qualidade) · Ciclos de vida: cascata, espiral, iterativo/incremental.

**Fluxogramas:** símbolos — oval (início/fim), retângulo (processo), losango (decisão), paralelogramo (entrada), "documento" (saída), seta (fluxo), barra (paralelismo). Dica do professor: rascunhar o algoritmo linha a linha ANTES de desenhar; é permitido usar termos como "lista de números", "obtenha um número aleatório".

## Anexo B — Bibliografia

- AHO, LAM, SETHI, ULLMAN. **Compiladores: Princípios, Técnicas e Ferramentas** (Dragon Book), 2.ed, 2008.
- PRICE. Implementação de Linguagens de Programação: compiladores, 3.ed, 2005.
- JOSÉ NETO. Introdução à Compilação, 2.ed, 2016.
- Complementar: MENEZES (Linguagens Formais e Autômatos), SIPSER (Teoria da Computação), GRUNE (Projeto Moderno de Compiladores), RICARTE.
