# Problema J - João e o Irrigador

* **Limite de tempo:** 3s

## Descrição do Problema

[cite_start]João dividiu sua plantação meticulosamente em linhas paralelas e equidistantes, as quais são subdivididas por colunas paralelas e equidistantes, perpendiculares às linhas. [cite: 243] [cite_start]Assim, fica definida uma malha que pode identificar cada muda por um par de coordenadas inteiras ($x$, $y$), onde $x$ indica a linha e $y$ a coluna onde a muda se encontra. [cite: 244]

[cite_start]João pretende colocar um irrigador no ponto (A, B), o qual irá molhar todas as mudas que estiverem dentro do raio de alcance R. [cite: 245] [cite_start]Uma vez que João planta suas mudas apenas nos pontos de interseção entre as linhas e as colunas, e considerando que nenhuma muda será plantada no ponto de fixação do irrigador, determine o máximo de mudas que poderão ser irrigadas. [cite: 245]

## Entrada

[cite_start]A entrada consiste em $T (1 \le T \le 1000)$ casos de teste, onde o valor de T é dado na primeira linha. [cite: 247] [cite_start]Cada teste consiste em uma única linha com os valores A, B e $R (-10^9 \le A, B \le 10^9, 1 \le R \le 3000)$, separados por um espaço em branco. [cite: 248]

## Saída

[cite_start]Para cada caso de teste imprima, em uma linha, o máximo de mudas que podem ser regadas pelo irrigador. [cite: 250]

## Exemplo

| Entrada     | Saída |
| :---------- | :---- |
| [cite_start]5 [cite: 252]       | [cite_start]4 [cite: 252]   |
| [cite_start]7 -2 1 [cite: 252]  | [cite_start]12 [cite: 252]  |
| [cite_start]-1 4 2 [cite: 252]  | [cite_start]28 [cite: 252]  |
| [cite_start]2 3 3 [cite: 252]   | [cite_start]80 [cite: 252]  |
| [cite_start]100 100 5 [cite: 252]| [cite_start]316 [cite: 252] |
| [cite_start]37 -59 10 [cite: 252]|       |

## Notas

Os 28 pontos do terceiro caso de teste estão ilustrados na figura abaixo. O ponto preto corresponde ao irrigador. [cite_start](Não é possível ilustrar a imagem aqui, por favor, consulte o PDF original para a representação visual.) [cite: 254]