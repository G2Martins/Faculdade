# Compiladores – P2 – Simulado 3

**Fonte:** [Compiladores - P2 - Simulado 3.pdf](Compiladores%20-%20P2%20-%20Simulado%203.pdf) · transcrição fiel, com gabarito do próprio simulado.

Simulado preparatório para a P2, no mesmo formato da prova: 16 questões valendo 0,50 ponto cada, totalizando 8,00 pontos.

**Conteúdo:** Material 6 (Geração de Código), questões 1 a 6; Material 7 (CST), questões 7 a 16.

> **Verificação (2026-11-14):** Q8, Q10, Q13, Q14, Q15 e Q16 foram reconferidas rodando o código do [Material 7](../Aula07/Compiladores%20-%20Material%207%20-%20CST%20%28c%C3%B3digo%29.md) — contagens e árvores batem com o gabarito. As questões do Material 6 (Q1–Q6) seguem o gabarito do simulado ("conferido executando o transpilador"); o repositório não tem o código completo do transpilador do Material 6 para reconferir.

---

## Questões

### Questão 1 (0,50)

Analise as afirmações sobre o transpilador MineonScript do Material 6:

- I. O lexer descarta espaços e comentários.
- II. A AST guarda os parênteses da expressão como nós próprios.
- III. O gerador traduz `retorna 0` para `exit(0)`.

Estão CORRETAS somente as afirmações:

- A. Apenas a I.
- B. I e II.
- C. II e III.
- D. I e III.
- E. I, II e III.

### Questão 2 (0,50)

Qual é a sequência de tokens produzida pelo lexer do Material 6 para a instrução abaixo?

```text
escreva(n + 1)
```

- A. ESCREVA, ABRE_PAR, NOME, ESPACO, SOMA, ESPACO, NUMERO, FECHA_PAR.
- B. ESCREVA, ABRE_PAR, NOME, SOMA, NUMERO, FECHA_PAR.
- C. ESCREVA, ABRE_PAR, IDENTIFICADOR, SOMA, NUMERO, FECHA_PAR.
- D. SAIDA, EXPRESSAO, NOME, NUMERO.
- E. ESCREVA, TEXTO, FECHA_PAR.

### Questão 3 (0,50)

Considere o programa MineonScript abaixo:

```text
n = 3
enquanto ! n == 0 {
    n = n - 1
}
retorna 0
```

Qual é a linha do laço no Python gerado?

- A. `while ! n == 0:`
- B. `while not n == 0 {`
- C. `while (n != 0):`
- D. `while n == 0:`
- E. `while not (n == 0):`

### Questão 4 (0,50)

O gerador sempre envolve uma EXPRESSAO em parênteses, como na tradução de `x = 2 + 3 * 4` para `x = (2 + (3 * 4))`.

Qual é a consequência dessa escolha?

- A. A precedência representada pela forma da AST é preservada no Python, mesmo que alguns parênteses fiquem redundantes.
- B. O Python passa a calcular as somas antes das multiplicações.
- C. O código gerado fica mais rápido na execução.
- D. Os parênteses são exigidos pela sintaxe do Python em toda atribuição.
- E. A expressão é calculada já na transpilação, e o Python recebe só o resultado.

### Questão 5 (0,50)

Sobre a comunicação entre as etapas do transpilador MineonScript, o que o parser recebe e o que ele devolve?

- A. Recebe o código-fonte como texto e devolve a lista de tokens.
- B. Recebe a AST e devolve o código Python.
- C. Recebe a lista de tuplas (TIPO, VALOR) do lexer e devolve a raiz da AST, um NoAST do tipo PROGRAMA.
- D. Recebe o código Python e devolve a CST.
- E. Recebe a lista de tokens e devolve o código Python, sem árvore intermediária.

### Questão 6 (0,50)

Um aluno esqueceu a linha final `retorna 0` no programa abaixo:

```text
x = 1
escreva(x)
```

O que acontece ao transpilá-lo?

- A. O código é traduzido normalmente, apenas sem o `exit(0)`.
- B. O lexer acusa erro, pois o arquivo termina sem o token RETORNO.
- C. O gerador insere `exit(0)` automaticamente.
- D. O parser acusa erro sintático, pois a gramática exige `<programa> ::= <instrucoes> <retorno>` e encontra o fim do arquivo.
- E. O erro só aparece ao executar o Python gerado.

### Questão 7 (0,50)

Identifique cada item como VERDADEIRO (V) ou FALSO (F):

- ( ) A CST também é chamada de árvore de derivação (*parse tree*).
- ( ) A AST de uma instrução tem sempre mais nós que a CST.
- ( ) Os nós de passagem, como `<termo>` com um único filho, existem na CST e somem na AST.
- ( ) A AST é a estrutura usada pelo gerador de código.

Escolha a alternativa que representa a sequência correta:

- A. V - V - V - V.
- B. V - F - F - V.
- C. F - F - V - V.
- D. V - V - F - V.
- E. V - F - V - V.

### Questão 8 (0,50)

Considere a instrução abaixo:

```text
x = (7)
```

Quantos nós têm, respectivamente, a CST e a AST dessa instrução?

- A. 11 e 3.
- B. 13 e 3.
- C. 13 e 5.
- D. 3 e 13.
- E. 9 e 3.

### Questão 9 (0,50)

Na conversão CST → AST, quando um nó `<termo>` da CST dá origem a um nó EXPRESSAO na AST?

- A. Quando tem mais de um filho, isto é, quando contém um operador MUL ou DIV entre fatores.
- B. Sempre: todo `<termo>` vira um nó EXPRESSAO.
- C. Nunca: apenas `<expressao>` vira EXPRESSAO.
- D. Quando o seu único filho é um `<fator>` com número.
- E. Quando aparece dentro de parênteses.

### Questão 10 (0,50)

Considere a instrução abaixo, com três espaços antes do 5 e um comentário ao final:

```text
x =   5 // cinco
```

Pela regra do prefixo usada no lexer da CST, onde ficam guardados esses espaços e o comentário?

- A. Ambos ficam no prefixo do token IGUAL.
- B. Ambos são descartados, como no Material 6.
- C. Os espaços ficam no prefixo do token NUMERO "5"; o comentário, no prefixo do token de fim de arquivo (EOF).
- D. Os espaços viram um nó ESPACO e o comentário, um nó COMENTARIO na CST.
- E. Ambos ficam guardados no nó ATRIBUICAO da AST.

### Questão 11 (0,50)

Uma ferramenta de refatoração baseada na CST vai renomear a variável `x` para `valor` em um programa com comentários e indentação própria.

O que a ferramenta altera?

- A. Todas as folhas da CST, que são reescritas com formatação padronizada.
- B. A AST, que depois é convertida de volta em texto com os comentários.
- C. Apenas o primeiro `x` encontrado.
- D. Os comentários que citam `x`, mas não o código.
- E. Apenas as folhas NOME com texto `x`; o restante, inclusive comentários, fica idêntico.

### Questão 12 (0,50)

Sobre o ANTLR, é correto afirmar:

- A. Foi criado nos laboratórios Bell no início dos anos 1970 e gera apenas código em C.
- B. Foi criado por Terence Parr e gera parsers em várias linguagens-alvo, como Java, Python e C#.
- C. É um sistema operacional derivado do Linux.
- D. É o sucessor livre e compatível do GNU Bison.
- E. É um transpilador de JavaScript moderno para JavaScript antigo.

### Questão 13 (0,50)

Desenhe a árvore AST gerada a partir da instrução abaixo:

```text
saldo = saldo - taxa * 2
```

### Questão 14 (0,50)

Qual instrução originou a árvore AST abaixo?

```text
[SAIDA]
  [EXPRESSAO: -]
    [EXPRESSAO: *]
      [IDENTIFICADOR: a]
      [EXPRESSAO: +]
        [IDENTIFICADOR: b]
        [IDENTIFICADOR: c]
    [IDENTIFICADOR: d]
```

### Questão 15 (0,50)

Desenhe a árvore CST gerada a partir da instrução abaixo:

```text
soma = x + 10
```

### Questão 16 (0,50)

Transcreva a instrução a partir da árvore CST abaixo:

```text
<instrucao>
└── <saida>
    ├── ESCREVA "escreva"
    ├── ABRE_PAR "("
    ├── <expressao>
    │   └── <termo>
    │       ├── <fator>
    │       │   └── NUMERO "2"
    │       ├── MUL "*"
    │       └── <fator>
    │           ├── ABRE_PAR "("
    │           ├── <expressao>
    │           │   ├── <termo>
    │           │   │   └── <fator>
    │           │   │       └── NOME "n"
    │           │   ├── SUB "-"
    │           │   └── <termo>
    │           │       └── <fator>
    │           │           └── NUMERO "1"
    │           └── FECHA_PAR ")"
    └── FECHA_PAR ")"
```

---

## Gabarito

| Questão | Resposta | Material | Explicação resumida |
|---|---|---|---|
| 1 | **D** | 6 | II é falsa: os parênteses não viram nós; a precedência fica na forma da árvore. |
| 2 | **B** | 6 | Espaços são descartados; IDENTIFICADOR e SAIDA são tipos de nó da AST, não de token. Conferido executando o lexer. |
| 3 | **E** | 6 | CONDICAO com valor `"!"` gera `not (...)`, e o LOOP vira `while`. Conferido executando o transpilador. |
| 4 | **A** | 6 | Trecho da EXPRESSAO: `return f"({esq} {no.valor} {dir})"`. |
| 5 | **C** | 6 | Ordem: `lexer(codigo)` → tokens; `Parser(tokens).parse_programa()` → AST; `transpilador_python(ast)` → Python. |
| 6 | **D** | 6 | Mensagem: `Esperado 'RETORNO', mas encontrado 'EOF'`. Conferido executando o transpilador. |
| 7 | **E** | 7 | Apenas o 2º item é falso: a AST é menor que a CST. |
| 8 | **B** | 7 | Os parênteses abrem uma segunda cadeia `<expressao>` → `<termo>` → `<fator>` na CST (13 nós); na AST restam [ATRIBUICAO], [IDENTIFICADOR x] e [NUMERO 7]. Conferido no programa. |
| 9 | **A** | 7 | Um `<termo>` com um único filho apenas o repassa (cadeia unitária); com operador, vira [EXPRESSAO \* ou /]. |
| 10 | **C** | 7 | Espaços e comentários vão para o prefixo do token SEGUINTE; depois do comentário só existe o EOF. |
| 11 | **E** | 7 | É o exemplo da aba Refatoração do laboratório: só as folhas NOME "x" mudam. |
| 12 | **B** | 7 | A alternativa sobre os laboratórios Bell descreve o YACC; o sucessor livre do YACC é o Bison; o transpilador de JavaScript é o Babel. |
| 13 | Árvore | 7 | Abaixo. AST com 7 nós (a CST teria 15). |
| 14 | Instrução | 7 | Abaixo. |
| 15 | Árvore | 7 | Abaixo. CST com 12 nós. |
| 16 | Instrução | 7 | Abaixo. Leia as folhas da esquerda para a direita. |

> **Nota nossa à Q10 (conferida no programa):** a resposta C vale para a instrução **isolada**, como o enunciado apresenta — depois do comentário não há outro token, então ele cai no EOF. Num **programa completo** (com `retorna 0` na linha de baixo), o comentário e a quebra de linha vão para o prefixo do token `RETORNO`, que é o "token seguinte". A regra é sempre a mesma: **prefixo do próximo token real**; o EOF só recebe o que sobra no fim do arquivo.

### Q13 — resposta

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: saldo]
  [EXPRESSAO: -]
    [IDENTIFICADOR: saldo]
    [EXPRESSAO: *]
      [IDENTIFICADOR: taxa]
      [NUMERO: 2]
```

### Q14 — resposta

```text
escreva(a * (b + c) - d)
```

A soma está mais funda que a multiplicação; por isso `(b + c)` precisa de parênteses. A subtração de `d` fica no topo.

### Q15 — resposta

```text
<instrucao>
└── <atribuicao>
    ├── NOME "soma"
    ├── IGUAL "="
    └── <expressao>
        ├── <termo>
        │   └── <fator>
        │       └── NOME "x"
        ├── SOMA "+"
        └── <termo>
            └── <fator>
                └── NUMERO "10"
```

### Q16 — resposta

```text
escreva(2 * (n - 1))
```
