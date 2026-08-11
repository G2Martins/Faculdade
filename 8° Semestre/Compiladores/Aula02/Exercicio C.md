# Exercício C — Máquina de refrigerante (preço R$ 4,50)

> Extensão da sintaxe: operador de comparação `==` (igualdade), necessário para o caso "valor igual".

```
declarar preco, valor, troco, falta

preco = 4.50

mostrar "Insira o dinheiro: "
ler valor

se valor > preco entao
    troco = valor - preco
    mostrar "Troco: R$ "
    mostrar troco
fim

se valor == preco entao
    mostrar "Beba com moderação!"
fim

se valor < preco entao
    falta = preco - valor
    mostrar "Dinheiro insuficiente! Faltam R$ "
    mostrar falta
fim
```
