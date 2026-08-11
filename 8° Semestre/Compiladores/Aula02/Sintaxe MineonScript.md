# Exercício — MineonScript

Sintaxe base da linguagem (proposta inicial):

```
declarar a, b, r
a = 2
b = -1
r = 2 * a + b
mostrar "Resultado: "
mostrar r
```

## Como resolver a entrada de dados e a aleatoriedade numérica?

A sintaxe inicial não possui entrada de dados nem números aleatórios.
Proposta de extensão da linguagem com duas novas palavras reservadas:

| Palavra    | Função                                                        |
|------------|---------------------------------------------------------------|
| `ler`      | Lê um valor digitado pelo usuário e guarda na variável        |
| `aleatorio`| Gera um número aleatório e guarda na variável                 |
| `se` / `entao` / `fim` | Estrutura condicional (necessária no exercício B) |

---


## Símbolos e palavras reservadas da linguagem

**Palavras reservadas:** `declarar`, `mostrar`, `ler`, `aleatorio`, `se`, `entao`, `fim`

**Símbolos:** `=` (atribuição), `+`, `-`, `*`, `/` (operadores aritméticos), `>`, `<` (comparação), `,` (separador de variáveis), `" "` (delimitador de texto)
