# Problema E - Enxugando Gelo no Sol

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]A empresa Gota d'Água promove, anualmente, o campeonato internacional de enxugar gelo no sol. [cite: 106] [cite_start]A título de divulgação e incentivo do esporte, a empresa distribui, a cada edição, três vultosos prêmios em dinheiro entre os participantes, aleatoriamente, sendo que cada participante pode receber, no máximo, um prêmio por edição. [cite: 107]

[cite_start]Uma vez que o enxugamento de gelo no sol é um esporte ainda pouco popular, a primeira edição contou com apenas três participantes. [cite: 108] [cite_start]Com o incentivo e divulgação da Gota d'Água, a cada edição um novo participante se junta aos participantes do ano anterior. [cite: 109] [cite_start]A cada edição os participantes recebem identificadores numéricos únicos de 1 a M, onde M é o total de participantes. [cite: 110] [cite_start]Na primeira edição, com M=3, a empresa tinha um total de 6 maneiras de distribuir seus 3 prêmios, a saber: 123, 132, 213, 231, 312 e 321. Já na segunda edição (M=4) haviam 24 maneiras de se distribuir os prêmios, enquanto que na terceira edição (M=5) era um total de 60 maneiras. [cite: 111]

[cite_start]Como a Gota d'Água mantém um registro rigoroso e abrangente das estatísticas do evento, ela gostaria de saber o total acumulado de maneiras de se distribuir os três prêmios, consideradas as N primeiras edições do evento. [cite: 112] [cite_start]Como este número pode ser muito grande, ela ficará satisfeita em saber o resto da divisão dele por $10^9+7$. [cite: 113]

## Entrada

[cite_start]A entrada é composta por uma única linha, que contém o valor do inteiro $N (1 \le N \le 10^{18})$. [cite: 115]

## Saída

[cite_start]Imprima, em uma linha, o resto da divisão por $10^9+7$ do total de maneiras de se distribuir os três prêmios, consideradas as primeiras N edições do evento. [cite: 117]

## Exemplo

| Entrada      | Saída     |
| :----------- | :-------- |
| [cite_start]2 [cite: 120]        | [cite_start]30 [cite: 124]    |
| [cite_start]5 [cite: 121]        | [cite_start]420 [cite: 125]   |
| [cite_start]1234567890 [cite: 122] | [cite_start]263458563 [cite: 126] |

## Notas

[cite_start]No primeiro caso, conforme o texto descreve, são 6 maneiras de se distribuir os prêmios na primeira edição e 24 maneiras na segunda, totalizando $6+24=30$. [cite: 128, 129] [cite_start]No segundo caso, são $6+24+60+120+210=420$ maneiras. [cite: 130]