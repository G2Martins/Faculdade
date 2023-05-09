/*Faça um programa em C que leia a largura e o comprimento de um terreno em metros e calcule a sua área em hectares (1 hectare = 10.000 m²).*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  float largura;
  float comprimento;
  float area;

  printf("-----------------------------------------\n");
  printf(" C A L C U L A D O R A   DE   H E C T A R\n");
  printf("-----------------------------------------\n");

  
  printf("\nDigite o valor da largura:\n");
  scanf("%f", &largura);

  printf("\nDigite o valor do comprimento\n");
  scanf("%f", &comprimento);

  printf("Dados enviados pelo user\n |Largura:%.f| |Comprimento:%.f|", largura,comprimento);
  
  area = (largura * comprimento) / 10000; // conversão de metros quadrados para hectares
  
  printf("\nA area do terreno resulta em %.2f hectares.\n", area);
    
  return 0;
}
