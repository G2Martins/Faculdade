/*Faça um programa em C que calcule o valor do desconto sobre um valor bruto lido com base na escala: até de 100.00 aplica 1%; de 100.01 a 500.00 aplica 5%; acima de 500.00 aplica 10%.*/

#include <stdio.h>

int main() {
  float valor_bruto = 0.0f;
  int deu_certo = 0;

  printf("\nDigite o valor do produto:\n");
  deu_certo = scanf("%f", &valor_bruto);

if (valor_bruto <= 100){
  const float DESCONTO_1 = 0.01 * valor_bruto;
  float valor_final1 = valor_bruto - DESCONTO_1;
    
  printf("\nValor do produto enviado pelo user: %.2f\n", valor_bruto);
  printf("\nValor do desconto: %.2f\n", DESCONTO_1);
  printf("\nValor Final do produto: %.3f\n",valor_final1);
}else if (valor_bruto <= 500){
  const float DESCONTO_2 = 0.05 * valor_bruto;
  float valor_final2 = valor_bruto - DESCONTO_2;
    
  printf("\nValor do produto enviado pelo user: %.2f\n", valor_bruto);
  printf("\nValor do desconto: %.2f\n", DESCONTO_2);
  printf("\nValor Final do produto: %.3f\n",valor_final2);
}else{
  const float DESCONTO_3 = 0.10 * valor_bruto;
  float valor_final3 = valor_bruto - DESCONTO_3;
    
  printf("\nValor do produto enviado pelo user: %.2f\n", valor_bruto);
  printf("\nValor do desconto: %.2f\n", DESCONTO_3);
  printf("\nValor Final do produto: %.3f\n",valor_final3);
  }
  
  return 0;
}
