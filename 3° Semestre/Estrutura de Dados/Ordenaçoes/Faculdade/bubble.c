#include <stdio.h>

void ordenacaoBubble(int vetor[], int tamanho) {
  for (int passo = 0; passo < tamanho - 1; ++passo) {
    for (int i = 0; i < tamanho - passo - 1; ++i) {
      if (vetor[i] > vetor[i + 1]) {
        int temporario = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = temporario;
      }
    }
  }
}

int main() {
  int vetor[] = {64, 34, 25, 12, 22, 11, 90};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);
  ordenacaoBubble(vetor, tamanho);
  printf("Vetor ordenado em ordem crescente: \n");
  for (int i = 0; i < tamanho; ++i) {
    printf("%d ", vetor[i]);
  }
  return 0;
}
