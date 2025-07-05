# Problema N - Números Balanceados

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]Em um número inteiro, podemos definir um par correspondente como dois dígitos iguais que encontram-se um exatamente ao lado do outro (ou vizinho). [cite: 350] [cite_start]Dizemos que um número é balanceado se, após remover um par correspondente, existe sempre um outro par correspondente nos seus dígitos constituintes restantes ou caso ele deixe de ser um número inteiro (quando ele perde todos os seus dígitos). [cite: 351] [cite_start]Por outro lado, dizemos que o número não é balanceado se não conseguimos remover um par correspondente dele ou do resultado da remoção de um par correspondente dele. [cite: 352]

[cite_start]Dado um número inteiro, determine se ele é balanceado ou não. [cite: 353]

## Entrada

[cite_start]A entrada é descrita por uma única linha contendo uma string $s$ composta apenas por $n$ dígitos numéricos $(1 \le n \le 100)$, em que $n$ é par. [cite: 355]

## Saída

[cite_start]Imprima "sim" (sem aspas duplas) se o número de entrada for balanceado, ou imprima "nao" (sem aspas duplas) caso contrário. [cite: 357, 358]

## Exemplo

| Entrada      | Saída |
| :----------- | :---- |
| [cite_start]1221 [cite: 360]     [cite_start]| sim [cite: 360] |
| [cite_start]1234 [cite: 360]     [cite_start]| nao [cite: 360] |
| [cite_start]22224444 [cite: 360] [cite_start]| sim [cite: 360] |