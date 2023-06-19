/*Escrever um programa em C que liste os 10 primeiros números da série de
 * Fibonacci.*/
// n3 = n1 + n2 ---> n3 = 1 + 1 = 2

#include <stdio.h>

int main() {
  int i;
  int n1 = 0;
  int n2 = 1;
  int n3;

printf("Os 10 primeiros números de Fibonacci são:\n");

    for (i = 1; i <= 10; i++)
    {
        printf("%d\n", n1);   
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }

  return 0;
}
