#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  const double PI = 3.1416;
  int raio = 0;

  printf("\nDigite o valor do raio:\n");
  scanf("%i", &raio);

  double comprimentopizza = 2 * PI * raio;

  printf("O comprimento da Pizza igual a: %f", comprimentopizza);
  
  return 0;
}
