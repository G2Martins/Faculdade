# Exercício D — Máquina de refrigerante R$ 5,00 (com espera do restante)

> Igual ao exercício da máquina de R$ 4,50, mas se o dinheiro for insuficiente a máquina informa quanto falta e **aguarda a inserção do restante** (laço `enquanto`).
> Extra do slide: se a pessoa não tem mais dinheiro, precisaria existir comando de cancelar/devolver — proposta: palavra `cancelar` que encerra e devolve `total` (a linguagem ainda não tem).

```
declarar preco, total, valor, troco, falta

preco = 5.00
total = 0

mostrar "Insira o dinheiro: "
ler valor
total = total + valor

enquanto total < preco faca
    falta = preco - total
    mostrar "Dinheiro insuficiente! Faltam R$ "
    mostrar falta
    mostrar "Insira o restante: "
    ler valor
    total = total + valor
fim

se total > preco entao
    troco = total - preco
    mostrar "Troco: R$ "
    mostrar troco
fim

se total == preco entao
    mostrar "Beba com moderação!"
fim
```
