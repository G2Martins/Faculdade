#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float numero;

  printf("Digite o Valor: \n");
  scanf("%f", &numero);

  float raiz = sqrt(numero);
  
  printf("A Raiz quadrada de %.1f é: %.2f\n", numero,raiz);

  return 0;
}
