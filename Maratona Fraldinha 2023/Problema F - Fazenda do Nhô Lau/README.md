# Problema F - Fazenda do Nhô Lau

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]Cansado de ter suas goiabas "afanadas" por Chico Bento, Nhô Lau decidiu construir cercar todas as suas goiabeiras, em um arranjo retangular. [cite: 135] [cite_start]Ele sabe as coordenadas (x, y) de cada goiabeira, onde a origem do sistema de coordenadas é a sua casa, que fica no ponto (0,0). [cite: 136]

[cite_start]Uma vez que a cerca não pode passar por uma goiabeira ou pela casa de Nhô Lau, determine as coordenadas inteiras dos pontos P e Q, onde P é o canto inferior esquerdo e Q o canto superior direito do retângulo que cerca todas as goiabeiras e a casa. [cite: 137] [cite_start]Como dinheiro anda curto, Nhô Lau quer que este retângulo tenha perímetro mínimo. [cite: 138]

## Entrada

[cite_start]A primeira linha da entrada contém o valor do inteiro $N (1 \le N \le 2 \times 10^5)$ que indica o número de goiabeiras no sítio do Nhô Lau. [cite: 140] [cite_start]As N linhas seguintes contêm, cada uma, um par de inteiros $x_i, y_i (-10^9 \le x_i, y_i \le 10^9)$, com $(x,y) \ne (0,0)$ e $(x_i, y_i) \ne (x_j, y_j)$ se $i \ne j$ onde $i, j \in \{1, 2, ..., N\}$ separados por um espaço em branco, indicando as coordenadas da i-ésima goiabeira. [cite: 141]

## Saída

[cite_start]Na primeira linha da saída imprima as coordenadas x e y do ponto P, separadas por um espaço em branco. [cite: 143] [cite_start]Na segunda linha da saída imprima as coordenadas x e y do ponto Q, separadas por um espaço em branco. [cite: 144]

## Exemplo

| Entrada           | Saída     |
| :---------------- | :-------- |
| [cite_start]5 [cite: 147]             | [cite_start]3 -4 [cite: 152]  |
| [cite_start]-2 3 [cite: 147]        | [cite_start]5 5 [cite: 153]   |
| [cite_start]4 4 [cite: 147]         |           |
| [cite_start]0 2 [cite: 147]         |           |
| [cite_start]-1 -3 [cite: 148]       |           |
| [cite_start]3 3 [cite: 149]         |           |
| [cite_start]3 [cite: 150]             | [cite_start]-1 [cite: 154]    |
| [cite_start]1 0 [cite: 155]         | [cite_start]1 0 [cite: 155]   |
| [cite_start]2 0 [cite: 156]         | [cite_start]2 0 [cite: 156]   |
| [cite_start]3 0 [cite: 158]         | [cite_start]4 1 [cite: 157]   |
| [cite_start]3 [cite: 159]             | [cite_start]3 0 [cite: 158]   |
| [cite_start]-2 0 [cite: 161]        | [cite_start]-3 -1 [cite: 160] |
| [cite_start]0 2 [cite: 163]         | [cite_start]3 3 [cite: 162]   |
| [cite_start]2 0 [cite: 164]         |           |

## Notas

[cite_start]No primeiro caso, temos o seguinte cenário: (Não é possível ilustrar a imagem aqui, por favor, consulte o PDF original para a representação visual.) [cite: 167, 168, 169]

[cite_start]No segundo caso, observe que a cerca não pode passar pela casa de Nhô Lau. [cite: 170]