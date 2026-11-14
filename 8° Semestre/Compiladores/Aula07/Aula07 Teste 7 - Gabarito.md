# Teste 7 — CST (Google Forms) — Gabarito

**Conteúdo:** [Material 7 — CST](Compiladores%20-%20Material%207%20-%20CST.pdf) · código em [Material 7 — CST (código)](Compiladores%20-%20Material%207%20-%20CST%20%28c%C3%B3digo%29.md) · 7 questões de 1 ponto · **Resultado: 7/7** ([gabarito oficial](Compiladores%20-%20Teste%207%20-%20CST%20-%20Gabarito.pdf)).

**Verificação:** a Q3 foi conferida rodando o código do Material 7 (`python cst_mineonscript.py -e "x = 2 * (3 + 4)"`) em 2026-11-14 — saída `CST: 20 nós | AST: 7 nós`. As demais saem do código e do texto do material, citados em cada explicação.

---

## Gabarito

| # | Questão | Resposta |
|---|---|---|
| 1 | No lexer da CST, o que acontece com espaços e comentários? | **Ficam guardados no "prefixo" do token seguinte** |
| 2 | O que é a CST (Árvore de Sintaxe Concreta)? | **A árvore que segue a gramática ao pé da letra: cada regra aplicada vira um nó e cada token vira uma folha** |
| 3 | Quantos nós têm, respectivamente, a CST e a AST de `x = 2 * (3 + 4)` no programa da aula? | **20 e 7** |
| 4 | Qual das aplicações abaixo precisa da CST e não se contenta com a AST? | **Uma ferramenta de refatoração que renomeia variáveis preservando comentários e formatação** |
| 5 | Na instrução `x = 2 * (3 + 4)`, o que acontece com os parênteses na AST? | **Desaparecem: a precedência já fica representada pela forma da árvore (o `+` fica mais fundo que o `*`)** |
| 6 | Por que se diz que a CST é "sem perdas" (lossless)? | **Porque, lendo suas folhas da esquerda para a direita (com espaços e comentários guardados), recupera-se o código-fonte original** |
| 7 | Sobre YACC, Bison e ANTLR, é correto afirmar: | **São geradores de parser: a partir da gramática, produzem um analisador que reconhece a entrada e pode montar a árvore de derivação** |

## Explicação por questão

**Q1 — prefixo, não descarte.** É a única diferença entre o lexer do Material 7 e o do Material 6. No código:

```python
if tipo in ("ESPACO", "COMENTARIO"):
    prefixo += texto          # acumula
else:
    tokens.append(Token(tipo, texto, prefixo))
    prefixo = ""              # entrega ao token "de verdade" e zera
...
tokens.append(Token("EOF", "", prefixo))  # o que sobrou no fim do arquivo
```

Distrator perigoso: *"São descartados, como a AST o faz"*. Quem descarta é o **lexer do Material 6** (o do transpilador), não "a AST" — e no lexer da CST nada é descartado. *"Viram nós ESPACO e COMENTARIO"* também é falso: espaço e comentário nunca viram nó, nem na CST nem na AST; viram **texto dentro do atributo `prefixo` de uma folha**.

**Q2 — definição de CST.** Também chamada **árvore de derivação** (*parse tree*). Cada método do `ParserCST` corresponde a uma regra da BNF e devolve um `NoCST` com **todos** os filhos — regras, palavras-chave, parênteses e chaves. A primeira alternativa (*"guarda apenas operadores e operandos, sem pontuação"*) é a definição da **AST**.

**Q3 — 20 e 7.** CST completa:

```text
<instrucao>
└── <atribuicao>
    ├── NOME "x"
    ├── IGUAL "="
    └── <expressao>
        └── <termo>
            ├── <fator>
            │   └── NUMERO "2"
            ├── MUL "*"
            └── <fator>
                ├── ABRE_PAR "("
                ├── <expressao>
                │   ├── <termo>
                │   │   └── <fator>
                │   │       └── NUMERO "3"
                │   ├── SOMA "+"
                │   └── <termo>
                │       └── <fator>
                │           └── NUMERO "4"
                └── FECHA_PAR ")"
```

- **9 folhas** = os 9 tokens (`x`, `=`, `2`, `*`, `(`, `3`, `+`, `4`, `)`).
- **11 nós internos** = `<instrucao>`, `<atribuicao>`, 2 × `<expressao>` (a principal + a dos parênteses), 3 × `<termo>`, 4 × `<fator>`.
- **Total 20.**

AST:

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: x]
  [EXPRESSAO: *]
    [NUMERO: 2]
    [EXPRESSAO: +]
      [NUMERO: 3]
      [NUMERO: 4]
```

**7 nós** = ATRIBUICAO + IDENTIFICADOR + 2 operadores + 3 operandos. O distrator *"9 e 9"* é o número de tokens; *"7 e 20"* é a resposta invertida.

**Q4 — refatoração.** O Material 7 implementa isso na função `renomear()` (flag `--renomear x valor`): troca só o texto das folhas `NOME` com o nome antigo e reescreve o arquivo pela CST — comentários e indentação ficam idênticos. Verificação de tipos, otimização de constantes, interpretação e geração de código trabalham sobre a **AST**, porque não precisam de espaço nem de comentário. É o mesmo papel de **LibCST** (Python) e **Roslyn** (C#).

**Q5 — parênteses somem.** Na conversão CST → AST:

```python
if no.rotulo == "<fator>":
    if len(f) == 3:              # ( <expressao> ): os parênteses somem
        return cst_para_ast(f[1])
```

A informação que o parêntese carregava ("faça a soma antes") passa a ser a **forma da árvore**: `[EXPRESSAO: +]` fica abaixo de `[EXPRESSAO: *]`, então é avaliada primeiro. Não existe nó `PARENTESES`, nem `ABRE_PAR`/`FECHA_PAR` na AST.

**Q6 — lossless.** A função `para_texto` concatena `prefixo + texto` de cada folha, da esquerda para a direita, e o programa principal confere: *"Sim, caractere por caractere."* Os distratores *"ocupa menos memória que a AST"* e *"remove os nós redundantes"* descrevem a **AST** (a CST é a maior das duas).

**Q7 — geradores de parser.** YACC (*Yet Another Compiler-Compiler*, Unix), GNU Bison (sucessor livre e compatível do YACC) e ANTLR (Terence Parr; gera parsers em Java, Python, C# e outras) recebem a gramática e produzem o analisador sintático. Não são editores, bibliotecas gráficas, linguagens nem sistemas operacionais.

## Para a P2

- **Lexer da CST guarda** espaço/comentário no **prefixo do token seguinte**; o que sobra no fim vai para o **EOF**. Lexer do Material 6 **descarta**.
- **CST** = gramática ao pé da letra, toda regra vira nó, todo token vira folha, **sem perdas**. **AST** = só operadores e operandos, sem pontuação, **com perdas**, é a que o gerador usa.
- **Contar nós da CST:** folhas = nº de tokens; internos = `<instrucao>` + `<atribuicao>`/`<saida>` + 1 `<expressao>` por expressão (principal + 1 por par de parênteses) + 1 `<termo>` por termo + 1 `<fator>` por operando (inclusive o `( … )`).
- **Contar nós da AST:** raiz (`ATRIBUICAO` + `IDENTIFICADOR`, ou só `SAIDA`) + 1 `EXPRESSAO` por operador + 1 nó por operando.
- **Parênteses na AST somem** — a precedência vira profundidade.
- **CST serve para** (quando o *texto* importa): formatadores (Black), realce de sintaxe e IDEs (Tree-sitter), refatoração sem perder comentários (LibCST, Roslyn), mensagens de erro com linha e coluna exatas. **AST serve para** (quando o *significado* importa): análise semântica, otimização (ex.: calcular `2 * 3` antes de rodar), geração de código, interpretadores (módulo `ast` do Python).
- **YACC / Bison / ANTLR** = geradores de parser.
