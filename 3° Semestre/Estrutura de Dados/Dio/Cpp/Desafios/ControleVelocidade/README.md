## Desafio
### Você foi contratado para criar um software que simule o controle de velocidade de um robô. Esse robô possui uma velocidade máxima e uma velocidade mínima. Sua tarefa é desenvolver um programa  utilizando o conceito de Orientação a Objetos para calcular a velocidade final do robô após uma sequência de comandos.Crie uma classe chamada "Robo" que possua as seguintes propriedades e métodos:

### velocidadeAtual: inteiro que representa a velocidade atual do robô (inicialmente 0);
### velocidadeMaxima: inteiro que representa a velocidade máxima do robô;
### velocidadeMinima: inteiro que representa a velocidade mínima do robô;
### acelerar(): um método que aumenta a velocidade atual em 1 unidade, desde que não ultrapasse a velocidade máxima;
### desacelerar(): um método que diminui a velocidade atual em 1 unidade, desde que não fique abaixo da velocidade mínima.

## Entrada
### A entrada consiste em duas linhas: A primeira linha contém dois inteiros Vmin e Vmax (1 ≤ Vmin < Vmax ≤ 100), representando a velocidade mínima e máxima do robô, respectivamente.
### A segunda linha contém uma sequência de comandos (com no máximo 100 caracteres), onde: 'A' representa uma aceleração e 'D' representa uma desaceleração. Desta maneira, a entrada seria da seguinte maneira:

### Vmin Vmax: ambos valores int.
### comandos: string.

## Saída
### A saída deve apresentar apenas a velocidade final (int)  do robô, considerando as regras descritas nos métodos de acelerar e desacelerar.

## Exemplos
### A tabela abaixo apresenta exemplos com alguns dados de entrada e suas respectivas saídas esperadas. Certifique-se de testar seu programa com esses exemplos e com outros casos possíveis.

### Entrada
1 5
AADAD
### Saída
2

### Entrada
2 8
ADAAD

### Saída
3