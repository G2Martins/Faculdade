/*Faça um programa em C que leia o valor de compra, o ano de fabricação e o ano de depreciação e calcule o valor depreciado de um veículo (depreciação = (ano de depreciação - ano de fabricação) x 0,01 x valor de compra).*/

#include <stdlib.h> 
#include <stdio.h>

int main() {
  int valor_compra;
  int ano_fabricacao;
  int ano_debreciacao;

  printf("\nDigite o valor pago pelo carro:\n");
  scanf("%d", &valor_compra);

  printf("\nDigite o Ano de fabricacao do carro?\n");
  scanf("%d", &ano_fabricacao);

  printf("\nDigite o Ano Atual:\n");
  scanf("%d", &ano_debreciacao);

  int valor_debreciado = (ano_debreciacao - ano_fabricacao) * 0.01 * valor_compra;
  int valor_final_veiculo = valor_compra - valor_debreciado;

  printf("\nValor de debreciacao do Veículo: %d\n", valor_debreciado);
  printf("\nValor Final Do Usado Atualizado: %d\n", valor_final_veiculo);
    
  return 0;
}
