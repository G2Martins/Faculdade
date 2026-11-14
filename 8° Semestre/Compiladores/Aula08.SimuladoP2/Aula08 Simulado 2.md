# Compiladores – P2 – Simulado 2

**Fonte:** [Compiladores - P2 - Simulado 2.pdf](Compiladores%20-%20P2%20-%20Simulado%202.pdf) · transcrição fiel, com gabarito do próprio simulado.

Simulado preparatório para a P2, no mesmo formato da prova: 16 questões valendo 0,50 ponto cada, totalizando 8,00 pontos.

**Conteúdo:** Material 6 (Geração de Código), questões 1 a 6; Material 7 (CST), questões 7 a 16.

> **Verificação (2026-11-14):** Q7, Q8, Q10, Q13, Q14, Q15 e Q16 foram reconferidas rodando o código do [Material 7](../Aula07/Compiladores%20-%20Material%207%20-%20CST%20%28c%C3%B3digo%29.md) — contagens e árvores batem com o gabarito. As questões do Material 6 (Q1–Q6) seguem o gabarito do simulado ("conferido executando o transpilador"); o repositório não tem o código completo do transpilador do Material 6 para reconferir.

---

## Questões

### Questão 1 (0,50)

Um aluno digitou, por engano, o programa abaixo:

```text
x = 2 @ 3
retorna 0
```

Em qual etapa o transpilador MineonScript interrompe a tradução?

- A. No lexer, com a mensagem de caractere inesperado, pois nenhum padrão de token reconhece `@`.
- B. No parser, porque `@` não é um operador previsto na gramática.
- C. No gerador, porque não existe tradução de `@` para Python.
- D. Somente ao executar o Python gerado.
- E. Na análise semântica, que verifica os operadores válidos.

### Questão 2 (0,50)

Considere o programa abaixo:

```text
escreva(x + )
retorna 0
```

O que acontece ao transpilá-lo?

- A. O lexer acusa erro, pois não reconhece o caractere `)`.
- B. A tradução funciona e gera `print((x + ))`.
- C. O gerador completa a expressão com zero, gerando `print((x + 0))`.
- D. A tradução funciona; o erro só aparece ao executar o Python.
- E. O parser acusa erro: depois do `+` a gramática exige um `<termo>`, mas encontra FECHA_PAR.

### Questão 3 (0,50)

Considere o programa MineonScript abaixo:

```text
i = 0
enquanto i < 10 {
    se i > 5 {
        escreva(i)
    }
    i = i + 1
}
retorna 0
```

No Python gerado, com quantos espaços de recuo aparece a linha `print(i)`?

- A. 4.
- B. 8.
- C. 0.
- D. 12.
- E. 2.

### Questão 4 (0,50)

Lembre que o gerador envolve toda EXPRESSAO em parênteses e que o parser coloca a multiplicação mais fundo que a soma.

Qual linha Python é gerada para a instrução abaixo?

```text
r = a * b + c * d
```

- A. `r = a * b + c * d`
- B. `r = (a * (b + c) * d)`
- C. `r = (((a * b) + c) * d)`
- D. `r = ((a * b) + (c * d))`
- E. `r = (a * b) + (c * d)`

### Questão 5 (0,50)

O programa abaixo é transpilado sem nenhuma mensagem de erro:

```text
escreva(total)
retorna 0
```

Ao executar o Python gerado, ocorre `NameError`. Qual alternativa explica a situação?

- A. O lexer deveria ter rejeitado `total`, pois não é palavra reservada.
- B. O parser deveria ter rejeitado `escreva` sem uma atribuição antes.
- C. O MineonScript não tem análise semântica: ninguém verifica se `total` recebeu valor antes de ser usado, e o erro só aparece na execução.
- D. O gerador traduziu `escreva` para a função errada.
- E. O `exit(0)` é executado antes do `print`.

### Questão 6 (0,50)

Transpiladores traduzem entre linguagens de alto nível.

Qual das ferramentas abaixo é um exemplo de transpilador?

- A. GCC, quando gera código de máquina a partir de C.
- B. Babel, que converte JavaScript moderno (ES2015+) em versões mais antigas da linguagem.
- C. O interpretador CPython executando um script.
- D. Um montador (assembler) convertendo Assembly em código de máquina.
- E. Um linker juntando arquivos objeto em um executável.

### Questão 7 (0,50)

Considere a instrução `x = 5`, que não tem nenhuma multiplicação nem parênteses.

Por que a CST dessa instrução contém os nós `<termo>` e `<fator>`?

- A. Porque o lexer cria esses nós para cada número encontrado.
- B. Porque o parser sempre supõe que haverá uma multiplicação.
- C. Porque a AST precisa deles para gerar o código Python.
- D. Porque são nós de erro inseridos quando a expressão é simples demais.
- E. Porque a CST registra cada regra da gramática aplicada, inclusive as de passagem com um único filho (`<expressao>` → `<termo>` → `<fator>` → NUMERO).

### Questão 8 (0,50)

Considere a instrução abaixo:

```text
escreva(k)
```

Quantos nós têm, respectivamente, a CST e a AST dessa instrução?

- A. 9 e 2.
- B. 9 e 3.
- C. 7 e 2.
- D. 2 e 9.
- E. 8 e 2.

### Questão 9 (0,50)

Considere a instrução abaixo, com espaços extras e um comentário:

```text
x  =  2*(3+4)   // dobro
```

Se tentássemos reconstruir o texto original percorrendo apenas a AST, o que se perderia?

- A. Apenas o comentário; os espaços ficam na AST.
- B. Apenas os números, que viram tipos na AST.
- C. Os espaços extras, o comentário e os parênteses, pois a AST não guarda prefixos nem pontuação.
- D. Nada: a AST também é sem perdas.
- E. O nome da variável `x`, que some na AST.

### Questão 10 (0,50)

A conversão para AST agrupa operadores de mesma precedência da esquerda para a direita (dobra à esquerda).

```text
q = 100 / 10 / 5
escreva(q)
retorna 0
```

Após transpilar e executar o Python gerado, qual valor é exibido?

- A. 50.0
- B. 0.5
- C. 20.0
- D. 2.0
- E. Nada: ocorre `ZeroDivisionError`.

### Questão 11 (0,50)

No Material 7, LibCST (Python) e Roslyn (C#) aparecem como exemplos de uso da CST.

Para que tipo de ferramenta elas são usadas?

- A. Interpretadores que executam o código diretamente da AST.
- B. Ferramentas de refatoração e transformação de código que precisam preservar formatação e comentários.
- C. Geradores de código de máquina para processadores x86.
- D. Analisadores léxicos que descartam espaços e comentários.
- E. Sistemas de controle de versão, como o Git.

### Questão 12 (0,50)

Sobre os geradores de parser YACC e GNU Bison, é correto afirmar:

- A. O YACC foi criado no ambiente Unix, e o GNU Bison é seu sucessor livre e compatível.
- B. O YACC é um sucessor do Bison, criado para o Windows.
- C. Ambos são transpiladores de JavaScript.
- D. Ambos geram apenas a AST e nunca a árvore de derivação.
- E. O Bison é uma biblioteca de refatoração baseada em CST.

### Questão 13 (0,50)

Desenhe a árvore AST gerada a partir da instrução abaixo:

```text
area = base * altura / 2
```

### Questão 14 (0,50)

Qual instrução originou a árvore AST abaixo?

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: d]
  [EXPRESSAO: -]
    [IDENTIFICADOR: a]
    [EXPRESSAO: -]
      [IDENTIFICADOR: b]
      [IDENTIFICADOR: c]
```

### Questão 15 (0,50)

Desenhe a árvore CST gerada a partir da instrução abaixo:

```text
escreva(n * 2)
```

### Questão 16 (0,50)

Transcreva a instrução a partir da árvore CST abaixo:

```text
<instrucao>
└── <atribuicao>
    ├── NOME "w"
    ├── IGUAL "="
    └── <expressao>
        └── <termo>
            ├── <fator>
            │   ├── ABRE_PAR "("
            │   ├── <expressao>
            │   │   ├── <termo>
            │   │   │   └── <fator>
            │   │   │       └── NOME "p"
            │   │   ├── SOMA "+"
            │   │   └── <termo>
            │   │       └── <fator>
            │   │           └── NOME "q"
            │   └── FECHA_PAR ")"
            ├── DIV "/"
            └── <fator>
                └── NOME "r"
```

---

## Gabarito

| Questão | Resposta | Material | Explicação resumida |
|---|---|---|---|
| 1 | **A** | 6 | Erro léxico: `Caractere inesperado: '@' na posição 6`. Conferido executando o transpilador. |
| 2 | **E** | 6 | Erro sintático: `Fator inesperado com token 'FECHA_PAR'`. Os tokens existem; a sequência é que não obedece à gramática. Conferido executando. |
| 3 | **B** | 6 | `print(i)` está dentro do `if`, que está dentro do `while`: `nivel_indentacao = 2`, e cada nível vale 4 espaços. Conferido executando. |
| 4 | **D** | 6 | AST: `[EXPRESSAO +]` com filhos `[EXPRESSAO *](a, b)` e `[EXPRESSAO *](c, d)`. Conferido executando o transpilador. |
| 5 | **C** | 6 | Léxica e sintaticamente o programa é válido; a falta de declaração é um problema semântico, verificado apenas pelo Python em tempo de execução. |
| 6 | **B** | 6 | Babel traduz JavaScript para JavaScript (alto nível para alto nível), como o MineonScript para Python. |
| 7 | **E** | 7 | Cadeias unitárias: a CST de `x = 5` tem 8 nós e a AST, 3. Conferido no programa. |
| 8 | **A** | 7 | CST: `<instrucao>`, `<saida>`, ESCREVA, ABRE_PAR, `<expressao>`, `<termo>`, `<fator>`, NOME k, FECHA_PAR. AST: [SAIDA] e [IDENTIFICADOR k]. Conferido no programa. |
| 9 | **C** | 7 | Só a CST é sem perdas: suas folhas, com os prefixos, devolvem o texto caractere por caractere. |
| 10 | **D** | 7 | Gera `q = ((100 / 10) / 5)` = 2.0 (a divisão `/` do Python devolve float). Agrupar pela direita daria `100 / (10 / 5)` = 50.0. Conferido executando. |
| 11 | **B** | 7 | Slide "Onde cada uma é usada": refatoração (LibCST, Roslyn) usa CST. |
| 12 | **A** | 7 | YACC (*Yet Another Compiler-Compiler*) nasceu no Unix; o Bison é seu sucessor livre e compatível. |
| 13 | Árvore | 7 | Abaixo. AST com 7 nós (a CST teria 14). |
| 14 | Instrução | 7 | Abaixo. |
| 15 | Árvore | 7 | Abaixo. CST com 12 nós. |
| 16 | Instrução | 7 | Abaixo. Leia as folhas da esquerda para a direita. |

### Q13 — resposta

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: area]
  [EXPRESSAO: /]
    [EXPRESSAO: *]
      [IDENTIFICADOR: base]
      [IDENTIFICADOR: altura]
    [NUMERO: 2]
```

### Q14 — resposta

```text
d = a - (b - c)
```

A subtração da direita está mais funda; sem parênteses, `a - b - c` seria agrupado pela esquerda e geraria outra árvore.

### Q15 — resposta

```text
<instrucao>
└── <saida>
    ├── ESCREVA "escreva"
    ├── ABRE_PAR "("
    ├── <expressao>
    │   └── <termo>
    │       ├── <fator>
    │       │   └── NOME "n"
    │       ├── MUL "*"
    │       └── <fator>
    │           └── NUMERO "2"
    └── FECHA_PAR ")"
```

### Q16 — resposta

```text
w = (p + q) / r
```
