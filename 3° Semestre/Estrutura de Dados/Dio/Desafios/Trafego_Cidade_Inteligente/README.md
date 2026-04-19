## Desafio

### Você está trabalhando em um projeto de análise de tráfego urbano para uma cidade inteligente. Para isso, você precisa criar uma função que receba como parâmetro um array de números inteiros representando o número de veículos que passaram por uma rua em diferentes horários do dia. Sua função deve retornar a média de veículos por hora em todo o período.

### Dessa forma, escreva um programa que solicite ao usuário o tamanho do array e os números de veículos que passaram por uma rua em diferentes horários do dia, calcule a média de veículos por hora em todo o período e imprima o resultado na tela.

## Entrada

### A entrada será composta por dois valores:

### Linha 1: Um número inteiro n (0 < n ≤ 24) representando o tamanho do array. Este valor indica quantos números inteiros serão lidos a seguir.

### Linha 2: Um conjuntos de números inteiros veiculosPorHora separados por espaço, onde cada elemento representa a quantidade de veículos que passaram em cada hora do dia. Esses valores devem estar compreendidos entre 0 e 10000.

### Os valores deverão ser informados na mesma linha, separados por espaço.

## Saída

### A saída deverá retornar um texto (string), indicando qual foi a média de veículos que passaram pela rua em todo o período. Como exemplo, veja os valores recebidos abaixo: 

### Linha 1: 5

### Linha 2: 100 200 150 300 250

### De acordo com esses valores de entrada, a saída ficará desta maneira:

### Média de veículos por hora: 200
### Caso o número de horas com veículos registrados seja menor que o tamanho do array informado, a média deve ser calculada apenas considerando as horas com registros.

### Dica: Use a função round() para arredondar a média final de carros passados pela rua.

## Exemplos

### A tabela abaixo apresenta exemplos com alguns dados de entrada e suas respectivas saídas esperadas. Certifique-se de testar seu programa com esses exemplos e com outros casos possíveis.

### Entrada	Saída
<p>5 100 200 150 300 250  Média de veículos por hora: 200</p>

3
50 75 90   Média de veículos por hora: 72

7
10 20 30 40 50 60 70 Média de veículos por hora: 40