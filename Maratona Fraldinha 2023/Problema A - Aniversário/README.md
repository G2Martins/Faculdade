# Problema A - Aniversário

* **Limite de tempo:** 1s

## Descrição do Problema

Festas de aniversário são animadas e divertidas. Menos a parte de planejamento, são tantas coisas para comprar que algo sempre é esquecido. Fernanda planejou os mínimos detalhes da festa de 82 anos do avô mas acabou esquecendo de comprar as velas. Felizmente ela lembrou na hora da festa que sua irmã tinha feito 28 anos duas semanas antes e ainda tinha as velas. Depois de cantarem o parabéns e da festa ter sido um sucesso, ela contou para todo mundo o que tinha acontecido. Todos ficaram chocados com a coincidência e pensativos em quantas outras vezes entre a família e amigos próximos duas pessoas celebrarão aniversário com os números invertidos. [cite_start]A expectativa de vida de brasileiros é de 76 anos, mas como a família de Fernanda costuma desrespeitar estatísticas e estatísticos, vamos considerar idades máximas de 99 anos. [cite: 4, 5, 6, 7, 8, 9]

## Entrada

[cite_start]A primeira linha da entrada contém um inteiro $N (2 \le N \le 20)$, o número de familiares e amigos. [cite: 11] [cite_start]Cada uma das próximas $N$ linhas contém um nome $s_i (1 \le |s_i| \le 20)$ e um inteiro $a_i (10 \le a_i \le 99)$. [cite: 12] O nome e idade que o i-ésimo familiar faz neste ano. [cite_start]É garantido que todos os nomes são distintos e formados apenas por letras minúsculas e maiúsculas. [cite: 13, 14]

## Saída

[cite_start]A saída é composta de várias linhas. [cite: 16] [cite_start]Para toda coincidência imprima "Em D anos $P_1$ faz $A_1$ e $P_2$ $A_2$", sem aspas. [cite: 17] [cite_start]Onde $D$ é um inteiro não negativo indicando o número de anos até acontecer a coincidência. [cite: 18] [cite_start]$P_1$ é o nome de uma pessoa e $A_1$ é a idade que ela faz. [cite: 19] [cite_start]$P_2$ é o nome da outra pessoa e $A_2$ a idade que ela faz. [cite: 20] A saída pode ser impressa em qualquer ordem. [cite_start]Em uma linha, as pessoas podem aparecer em qualquer ordem. [cite: 21]

## Exemplo

| Entrada           | Saída                               |
| :---------------- | :---------------------------------- |
| 2                 | [cite_start]Em 0 anos Natalia faz 28 e Wilson 82 [cite: 24] |
| Natalia 28        | [cite_start]Em 11 anos Natalia faz 39 e Wilson 93 [cite: 24] |
| Wilson 82         |                                     |
| 2                 | [cite_start]Em 0 anos Wilson faz 82 e Natalia 28 [cite: 24] |
| Wilson 82         | [cite_start]Em 11 anos Wilson faz 93 e Natalia 39 [cite: 24] |
| Natalia 28        |                                     |
| 4                 | [cite_start]Em 0 anos Filomena faz 77 e Helena 77 [cite: 24] |
| Filomena 77       | [cite_start]Em 11 anos Filomena faz 88 e Helena 88 [cite: 24] |
| Helena 77         | [cite_start]Em 22 anos Filomena faz 99 e Helena 99 [cite: 24] |
| Hugo 22           | [cite_start]Em 5 anos Hugo faz 27 e Elisa 72 [cite: 24] |
| Elisa 67          | [cite_start]Em 16 anos Hugo faz 38 e Elisa 83 [cite: 24] |
|                   | [cite_start]Em 27 anos Hugo faz 49 e Elisa 94 [cite: 24] |