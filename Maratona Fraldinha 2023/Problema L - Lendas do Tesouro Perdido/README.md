# Problema L - Lendas do Tesouro Perdido

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]Isa, Emerson e Lucas são amigos aventureiros que adoram explorar lugares antigos e misteriosos em busca de tesouros perdidos. [cite: 286] [cite_start]Em uma de suas expedições, eles encontraram um mapa do tesouro extremamente antigo. [cite: 287] [cite_start]O mapa contém várias pistas que levam ao tesouro escondido, mas também possui um segredo para despistar os caçadores de tesouros. [cite: 288]

[cite_start]Formalmente, a pista é representada por uma sequência de $n$ inteiros $a_1, ..., a_n$. [cite: 289] [cite_start]Para despistar exploradores, o segredo do tesouro está codificado como uma subsequência $b$ de $a$ que começa em 1, termina em 1 e todos os números adjacentes diferem em exatamente 1. [cite: 290, 291]

[cite_start]Para desvendar o enigma e encontrar o tesouro, Isa, Emerson e Lucas precisam determinar o tamanho da maior subsequência possível que atenda a essas restrições. [cite: 292] [cite_start]Escreva um programa e ajude-os a tornarem-se as Lendas do Tesouro Perdido! [cite: 293]

## Entrada

[cite_start]A primeira linha contém um único inteiro $n (1 \le n \le 10^5)$ - o número de elementos do vetor $a$. [cite: 295] [cite_start]A segunda linha contém $n$ inteiros $a_1, ..., a_n (1 \le a_i \le n)$, os elementos do vetor $a$. [cite: 296, 298]

## Saída

[cite_start]Imprima um único inteiro o tamanho da maior subsequência que satisfaça as restrições dadas. [cite: 299, 300]

## Exemplo

| Entrada           | Saída |
| :---------------- | :---- |
| [cite_start]10 [cite: 302]            | [cite_start]9 [cite: 302]   |
| [cite_start]1 2 3 2 1 2 3 4 2 1 [cite: 302] |       |
| [cite_start]3 [cite: 302]             | [cite_start]0 [cite: 302]   |
| [cite_start]2 3 4 [cite: 302]         |       |
| [cite_start]6 [cite: 302]             | [cite_start]1 [cite: 302]   |
| [cite_start]2 2 2 1 1 1 [cite: 302]   |       |
| [cite_start]11 [cite: 302]            | [cite_start]5 [cite: 302]   |
| [cite_start]3 4 1 5 2 9 3 4 1 2 1 [cite: 302]|       |

## Notas

[cite_start]Uma subsequência de um array $a$ é uma sequência de elementos que pode ser obtida a partir do array original, mantendo a ordem dos elementos, mas sem necessariamente usar todos os elementos. [cite: 304]