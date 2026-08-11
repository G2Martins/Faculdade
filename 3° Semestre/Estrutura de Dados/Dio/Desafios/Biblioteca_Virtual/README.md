## Desafio

### Neste desafio, você deve desenvolver um programa que simule uma biblioteca virtual que utiliza robôs para organizar seus livros. O programa receberá como entrada o número total de livros existentes na biblioteca e as informações de cada livro, incluindo o título, autor e ano de publicação.

## Entrada

### O programa deve receber como entrada o número de livros presentes na biblioteca e as informações de cada livro. A primeira linha da entrada contém um número inteiro N (1 ≤ N ≤ 100) que representa o número de livros na biblioteca. As próximas N linhas contêm as informações de cada livro, na seguinte sequência (cada dado em uma nova linha):

### titulo (string)
### autor (string)
### anoDePublicacao (int)
### As strings de título e autor não contêm espaços, e o ano de publicação é um número inteiro de quatro dígitos.

## Saída

### O programa deve identificar o livro mais antigo da lista de livros que o usuário informou, armazenar suas informações em variáveis e imprimí-las no seguinte formato:

### biblioteca[indiceLivroMaisAntigo].titulo
### biblioteca[indiceLivroMaisAntigo].autor
### biblioteca[indiceLivroMaisAntigo].ano

### Dica: Você pode explorar uma estrutura de dados (struct, classe etc) para definir os atributos de cada livro. Com isso, sua lógica de impressão ficará parecida com a sintaxe acima, onde a biblioteca é um array de Livro.

## Exemplos

### A tabela abaixo apresenta exemplos com alguns dados de entrada e suas respectivas saídas esperadas. Certifique-se de testar seu programa com esses exemplos e com outros casos possíveis.

### Entrada
2
Moby-Dick
Herman Melville
1851
Emma
Jane Austen
1815	

### Saída 
Emma
Jane Austen
1815

### Entrada
2
Hamlet
Willian Shakespeare
1603
Dracula
Bran Stoker
1897	

### Saída 
Hamlet
Willian Shakespeare
1603

### Entrada
2
Dao de Jing
Laozi
742
Frankenstein
Mary Shelley
1818	

### Saída 
Dao de Jing
Laozi
742