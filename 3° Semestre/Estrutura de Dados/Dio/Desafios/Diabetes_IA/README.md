## Desafio

### Neste desafio, você está desenvolvendo um modelo de Inteligência Artificial para prever se uma pessoa tem risco de desenvolver diabetes. O modelo de Inteligência Artificial será treinado com informações médicas básicas de uma pessoa, como idade, concentração de glicose no sangue e índice de massa corporal (IMC), indicando se ela tem a possibilidade de adquirir diabetes ou não.

### As informações médicas a serem lidas são idade, concentração de glicose no sangue e índice de massa corporal (IMC). O programa deve prever se há ou não risco de diabetes com base nessas informações.

### Observações importantes para realizar o diagnóstico:

### Considere que uma pessoa com uma concentração de glicose entre 120-125mg/dl e um IMC acima de 27 é considerada com probabilidade de se adquirir diabetes;
### Uma pessoa acima de 126mg/dl é considerada com diabetes;
### Há uma incidência maior após os 40 anos.
### Com base nessas informações, teremos as seguintes condições a serem implementadas:

### Se a concentração de glicose estiver abaixo de 120 mg/dl, não corre o risco de diabetes, imprima:
### Você não corre risco de diabetes

### Se a concentração de glicose estiver entre 120-125 mg/dl e um IMC acima de 27, essa pessoa será considerada com risco de diabetes, imprima:
### Você tem uma probabilidade de adquirir diabetes. Procure um médico

### Se a concentração de glicose com ou acima de 126 mg/dl, está com diabetes, imprima:
### É altamente recomendável que você procure um médico para avaliação

### Por fim, se a pessoa não correr o risco, mas estiver acima de 40 anos, imprima:
### Não tem diabetes. IMPORTANTE: cuide da sua saúde por estar acima dos 40 anos

## Entrada

### A entrada deve receber três valores, referentes às informações do usuário.

### idade: Um número inteiro, que especifica a idade do usuário;
### concentracaoGlicose: Um número inteiro, que mostra a concentração de Glicose no sangue;
### imc: O Índice de massa corporal (float) do usuário;
### IMPORTANTE: A entrada deverá seguir a ordem informada acima.

## Saída

### O programa deve retornar um texto (string) informando se há ou não risco de diabetes com base nas informaçõese condições citadas acima. Veja alguns exemplos de entrada e saída na seção a seguir.

## Exemplos

### A tabela abaixo apresenta exemplos com alguns dados de entrada e suas respectivas saídas esperadas. Certifique-se de testar seu programa com esses exemplos e com outros casos possíveis.

## Entrada	Saída
35
127
27.0    É altamente recomendável que você procure um médico para avaliação


40
119
27.0    Não tem diabetes. IMPORTANTE: cuide da sua saúde por estar acima dos 40 anos


25
125
29.0     Você tem uma probabilidade de adquirir diabetes. Procure um médico


34
110
18.0     Você não corre risco de diabetes