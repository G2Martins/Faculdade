# Desafio Conta Banco
Folder destinado ao armazenamento do Desafio de Projeto em java com o seguinte tema:
"Desafios Java: Organizando seus ativos"

# 📚 Documentação
- [Documento Desafio](https://drive.google.com/file/d/1QPfMSDmYqXUgdrzvZy64xmP2iHzWYb35/view?pli=1)

## Descrição
Implemente um jogo de adivinhação, onde o usuário deve adivinhar um número aleatório entre 1 a
100. Enquanto o usuário não acertar o número, deverá ser informado ao usuário que o palpite do
usuário foi muito alto ou muito baixo. Caso o usuário acertar o número, deverá ser informado que ele
acertou em determinado número de tentativas.

## Entrada
Para a construção do jogo, considere elaborar as seguintes funções:
- void novoJogo(); - Que inicializa um novo jogo, conforme a lógica do fluxograma.
- int gerarNumeroAleatorio(int min, int max); - Que retorna um número aleatório entre 1 a 100.
- int receberPalpite(); - Que solicita ao usuário um número inteiro e o retorne como palpite para afunção novoJogo() receber esse valor.
- int verificarPalpite(int palpite, int numeroAleatorio); - Que compara o palpite com o numeroAleatorio, e retorna um valor de acordo com os seguintes casos:
  - Caso o palpite for maior que o número aleatório, retorna 1
  - Caso o palpite for igual ao número aleatório, retorna 0
  - Caso o palpite for menor que o número aleatório, retorna -1
  - void limparTela(); - que limpa a tela do usuário e posiciona o cursor no início do console.

## Saída

```c
Bem-vindo ao jogo da adivinhação!
Estou pensando em um número entre 1 e 100.
Qual é o seu palpite? 50
Muito baixo, tente novamente!
Qual é o seu palpite? 75
Muito alto, tente novamente!
Qual é o seu palpite? 60
Muito baixo, tente novamente!
Qual é o seu palpite? 65
Muito baixo, tente novamente!
Qual é o seu palpite? 67
Muito baixo, tente novamente!
Qual é o seu palpite? 70
Parabéns, você acertou o número após 6 tentativas!
Gostaria de jogar novamente? (s/n):
```


<h4 align="center">
 
![Hello](https://user-images.githubusercontent.com/70382532/138322189-2db8df52-9dcb-40a0-88a8-c365466bd33d.gif)

<hr>
