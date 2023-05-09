#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int coeficiente_a = 0;
  int coeficiente_b = 0;
  int coeficiente_c = 0;

  printf("Digite o valor do coeficiente A:");
  scanf("%i", &coeficiente_a);

  printf("Digite o valor do coeficiente B:");
  scanf("%i", &coeficiente_b);

  printf("Digite o valor do coeficiente C:");
  scanf("%i", &coeficiente_c);

  int delta = coeficiente_b * coeficiente_b - (4 * coeficiente_a * coeficiente_c);
  float raiz1 = - (coeficiente_b + (sqrt(delta)) / 2 * coeficiente_a;
  float raiz2 = - (coeficiente_b - (sqrt(delta)) / 2 * coeficiente_a;

  printf("As raizes da equacao %ix2 %ix %i sao %f e %f", coeficiente_a,coeficiente_b,coeficiente_c,raiz1,raiz2);

  return 0;
  
