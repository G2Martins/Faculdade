/*Faça um programa em C que leia dois números inteiros e imprima o quociente e o resto da divisão entre eles.*/

#include <stdio.h>

int main() {
  int numero_1;
  int numero_2;
  int quociente;
  int resto;

  printf("\nDigite o primeiro numero:\n");
  scanf("%d", &numero_1);

  printf("\nDigite o segundo numero:\n");
  scanf("%d", &numero_2);

  quociente = numero_1 / numero_2;
  resto = numero_1 % numero_2;

  printf("\nO quociente da divisão é: %d\n", quociente);

  printf("\nO resto da divisão é: %d\n", resto);

  return 0;
}
