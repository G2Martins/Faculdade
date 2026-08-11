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

**Palavras reservadas:** `declarar`, `mostrar`, `ler`, `aleatorio`, `se`, `entao`, `senao`, `fim`, `enquanto`, `faca`

**Símbolos:** `=` (atribuição), `+`, `-`, `*`, `/` (operadores aritméticos), `>`, `<`, `==`, `>=`, `<=` (comparação), `,` (separador de variáveis), `" "` (delimitador de texto), `( )` (agrupamento), `[ ]` (lista)

**Extensões posteriores** (Aula01/Aula03): `senao` (condicional completa), `enquanto ... faca ... fim` (laço), listas com `tamanho(l)`, `contem(l, x)`, `remover_primeiro(l, x)`. Propostas pendentes: `!=`, `cancelar`.
