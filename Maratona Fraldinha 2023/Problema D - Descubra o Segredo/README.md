# Problema D - Descubra o Segredo

* **Limite de tempo:** 1s

## Descrição do Problema

[cite_start]José colocou um segredo em sua mala para viajar para a final brasileira da maratona de programação da SBC 2023, em Chapecó. [cite: 70] [cite_start]Este segredo consiste de uma sequência de inteiros que pode ser rotacionada para a esquerda ou para a direita. [cite: 71] [cite_start]Por exemplo, se o segredo é a sequência 12345, ao ser rotacionado para a esquerda uma vez, temos 23451. Se for rotacionado para a direita uma vez, temos 51234. [cite: 72]

[cite_start]Ao chegar em Chapecó, todos os participantes foram convidados para a palestra de abertura. [cite: 73] [cite_start]Contudo, José esqueceu o seu segredo, e com isso, não pode pegar o seu traje de gala. [cite: 74] [cite_start]Ajude José a descobrir o número mínimo de rotações, para a esquerda ou para a direita, que José precisa aplicar na configuração atual do segredo para chegar na sequência que destrava sua mala. [cite: 75]

## Entrada

[cite_start]A primeira linha da entrada possui um inteiro $n$, que indica a quantidade de casos de testes. [cite: 77] [cite_start]Cada caso de teste é descrito por duas linhas, $S_1$ e $S_2$, indicando, respectivamente, a sequência de inteiros que destrava o segredo da mala, e a sequência de inteiros que o segredo se encontra. [cite: 78]

**Restrições:**
* [cite_start]$1 \le n \le 20$ [cite: 80]
* $1 \le |S_1|, |S_2| \le 1000$ e $|S_1| [cite_start]= |S_2|$ [cite: 81]
* [cite_start]Os dígitos de $S_1$ e $S_2$ vão de 1 a 9 [cite: 82]

## Saída

[cite_start]Imprima, para cada caso de teste, uma linha com o número mínimo de rotações, para a esquerda ou para a direita, necessárias para que José destrave sua mala. [cite: 84]

## Exemplo

| Entrada   | Saída |
| :-------- | :---- |
| [cite_start]3 [cite: 87]       | [cite_start]2 [cite: 95] |
| [cite_start]12345 [cite: 88]  | [cite_start]1 [cite: 96] |
| [cite_start]34512 [cite: 89]  | [cite_start]0 [cite: 97] |
| [cite_start]12345 [cite: 90]  |       |
| [cite_start]51234 [cite: 91]  |       |
| [cite_start]12345 [cite: 92]  |       |
| [cite_start]12345 [cite: 93]  |       |

## Notas

[cite_start]No primeiro caso de teste, José pode aplicar duas rotações para a esquerda. [cite: 100] [cite_start]No segundo, basta José aplicar uma rotação para a direita. [cite: 101] [cite_start]No terceiro, a mala já está destravada, José não precisa fazer nada. [cite: 102]