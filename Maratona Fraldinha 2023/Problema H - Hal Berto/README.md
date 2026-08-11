# Problema H - Hal Berto

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]Hal Berto é o nome de uma linha de supercomputadores, desenvolvidos pelo laboratório ZPT, que é especializado em matemática e teoria dos números. [cite: 189] [cite_start]Um HB, como é conhecido, representa internamente números inteiros positivos não em base binária, como os computadores tradicionais: ele os guarda em p-uplas, que contêm os expoentes da fatoração prima do número, usando os primeiros p primos. [cite: 190] [cite_start]O motivo disso é óbvio (pelo menos para os engenheiros da ZPT): com este modelo, multiplicações e divisões podem ser feitas somando e subtraindo os coeficientes correspondentes das p-uplas, respectivamente. [cite: 191] [cite_start]Para facilitar a identificação entre os diferentes modelos, os engenheiros dizem que o modelo tem arquitetura p-prima, e escrevem $HB-p$. [cite: 192]

[cite_start]Por exemplo, um HB-2 representaria o número 12 como (2, 1), pois $12=2^2 \times 3$; [cite: 193] [cite_start]um HB-3 representaria 100 como (2,0, 2), pois $100=2^2 \times 3^0 \times 5^2$; e um HB-4 representaria 343 como (0,0,0, 3). [cite: 194]

[cite_start]Você está estagiando no ZPT e sua primeira tarefa é escrever uma rotina que recebe um inteiro positivo N e imprime a representação interna de N em um $HB-p$, se possível. [cite: 195]

## Entrada

[cite_start]A primeira linha da entrada contém o inteiro $M (1 \le M \le 100)$, que indica o número de inteiros que devem ser processados por sua rotina. [cite: 197] [cite_start]Cada uma das M linhas seguintes contém dois inteiros $p (2 \le p \le 100)$ e $N (1 \le N \le 10^9)$, separados por um espaço em branco, que indicam o número que deve ser processado por sua rotina e o número de primos que compõem a arquitetura do HB. [cite: 198]

## Saída

[cite_start]Para cada inteiro N da entrada imprima, em uma linha, a mensagem "Sim", caso seja possível representar N em um $HB-p$, ou a mensagem "Nao", caso contrário. [cite: 200] [cite_start]Se for possível representar o número imprima, na linha seguinte, os p coeficientes da representação do número em uma arquitetura p-prima, com um espaço em branco entre eles (não há espaço após o último coeficiente). [cite: 201]

## Exemplo

| Entrada   | Saída     |
| :-------- | :-------- |
| [cite_start]3 [cite: 204]       | [cite_start]Sim [cite: 204]   |
| [cite_start]2 12 [cite: 204]    | [cite_start]2 1 [cite: 204]   |
| [cite_start]3 100 [cite: 204]   | [cite_start]Sim [cite: 204]   |
| [cite_start]4 343 [cite: 204]   | [cite_start]2 0 2 [cite: 204] |
|           | [cite_start]Sim [cite: 204]   |
|           | [cite_start]0 0 0 3 [cite: 204] |
| [cite_start]3 [cite: 204]       | [cite_start]Nao [cite: 204]   |
| [cite_start]2 10 [cite: 204]    | [cite_start]Sim [cite: 204]   |
| [cite_start]5 16 [cite: 204]    | [cite_start]4 0 0 0 0 [cite: 204] |
| [cite_start]4 11 [cite: 204]    | [cite_start]Nao [cite: 204]   |

## Notas

[cite_start]O primeiro caso foi explicado no texto do problema. [cite: 206] [cite_start]No segundo caso, observe que um HB-2 só utiliza os primos 2 e 3, o que inviabiliza a representação do número 10. [cite: 207]