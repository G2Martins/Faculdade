/*Faça um programa em C que leia três números reais e imprima a média aritmética destes números.*/

#include <stdio.h>

int main() {
  int numero_1;
  int numero_2;
  int numero_3;

  printf("\nDigite o numero 1:\n");
  scanf("%d", &numero_1);

  printf("\nDigite o numero 2:\n");
  scanf("%d", &numero_2);

  printf("\nDigite o numero 3:\n");
  scanf("%d", &numero_3);

  int media = (numero_1 + numero_2 + numero_3) / 3;

  printf("A Media Aritmetica dos numeros |N1: %d| |N2: %d| |N3: %d|\n Resulta em: %d", numero_1,numero_2,numero_3,media);
  
  return 0;
}
