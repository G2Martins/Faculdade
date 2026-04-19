## Desafio
### Você foi contratado para criar um sistema de informações de produtos para uma loja virtual. O sistema deve ser capaz de gerenciar dois tipos de produtos: eletrônicos e vestuário. Os produtos eletrônicos possuem uma garantia em meses, enquanto os produtos de vestuário possuem um tamanho (P, M ou G). Sua tarefa é desenvolver um programa em C++ utilizando os conceitos de Orientação a Objetos, encapsulamento e polimorfismo para exibir as informações de cada produto. Crie as seguintes classes:

## Classe Produto com as seguintes propriedades e método:
### - nome: uma string que representa o nome do produto;
### - informacoes(): um método virtual puro que retorna uma string com informações do produto.

## Classe Eletronico, que herda de Produto, com a seguinte propriedade adicional:
### - garantia: um inteiro que representa a garantia do produto em meses.

## Classe Vestuario, que herda de Produto, com a seguinte propriedade adicional:
### - tamanho: uma string que representa o tamanho do produto (P, M ou G).

### O método informacoes() deve ser sobrescrito nas classes derivadas (Eletronico e Vestuario) para exibir as informações específicas de cada tipo de produto.

## Entrada
### A entrada consiste em duas linhas: A primeira linha contém uma string que representa o nome do produto; A segunda linha contém uma string que representa o tipo de produto ("E" para eletrônico ou "V" para vestuário), seguida por um espaço e as informações adicionais específicas de cada tipo (um inteiro G (1 ≤ G ≤ 60) para garantia em meses de produtos eletrônicos ou uma string T (P, M ou G) para o tamanho de produtos de vestuário).

## Saída
### A saída deve apresentar a string retornada pelo método informacoes() do produto. A string retornada seguirá o seguinte padrão: Para produtos eletrônicos: "[nome], garantia: [garantia] meses" Para produtos de vestuário: "[nome], tamanho: [tamanho]" onde [nome], [garantia] e [tamanho] são substituídos pelas informações do produto específico.

### Veja como exemplo as entradas recebidas abaixo:

### Celular
### E 24

### Camisa
### V M

### De acordo com esses valores de entrada, as saídas ficarão desta maneira:

### Celular, garantia: 24 meses

### Camisa, tamanho: M

## Exemplos
### A tabela abaixo apresenta exemplos com alguns dados de entrada e suas respectivas saídas esperadas. Certifique-se de testar seu programa com esses exemplos e com outros casos possíveis. Entrada Saída Celular E 24 Celular, garantia: 24 meses Camisa V M Camisa, tamanho: M

### Entrada	Saída
Celular
E 24

### Saída
Celular, garantia: 24 meses

### Entrada
Camisa
V M

### Saída
Camisa, tamanho: M

### Entrada
Video Game
E 12

### Saída
Video Game, garantia: 12 meses