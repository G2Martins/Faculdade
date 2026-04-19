#include <stdio.h>

int main() {
  int peso, altura;
  char temPelos, ehMamifero;

  scanf("%d", &peso);
  getchar();
  
  scanf("%d", &altura);
  getchar();
  //Como scanf lê os caracteres no buffer de entrada (teclado), quando digitamos um caractere e
  //teclamos enter, o caractere '\n' vai para o buffer e é lido pelo próximo scanf (que espera um char).
  //Para resolover essa situação, basta inserir um espaço entre a aspa e o símbolo %c:
  scanf(" %c", &temPelos);
  getchar();
  scanf(" %c", &ehMamifero);
  getchar();
  
  //TODO: Implementar o restante das condições para que todos os animais sejam categorizados.
  if (peso >= 2000 && altura >= 300) {
        printf("O animal é um elefante!\n");
    } else if (ehMamifero == 's' && temPelos == 's' && altura == 150) {
        printf("O animal é um cavalo!\n");
    } else if (ehMamifero == 's' && temPelos == 's' && altura <= 100) {
        printf("O animal é um cachorro!\n");
    } else if (ehMamifero == 'n' && temPelos == 'n') {
        printf("O animal é uma serpente!\n");
    } else if (ehMamifero == 's' && temPelos == 'n') {
        printf("O animal é uma tartaruga!\n");
    } else {
        printf("Não foi possível classificar o animal!\n");
    }

  return 0;
}