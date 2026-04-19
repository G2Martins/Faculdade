## Desafio

### Dado um array de números inteiros que representam a posição de robôs em uma linha, escreva um que retorne o índice do robô que percorreu a maior distância em relação aos outros robôs.

### O programa deve conter uma função maiorDistancia que recebe como parâmetro um array de inteiros e o tamanho do array e retorna o índice do robô que percorreu a maior distância.

## Entrada:
### A entrada consiste de duas linhas:

### A primeira linha contém um inteiro N (1 <= N <= 10), representando o tamanho do array.
### A segunda linha contém N inteiros separados por espaço, representando as posicoesDosRobos.

## Saída:
### Um número inteiro representando o índice do robô que percorreu a maior distância.

## Exemplos

### A saída deve ser uma linha contendo um inteiro, representando o índice do robô que percorreu a maior distância em relação aos outros robôs. Em caso de empate, a saída deve ser o índice do primeiro robô encontrado.

### Restrição: No caso de haver empate, ou seja, mais de um robô percorrendo a maior distância, o programa deve retornar o índice do robô que aparece primeiro no array. Por exemplo, se os robôs 2 e 5 percorrerem a maior distância, o programa deve retornar o índice 2 (que aparece primeiro no array).

 
## Entrada	Saída
5
10
20
30
40
50                 O robô que percorreu a maior distância é o robô 5

3
15
25
25           O robô que percorreu a maior distância é o robô 2


1
0          O robô que percorreu a maior distância é o robô 1