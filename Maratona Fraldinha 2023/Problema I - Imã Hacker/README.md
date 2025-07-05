# Problema I - Imã Hacker

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]Pedro Gallo, por ser um estudante de Engenharia, possui habilidades limitadas em programação, tem a tarefa de modificar um arquivo de $n$ bits em um computador. [cite: 212] [cite_start]No entanto, ele não pode confiar em suas habilidades de programação e decide adotar uma abordagem diferente. [cite: 213] [cite_start]Pedro remove secretamente o disco rígido do computador e planeja alterar manualmente os bits do arquivo usando um imã. [cite: 214] [cite_start]Infelizmente, o imã disponível possui restrições operacionais. [cite: 215]

As únicas operações permitidas por esse imã são as seguintes:
* [cite_start]**Operação 1:** Transformar dois bits adjacentes em 1 (ligar dois bits adjacentes). [cite: 217]
* [cite_start]**Operação 2:** Transformar dois bits adjacentes em 0 (desligar dois bits adjacentes). [cite: 218]

[cite_start]Dada uma string S com n bits, Pedro deseja saber se é possível transformá-la em uma string T de n bits usando apenas as duas operações acima. [cite: 219]

## Entrada

[cite_start]A entrada é composta por três linhas: [cite: 221]
[cite_start]A primeira linha contém um número inteiro $n (2 \le n \le 10^5)$, representando o tamanho em bits do arquivo. [cite: 222] [cite_start]A segunda linha contém uma string S de n caracteres, onde cada caractere representa um bit do arquivo original no disco rígido. [cite: 222] [cite_start]A terceira linha contém uma string T de n caracteres, onde cada caractere representa o bit desejado pelo Pedro para o arquivo. [cite: 222]

## Saída

[cite_start]Imprima na saída: [cite: 224]
[cite_start]"YES" (sem aspas) se for possível realizar a operação de hackear o HD e transformar a string S em T usando as operações permitidas. [cite: 225]
[cite_start]"NO" (sem aspas) caso contrário, ou seja, se não for possível obter a string T a partir da string S usando apenas as operações permitidas. [cite: 226]

## Exemplo

| Entrada   | Saída |
| :-------- | :---- |
| [cite_start]5 [cite: 228]       | [cite_start]NO [cite: 228]  |
| [cite_start]11100 [cite: 228]   |       |
| [cite_start]00110 [cite: 228]   |       |
| [cite_start]3 [cite: 228]       | [cite_start]NO [cite: 228]  |
| [cite_start]101 [cite: 228]     |       |
| [cite_start]010 [cite: 228]     |       |
| [cite_start]7 [cite: 228]       | [cite_start]YES [cite: 228] |
| [cite_start]1011100 [cite: 228] |       |
| [cite_start]0100011 [cite: 228] |       |

## Notas

[cite_start]No primeiro caso de teste, é impossível utilizando apenas operações de ligar/desligar 2 bits adjacentes transformar 11100 em 00110. [cite: 231, 232]

Exemplo de sequência de operações para o terceiro caso:
* [cite_start]$1011100 <=$ String S [cite: 233]
* [cite_start]$0011100 <=$ Desliga o primeiro e o segundo bit [cite: 234]
* [cite_start]$0011111 <=$ Liga o sexto e sétimo bit [cite: 235]
* [cite_start]$0010011 <=$ Desliga o quarto e quinto bit [cite: 236]
* [cite_start]$0110011 <=$ Liga o segundo e terceiro bit [cite: 237]
* [cite_start]$0100011 <=$ Desliga o terceiro e quarto bit [cite: 238]