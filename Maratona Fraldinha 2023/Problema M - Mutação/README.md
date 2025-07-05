# Problema M - Mutação

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]Depois de um dia cheio de estudos para a maratona de programação, Blum, Estela e Muza resolveram jogar um jogo para descontrair um pouco. [cite: 308] [cite_start]Diante das opções, elas acabaram escolhendo um jogo chamado Mutação. [cite: 309]

[cite_start]Em Mutação, os jogadores se encontram diante de um tabuleiro em forma de matriz quadrada, pré-carregado com peças estrategicamente posicionadas. [cite: 310] Cada peça tem um valor que reflete sua importância tática. [cite_start]O desafio é usar essas peças para obter a vitória. [cite: 311] [cite_start]Os jogadores precisam utilizar suas habilidades estratégicas para realizar movimentos inteligentes e tomar decisões precisas. [cite: 312] [cite_start]A cada jogada, é necessário avaliar cuidadosamente a posição das peças e antecipar os movimentos do adversário. [cite: 313]

[cite_start]A verdadeira reviravolta do jogo é a operação que dá nome a ele: a mutação. [cite: 314] [cite_start]Nesta operação os jogadores têm a oportunidade de rolar um dado e rotacionar no sentido horário as diagonais principal e secundária da matriz, reorganizando assim a disposição dessas peças afetadas. [cite: 315] [cite_start]Isso pode ser feito a qualquer momento durante a partida! [cite: 316]

[cite_start]O manual do jogo possui o seguinte exemplo, para uma configuração de jogo: (Não é possível ilustrar a imagem aqui, por favor, consulte o PDF original para a representação visual.) [cite: 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329]

[cite_start]Após rolar o dado e tirar o valor 1, o resultado de uma rotação no sentido horário é o seguinte: (Não é possível ilustrar a imagem aqui, por favor, consulte o PDF original para a representação visual.) [cite: 330, 331, 332, 333, 334, 335, 336, 337]

[cite_start]Antes de se aprofundar no restante das regras do jogo, Blum, Estela e Muza resolveram te chamar e escrever um programa para, dada a configuração do jogo e o número resultado da rolagem do dado, realizar a mutação. [cite: 338]

## Entrada

[cite_start]A primeira linha da entrada contém dois inteiros separados por espaço $n$ e $d$, onde $n (2 \le n \le 1000)$ indica a quantidade de linhas e colunas do tabuleiro, e $d (1 \le d \le 1000)$ o valor retirado no dado. [cite: 340] [cite_start]As próximas $n$ linhas contêm $n$ inteiros $a_i$ cada $(-10^6 \le a_i \le 10^6)$, separados por espaço, que representam cada uma das peças no tabuleiro. [cite: 341]

## Saída

[cite_start]A saída deve conter $n$ linhas, onde cada linha deve conter $n$ inteiros separados por espaço, que são a configuração final do tabuleiro após a operação de mutação ter sido realizada. [cite: 344]

## Exemplo

| Entrada      | Saída          |
| :----------- | :------------- |
| [cite_start]4 1 [cite: 346]    | [cite_start]2 13 1 [cite: 346] |
| [cite_start]1 2 3 4 [cite: 346]| [cite_start]10 5 8 [cite: 346] |
| [cite_start]5 6 7 8 [cite: 346]| [cite_start]9 11 7 12 [cite: 346]|
| [cite_start]9 10 11 12 [cite: 346]| [cite_start]16 14 15 4 [cite: 346]|
| [cite_start]13 14 15 16 [cite: 346]|                |
| [cite_start]3 2 [cite: 346]    | [cite_start]9 2 7 [cite: 346]  |
| [cite_start]1 2 3 [cite: 346]  | [cite_start]4 5 6 [cite: 346]  |
| [cite_start]4 5 6 [cite: 346]  | [cite_start]3 8 1 [cite: 346]  |
| [cite_start]7 8 9 [cite: 346]  |                |