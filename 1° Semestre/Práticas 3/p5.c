/*Faça um programa em C que leia um ano e verifique se ele é bissexto (é múltiplo de 4 e não é múltiplo de 100, ou é múltiplo de 400).*/

#include <stdio.h>

int main() {

  int ano_atual = 0;
  int deu_certo = 0;
  
  printf("Digite uma Ano:");
  deu_certo = scanf("%d", &ano_atual);

if(ano_atual % 100 != 0 && ano_atual % 4 == 0 || ano_atual % 400 == 0){
  
  printf("O Ano %d e bissexto", ano_atual);
}else{
  printf("O Ano %d Nao e bissexto", ano_atual);
}
  
  return 0;
}
