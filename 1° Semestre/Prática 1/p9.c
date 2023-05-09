/*Faça um programa em C que converta uma idade expressa em anos, meses e dias para um valor em dias. Considere um ano com 365 dias e um mês com 30 dias.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int anos;
  int meses;
  int dias;
  int tempo_dias;

  printf("\nQual foi o tempo em anos?\n");
  scanf("%d", &anos);
 
  printf("\nQual foi o tempo em meses?\n");
  scanf("%d", &meses);

  printf("\nQual foi tempo em dias?\n");
  scanf("%d", &dias);

  tempo_dias = (anos * 365) + (meses * 30) + dias;

  printf("\n%d anos, %d meses e %d dias equivalem a %d dias.\n", anos, meses, dias, tempo_dias); 
  
  return 0;
  
}
