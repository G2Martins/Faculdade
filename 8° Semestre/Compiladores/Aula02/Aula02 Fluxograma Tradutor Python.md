# Fluxograma — Tradutor MineonScript → Python

O tradutor lê o código-fonte MineonScript linha a linha, classifica cada comando pela palavra reservada inicial e emite a linha Python equivalente.

## Fluxograma

```mermaid
flowchart TD
    A([Início]) --> B[Abrir arquivo fonte MineonScript]
    B --> C{Ainda há linhas?}
    C -- Não --> Z([Fim — código Python gerado])
    C -- Sim --> D[Ler próxima linha]
    D --> E{Linha vazia?}
    E -- Sim --> C
    E -- Não --> F{Qual a palavra reservada?}

    F -- "declarar" --> G["Emitir: var1 = 0, var2 = 0, ...<br/>(inicializa cada variável com 0)"]
    F -- "ler" --> H["Emitir: var = float(input())"]
    F -- "aleatorio" --> I["Emitir: var = random.randint(0, 100)<br/>(garantir import random no topo)"]
    F -- "mostrar" --> J{Argumento é texto entre aspas?}
    J -- Sim --> K["Emitir: print(&quot;texto&quot;)"]
    J -- Não --> L["Emitir: print(var)"]
    F -- "se" --> M["Emitir: if condição:<br/>aumentar nível de indentação"]
    F -- "senao" --> N["Emitir: else:<br/>(mantém nível do if)"]
    F -- "fim" --> O["Reduzir nível de indentação<br/>(não emite linha)"]
    F -- "atribuição (var = expressão)" --> P["Emitir linha igual:<br/>var = expressão"]

    G --> C
    H --> C
    I --> C
    K --> C
    L --> C
    M --> C
    N --> C
    O --> C
    P --> C
```

## Tabela de tradução

| MineonScript | Python |
|---|---|
| `declarar a, b, r` | `a = 0` `b = 0` `r = 0` |
| `a = 2 * b + 1` | `a = 2 * b + 1` (idêntico) |
| `mostrar "texto"` | `print("texto")` |
| `mostrar r` | `print(r)` |
| `ler x` | `x = float(input())` |
| `aleatorio n` | `n = random.randint(0, 100)` |
| `se x > 10 entao` | `if x > 10:` |
| `senao` | `else:` |
| `fim` | (fecha bloco — volta indentação) |

## Condicionalidade estrutural da linguagem

MineonScript delimita blocos por palavras reservadas; Python delimita por indentação. O tradutor precisa manter um **contador de nível de indentação**:

```
se <condição> entao      →  if <condição>:      (nível +1)
    <comandos>           →      <comandos>       (indentados)
senao                    →  else:                (mesmo nível do if)
    <comandos>           →      <comandos>
fim                      →  (nada — nível -1)
```

- `se ... entao` abre o bloco e incrementa o nível;
- `senao` é opcional, fica no mesmo nível do `se`;
- `fim` fecha o bloco e decrementa o nível — todo `se` exige um `fim` (blocos aninhados empilham níveis).

### Exemplo completo (Exercício C traduzido)

MineonScript:

```
declarar preco, valor, troco
preco = 4.50
ler valor
se valor > preco entao
    troco = valor - preco
    mostrar "Troco: R$ "
    mostrar troco
fim
```

Python gerado:

```python
preco = 0
valor = 0
troco = 0
preco = 4.50
valor = float(input())
if valor > preco:
    troco = valor - preco
    print("Troco: R$ ")
    print(troco)
```
