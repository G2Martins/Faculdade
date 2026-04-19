#include <stdio.h>

void troca(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(int vetor[], int baixo, int alto) {
  int pivo = vetor[alto];
  int i = (baixo - 1);

  for (int j = baixo; j < alto; j++) {
    if (vetor[j] <= pivo) {
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }

  troca(&vetor[i + 1], &vetor[alto]);
  return (i + 1);
}

void ordenacaoQuick(int vetor[], int baixo, int alto) {
  if (baixo < alto) {
    int pi = particao(vetor, baixo, alto);
    ordenacaoQuick(vetor, baixo, pi - 1);
    ordenacaoQuick(vetor, pi + 1, alto);
  }
}

int main() {
  int vetor[] = {10, 7, 8, 9, 1, 5};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);
  ordenacaoQuick(vetor, 0, tamanho - 1);
  printf("Vetor ordenado: \n");
  for (int i = 0; i < tamanho; i++)
    printf("%d ", vetor[i]);
  return 0;
}
