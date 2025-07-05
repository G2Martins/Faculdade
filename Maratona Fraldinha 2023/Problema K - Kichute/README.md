# Problema K - Kichute

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]Roque é um famoso jogador de futebol na Nlogônia e que é patrocinado pela Alcaparras. [cite: 261] [cite_start]Essa empresa é conhecida por fabricar o Kichute, calçado que é um misto de chuteira e tênis. [cite: 262] [cite_start]O jogador recebeu N pares de kichute, todos do mesmo tamanho, mas com detalhes de cor e desenho diferentes entre si. [cite: 263]

[cite_start]A temporada de futebol masculino irá começar e Roque foi informado que precisará disputar K partidas nos diversos campeonatos que sua equipe está inscrita. [cite: 264] [cite_start]Determine a quantidade de maneiras distintas que Roque poderá utilizar seus pares de kichute em todas as partidas da sua equipe. [cite: 265] [cite_start]Como o valor resultante pode ser muito grande, imprima esse valor módulo $10^9+7$ (o resto da divisão entre esse valor e $10^9+7$). [cite: 266]

## Entrada

[cite_start]A única linha da entrada contém dois inteiros separados por espaço N e K ($1 \le N, K \le 10^6$), denotando a quantidade de pares de kichute e a quantidade de partidas a serem disputadas por Roque, respectivamente. [cite: 268]

## Saída

[cite_start]Imprima um único número inteiro com a resposta para o problema: a quantidade de maneiras distintas que Roque escolhe seus N pares de kichute nos K jogos que irá disputar. [cite: 270] [cite_start]Imprima esse número módulo $10^9+7$. [cite: 271]

## Exemplo

| Entrada    | Saída      |
| :--------- | :--------- |
| [cite_start]2 3 [cite: 274]    | [cite_start]8 [cite: 279]      |
| [cite_start]3 5 [cite: 275]    | [cite_start]243 [cite: 280]    |
| [cite_start]27 65 [cite: 276] | [cite_start]696034236 [cite: 280] |

## Notas

[cite_start]No primeiro exemplo de teste, são oito maneiras distintas de Roque utilizar seus kichutes. [cite: 281] [cite_start]Considere as tuplas a seguir descrevendo cada maneira dele escolher o par de kichutes (representados por inteiros de 1 a N nos K=3 jogos: {1, 1, 1}, {1, 1, 2}, {1, 2, 1}, {1, 2, 2}, {2, 1, 1}, {2, 1, 2}, {2, 2, 2} e {2, 2, 1}. Assim, são 8 maneiras. [cite: 282]