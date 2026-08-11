# CLAUDE.md — Compiladores (8° Semestre)

> Contexto da disciplina para o agente. Atualizar conforme novas aulas/exercícios.

## 1. Identificação

- **Curso:** 2130 — Ciência da Computação (IESB) · **Ano/Semestre:** 2026/2
- **Disciplina:** Compiladores · **CH:** 60h semestral
- **Professor:** Roger Rocha Ferreira · roger.ferreira@iesb.br
- **Material:** Google Sala de Aula (slides por encontro) + exercícios semanais pontuados

## 2. Ementa / Unidades

1. **Unidade I** — Introdução a compiladores e interpretadores
2. **Unidade II** — Análise léxica, sintática e semântica
3. **Unidade III** — Sínteses e código objeto (código intermediário, otimização, gerência de memória)
4. **Unidade IV** — Tradutor de códigos (projeto e implementação de um tradutor)

## 3. Avaliação (importante)

```
A1 = P1*0,8 + T1*0,2
A2 = P2*0,8 + T2*0,2
MF = A1*0,4 + A2*0,6          → aprovado se MF ≥ 5,0 e frequência ≥ 75%

P3 (substitutiva, se MF < 5,0):
MF = max{ P3*0,4 + A2*0,6 ; A1*0,4 + P3*0,6 }
```

Provas individuais sem consulta; conteúdo = ementa dada até a data da prova. Exercícios semanais contam na avaliação contínua.

## 4. Organização da pasta

Padrão: `AulaXX/Exercicio X.md` — um arquivo por exercício, código MineonScript em bloco ```.

- `Aula01/` — Exercicio B.md (notas/conceito) · Exercicio C.md (jogo adivinhação) · Exercicio D.md (máquina R$ 5,00 com loop) · Exercicio E.md (fila com prioridades)
- `Aula02/` — Sintaxe MineonScript.md · Exercicio A.md (3 produtos, soma+média) · Exercicio B.md (5 aleatórios, >10 e <20) · Fluxograma Tradutor Python.md (tradutor MineonScript→Python, Mermaid) · Questionario.md (gabarito comentado: fases da tradução, compilador vs interpretador)
- `Aula03/` — Exercicio C.md (máquina refrigerante R$ 4,50)

## 5. MineonScript (linguagem da disciplina)

Linguagem didática criada em aula. Base para o tradutor da Unidade IV.

**Sintaxe base (slide original):**

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

Extensões propostas por nós (documentadas nos arquivos): `ler` (entrada), `aleatorio` (random), `se/entao/senao/fim` (condicional), `enquanto ... faca ... fim` (laço), `==`/`>=`/`<=`, listas com funções `tamanho(l)`, `contem(l, x)`, `remover_primeiro(l, x)` (Exercicio E). Pendências identificadas: `!=` (Exercicio C), `cancelar` (Exercicio D).

**Tradução → Python** (ver `Aula02/Fluxograma Tradutor Python.md`): `mostrar`→`print`, `ler`→`float(input())`, `aleatorio`→`random.randint(0,100)`, `se/entao`→`if:`+indent, `fim`→dedent, `declarar`→inicializa com 0.

## 6. Conteúdo visto nos slides (base teórica)

### Slide 2 — Compiladores e Interpretadores (núcleo da disciplina)

**Objetivo:** diferenciar interpretar vs compilar; mapear como arquivo texto vira executável nas 4 fases clássicas.

**Compilação vs Interpretação (analogia do livro de receitas FR→PT):**

- **Intérprete** = tradutor simultâneo: lê linha, traduz, executa, segue. Vantagem: executa imediatamente. Desvantagem: laço de mil repetições traduz a mesma linha mil vezes.
- **Compilador** = tradutor do livro: traduz tudo antes, gera "novo livro" (executável). Vantagem: execução rápida e independente do compilador. Desvantagem: etapa prévia obrigatória.

**Execução de um programa (cadeias):**

- Compilado: Código Fonte → Compilador → Ligador → Código Exec. → Montador → Assembly → CPU
- Interpretado: Código Fonte → Interpretador → Ligador → Montador → Assembly → CPU (sem executável persistido)
- Compilado multiplataforma: Código Fonte → Compilador → **Código Objeto** → Ligador → Montador → Assembly → CPU

**Transpilador (source-to-source compiler):** traduz código-fonte de uma linguagem de alto nível pra outra de nível parecido, mantendo lógica/funcionalidade. Usos: recursos novos em ambientes antigos (Babel: ES6+ → retrocompatível), migrar projetos legados, criar linguagens sobre sistemas prontos. **Nosso tradutor MineonScript→Python é um transpilador.**

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

Taxa transmissão ≠ taxa recebimento dessincronizadas = bug → solução: **bufferização** (buffer de saída/entrada entre dispositivos). Gargalo: destino precisa taxa de armazenamento ≥ taxa de recebimento. Ex. praticado: pacote 20KB a 8B/s.

**Software:** Básicos (BIOS, interpretadores, **compiladores**, drivers, SO) · SO (interface usuário↔máquina, gerencia recursos) · Aplicativos (programas de usuário) · Utilitários (suprem deficiências do SO). Classificação: proprietário, gratuito, open source, livre (GPL).

**Redes:** Simplex / Half-Duplex / Full-Duplex · Topologia ponto-a-ponto e barramento · Modem, Hub/Switch, Roteador · LAN / MAN / WAN.

**Eng. de Software:** áreas (requisitos, projeto, construção, teste, manutenção, config, qualidade) · Ciclos de vida: cascata, espiral, iterativo/incremental.

**Fluxogramas:** símbolos — oval (início/fim), retângulo (processo), losango (decisão), paralelogramo (entrada), "documento" (saída), seta (fluxo), barra (paralelismo). Dica do professor: rascunhar algoritmo linha a linha ANTES de desenhar; permitido usar termos como "lista de números", "obtenha um número aleatório".

## 7. Inventário de exercícios

| Slide | Enunciado | Status |
|---|---|---|
| PB1 | 3 produtos → soma + média | ✅ `Aula02/Exercicio A.md` |
| PB2 | 5 aleatórios → exibir >10, depois <20 | ✅ `Aula02/Exercicio B.md` |
| Tradutor | Fluxograma MineonScript → Python + condicionalidade estrutural | ✅ `Aula02/Fluxograma Tradutor Python.md` |
| A | Máquina refrigerante R$ 4,50 (troco / igual / insuficiente) | ✅ `Aula03/Exercicio C.md` |
| B | Sistema de notas: 3 notas (0-10), média → Aprovado ≥7 / Recuperação 5-6.9 / Reprovado <5. Extra: validar notas inválidas | ✅ `Aula01/Exercicio B.md` |
| C | Jogo adivinhação 1-100: maior/menor/bem maior/bem menor/acertou ("memória curta") | ✅ `Aula01/Exercicio C.md` |
| D | Máquina refrigerante R$ 5,00 com loop: se insuficiente, aguarda inserção do restante. Extra: e se não tiver mais dinheiro? | ✅ `Aula01/Exercicio D.md` |
| E | Fila de banco com prioridades G > I > P > N, desempate por chegada. Entrada `[P,I,G,N,I]` → ordem de atendimento. Extra: evitar espera eterna do Normal | ✅ `Aula01/Exercicio E.md` |

Ao resolver exercício novo: criar `AulaXX/Exercicio X.md` no padrão existente, código em MineonScript, anotar extensões de sintaxe novas aqui e no `Aula02/Sintaxe MineonScript.md`.

## 8. Bibliografia principal

- AHO, LAM, SETHI, ULLMAN. **Compiladores: Princípios, Técnicas e Ferramentas** (Dragon Book), 2.ed, 2008.
- PRICE. Implementação de Linguagens de Programação: compiladores, 3.ed, 2005.
- JOSÉ NETO. Introdução à Compilação, 2.ed, 2016.
- Complementar: MENEZES (Linguagens Formais e Autômatos), SIPSER (Teoria da Computação), GRUNE (Projeto Moderno de Compiladores), RICARTE.
