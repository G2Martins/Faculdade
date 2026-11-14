# Compiladores – P2 – Simulado 1

**Fonte:** [Compiladores - P2 - Simulado 1.pdf](Compiladores%20-%20P2%20-%20Simulado%201.pdf) · transcrição fiel, com gabarito do próprio simulado.

Simulado preparatório para a P2, no mesmo formato da prova: 16 questões valendo 0,50 ponto cada, totalizando 8,00 pontos.

**Conteúdo:** Material 6 (Geração de Código), questões 1 a 6; Material 7 (CST), questões 7 a 16.

> **Verificação (2026-11-14):** Q8, Q10, Q13, Q14, Q15 e Q16 foram reconferidas rodando o código do [Material 7](../Aula07/Compiladores%20-%20Material%207%20-%20CST%20%28c%C3%B3digo%29.md) — contagens e árvores batem com o gabarito. As questões do Material 6 (Q1–Q6) seguem o gabarito do simulado ("conferido executando o transpilador"); o repositório não tem o código completo do transpilador do Material 6 para reconferir.

---

## Questões

### Questão 1 (0,50)

Sobre as etapas do transpilador MineonScript apresentadas no Material 6, analise as afirmações:

- I. O parser recebe a lista de tokens e devolve a AST.
- II. O transpilador MineonScript verifica se cada variável foi declarada antes de ser usada.
- III. O gerador percorre a AST recursivamente: para traduzir um nó, chama `transpilador_python` sobre os filhos dele.

Estão CORRETAS somente as afirmações:

- A. Apenas a I.
- B. Apenas a II.
- C. I e III.
- D. II e III.
- E. I, II e III.

### Questão 2 (0,50)

Considere o programa MineonScript abaixo:

```text
i = 0
enquanto i < 3 {
    escreva(i)
    i = i + 1
}
retorna 0
```

No código Python gerado pelo transpilador, quais são, respectivamente, a linha do laço e a linha do incremento?

- A. `while (i < 3):` e `    i = i + 1`, com quatro espaços de recuo.
- B. `while i < 3:` e `i = (i + 1)`, sem recuo.
- C. `while i < 3 {` e `    i = (i + 1)`, mantendo as chaves.
- D. `while i < 3:` e `    i = (i + 1)`, com quatro espaços de recuo.
- E. `for i in range(3):` e `    i += 1`.

### Questão 3 (0,50)

O gerador de código traduz cada tipo de nó da AST para uma construção Python.

Qual associação entre MineonScript e o Python gerado está INCORRETA?

- A. `escreva(x)` → `print(x)`
- B. `retorna 0` → `exit(0)`
- C. `senao` → `elif`
- D. `n = leia("Idade: ")` → `n = input("Idade: ")`
- E. `enquanto` → `while`

### Questão 4 (0,50)

Na gramática do MineonScript, a negação é escrita antes da condição, sem parênteses: `<condicao> ::= NEGACAO <condicao>`.

```text
x = 7
se ! x > 5 {
    escreva("pequeno")
}
retorna 0
```

Qual linha Python é gerada para o `se`?

- A. `if !x > 5:`
- B. `if not (x > 5):`
- C. `if not x > 5:`
- D. `if (x > 5) == False:`
- E. Nenhuma: o MineonScript não aceita `!` antes de uma condição.

### Questão 5 (0,50)

Um aluno documentou seu programa MineonScript com comentários `//` em várias linhas e, em seguida, o transpilou para Python.

O que acontece com esses comentários?

- A. Não aparecem no Python: o lexer descarta comentários e espaços, então eles nunca chegam à AST nem ao gerador.
- B. São convertidos em comentários Python iniciados por `#`.
- C. Viram strings dentro de chamadas `print`.
- D. Provocam um erro léxico, pois o lexer não reconhece `//`.
- E. São reunidos no topo do arquivo, logo após o cabeçalho gerado.

### Questão 6 (0,50)

Compiladores, transpiladores e interpretadores tratam o código-fonte de formas diferentes.

Qual alternativa descreve corretamente o transpilador?

- A. Traduz o programa diretamente para código de máquina ou Assembly.
- B. Executa o programa linha a linha, sem gerar código em outra linguagem.
- C. Junta vários arquivos objeto em um executável final.
- D. Converte código de máquina de volta para uma linguagem de alto nível.
- E. Traduz entre linguagens de alto nível, como o MineonScript para Python.

### Questão 7 (0,50)

O lexer usado na construção da CST (Material 7) é diferente do lexer do Material 6 em um ponto importante.

O que ele faz com espaços e comentários?

- A. Descarta-os, exatamente como o lexer do Material 6.
- B. Guarda-os no prefixo do token seguinte, para que a CST possa devolver o texto original.
- C. Transforma-os em nós ESPACO e COMENTARIO da AST.
- D. Gera um erro léxico quando encontra um comentário.
- E. Converte-os em tokens NOME.

### Questão 8 (0,50)

Considere a instrução abaixo:

```text
y = a * b
```

Quantos nós têm, respectivamente, a CST e a AST dessa instrução, conforme o programa da aula?

- A. 11 e 5.
- B. 5 e 11.
- C. 9 e 5.
- D. 11 e 7.
- E. 13 e 5.

### Questão 9 (0,50)

Considere a instrução `escreva(total)` e suas duas árvores. Analise as afirmações:

- I. Na CST, cada token vira uma folha, inclusive ESCREVA, ABRE_PAR e FECHA_PAR.
- II. Na AST, a palavra-chave `escreva` não aparece como folha: ela é representada pelo próprio tipo do nó SAIDA.
- III. Na AST, os parênteses viram nós filhos de SAIDA.

Estão CORRETAS somente as afirmações:

- A. Apenas a I.
- B. Apenas a III.
- C. II e III.
- D. I e II.
- E. I, II e III.

### Questão 10 (0,50)

Pela repetição EBNF `<expressao> ::= <termo> { ( SOMA | SUB ) <termo> }`, a conversão para AST agrupa os operadores da esquerda para a direita.

```text
z = 10 - 4 - 3
escreva(z)
retorna 0
```

Após transpilar e executar o Python gerado, qual valor é exibido?

- A. 9
- B. -3
- C. 17
- D. Nada: ocorre um erro de sintaxe no Python.
- E. 3

### Questão 11 (0,50)

Identifique cada item como VERDADEIRO (V) ou FALSO (F):

- ( ) Um formatador que padroniza a indentação sem perder comentários deve trabalhar sobre a CST.
- ( ) A função `transpilador_python` do Material 6 continua funcionando sem alterações quando recebe a AST construída a partir da CST.
- ( ) A AST guarda o prefixo de cada token e, por isso, também é sem perdas.
- ( ) Na CST de `x = 2 * (3 + 4)`, os parênteses aparecem como folhas dentro de um nó `<fator>`.

Escolha a alternativa que representa a sequência correta:

- A. V - V - V - V.
- B. V - F - F - V.
- C. V - V - F - V.
- D. F - V - F - V.
- E. V - V - F - F.

### Questão 12 (0,50)

Geradores de parser produzem o analisador sintático a partir de uma gramática.

Qual das ferramentas abaixo é um gerador de parser capaz de produzir analisadores em várias linguagens-alvo, como Java, Python e C#?

- A. ANTLR.
- B. Babel.
- C. LibCST.
- D. Roslyn.
- E. pip.

### Questão 13 (0,50)

Desenhe a árvore AST gerada a partir da instrução abaixo:

```text
total = preco * 3 + frete
```

### Questão 14 (0,50)

Qual instrução originou a árvore AST abaixo?

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: y]
  [EXPRESSAO: *]
    [EXPRESSAO: +]
      [IDENTIFICADOR: a]
      [IDENTIFICADOR: b]
    [IDENTIFICADOR: c]
```

### Questão 15 (0,50)

Desenhe a árvore CST gerada a partir da instrução abaixo:

```text
media = soma / 2
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
    │       │   └── NOME "x"
    │       ├── MUL "*"
    │       └── <fator>
    │           ├── ABRE_PAR "("
    │           ├── <expressao>
    │           │   ├── <termo>
    │           │   │   └── <fator>
    │           │   │       └── NOME "y"
    │           │   ├── SUB "-"
    │           │   └── <termo>
    │           │       └── <fator>
    │           │           └── NUMERO "2"
    │           └── FECHA_PAR ")"
    └── FECHA_PAR ")"
```

---

## Gabarito

| Questão | Resposta | Material | Explicação resumida |
|---|---|---|---|
| 1 | **C** | 6 | II é falsa: o MineonScript não tem análise semântica, então não verifica declaração de variáveis. |
| 2 | **D** | 6 | LOOP vira `while` sem parênteses na condição (CONDICAO não gera parênteses); o bloco ganha um nível de indentação e a EXPRESSAO `i + 1` vira `(i + 1)`. Conferido executando o transpilador. |
| 3 | **C** | 6 | O bloco `senao` é traduzido para `else`, e não para `elif` (ver o tratamento de CONDICIONAL com três filhos). |
| 4 | **B** | 6 | CONDICAO com valor `"!"` gera `not (...)`. Conferido executando o transpilador. |
| 5 | **A** | 6 | O padrão COMENTARIO (`//.*`) é reconhecido e descartado junto com ESPACO. A única linha `#` do Python é o cabeçalho fixo `# Código gerado via Transpilador MineonScript`. |
| 6 | **E** | 6 | Definição de transpilador (Material 6): tradução entre linguagens de alto nível. |
| 7 | **B** | 7 | Propriedade sem perdas (lossless) da CST: espaços e comentários ficam no atributo `prefixo` do token seguinte. |
| 8 | **A** | 7 | CST: `<instrucao>`, `<atribuicao>`, NOME y, IGUAL, `<expressao>`, `<termo>`, `<fator>`, NOME a, MUL, `<fator>`, NOME b. AST: [ATRIBUICAO], [IDENTIFICADOR y], [EXPRESSAO *], [IDENTIFICADOR a], [IDENTIFICADOR b]. Conferido no programa. |
| 9 | **D** | 7 | III é falsa: parênteses e pontuação somem na AST. |
| 10 | **E** | 7 | AST: `[EXPRESSAO -]([EXPRESSAO -](10, 4), 3)`, que gera `z = ((10 - 4) - 3)` = 3. Agrupar pela direita daria `10 - (4 - 3)` = 9. Conferido executando. |
| 11 | **C** | 7 | Apenas o 3º item é falso: a AST descarta tokens e prefixos; só a CST é sem perdas. |
| 12 | **A** | 7 | ANTLR (Terence Parr) gera parsers em várias linguagens. Babel é transpilador; LibCST e Roslyn usam CST para refatoração; pip instala pacotes Python. |
| 13 | Árvore | 7 | Abaixo. AST com 7 nós (a CST teria 15). |
| 14 | Instrução | 7 | Abaixo. |
| 15 | Árvore | 7 | Abaixo. CST com 11 nós. |
| 16 | Instrução | 7 | Abaixo. Leia as folhas da esquerda para a direita. |

### Q13 — resposta

```text
[ATRIBUICAO: =]
  [IDENTIFICADOR: total]
  [EXPRESSAO: +]
    [EXPRESSAO: *]
      [IDENTIFICADOR: preco]
      [NUMERO: 3]
    [IDENTIFICADOR: frete]
```

### Q14 — resposta

```text
y = (a + b) * c
```

A soma está mais funda que a multiplicação na árvore; por isso a instrução precisa dos parênteses em `(a + b)`.

### Q15 — resposta

```text
<instrucao>
└── <atribuicao>
    ├── NOME "media"
    ├── IGUAL "="
    └── <expressao>
        └── <termo>
            ├── <fator>
            │   └── NOME "soma"
            ├── DIV "/"
            └── <fator>
                └── NUMERO "2"
```

### Q16 — resposta

```text
escreva(x * (y - 2))
```
