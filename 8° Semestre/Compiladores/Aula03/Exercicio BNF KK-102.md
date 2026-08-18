# Exercício — BNF da calculadora KK-102

**Enunciado:** escrever a gramática BNF para a calculadora KK-102, com as operações: soma, subtração, multiplicação, divisão, exponenciação, raiz quadrada, média, área do retângulo, área do triângulo e área do círculo.

## Gramática

```bnf
<programa> ::= <expressao>

<expressao> ::= <termo>
              | <expressao> "+" <termo>
              | <expressao> "-" <termo>

<termo> ::= <potencia>
          | <termo> "*" <potencia>
          | <termo> "/" <potencia>

<potencia> ::= <fator>
             | <fator> "^" <potencia>

<fator> ::= <numero>
          | "(" <expressao> ")"
          | <funcao>

<funcao> ::= "raiz" "(" <expressao> ")"
           | "media" "(" <lista_numeros> ")"
           | "area_retangulo" "(" <expressao> "," <expressao> ")"
           | "area_triangulo" "(" <expressao> "," <expressao> ")"
           | "area_circulo" "(" <expressao> ")"

<lista_numeros> ::= <expressao>
                  | <expressao> "," <lista_numeros>

<numero> ::= <digitos>
           | <digitos> "." <digitos>

<digitos> ::= digito {digito}
```

## Decisões de projeto

1. **Precedência embutida na gramática** (diferente da proposta do slide, que é ambígua): `expressao` → `termo` → `potencia` → `fator` garante que `2 + 3 * 4` derive como `2 + (3 * 4)`, sem precisar de regras extras de desambiguação.
2. **Exponenciação associativa à direita:** `<fator> "^" <potencia>` faz `2 ^ 3 ^ 2` = `2 ^ (3 ^ 2)` = 512, convenção matemática padrão.
3. **`+`, `-`, `*`, `/` associativos à esquerda:** recursão à esquerda (`<expressao> "+" <termo>`), então `10 - 4 - 3` = `(10 - 4) - 3` = 3.
4. **Parênteses em `<fator>`** permitem quebrar a precedência: `(2 + 3) * 4`.
5. **`<numero>` aceita decimais** (`4.50`) — a KK-102 tem tecla `.` no teclado.
6. **Funções recebem `<expressao>` como argumento**, não só números: `raiz(2 + 2)` e `media(1, raiz(9), 2^2)` são sentenças válidas.

## Exemplos de sentenças válidas

```
2 + 3 * 4
(2 + 3) * 4
2 ^ 10
raiz(144)
media(7, 8.5, 9)
area_retangulo(3, 4)
area_triangulo(6, 2)
area_circulo(raiz(4))
area_retangulo(2 + 1, 10 / 2)
```

## Derivação de exemplo: `2 + 3 * 4`

```
<programa>
⇒ <expressao>
⇒ <expressao> "+" <termo>
⇒ <termo> "+" <termo>
⇒ <potencia> "+" <termo>
⇒ <fator> "+" <termo>
⇒ 2 "+" <termo>
⇒ 2 "+" <termo> "*" <potencia>
⇒ 2 "+" <potencia> "*" <potencia>
⇒ 2 "+" <fator> "*" <fator>
⇒ 2 "+" 3 "*" 4
```

A multiplicação fica agrupada dentro de `<termo>`, provando que a gramática resolve a precedência sozinha.
