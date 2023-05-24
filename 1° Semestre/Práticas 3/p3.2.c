/*Faça um programa em C que imprima um qualitativo associado a uma nota lida conforme a tabela: 1 = Ruim; 2 = Insuficiente; 3 = Suficiente, 4 = Bom, 5 = Ótimo, e imprima Nota inválida nos demais casos.*/

#include <stdio.h>

int main() {
  int nota = 0;
  int deu_certo = 0;

  printf("+---Bem Vindo a Nossa Central de Avaliação-----+\n");
  printf("+                                              +\n");
  printf("+ Qual a sua nota ao nosso atendimento de 1-5? +\n");
  printf("+     1- Ruim                                  +\n");
  printf("+     2- Insuficiente                          +\n");
  printf("+     3- Suficiente                            +\n");
  printf("+     4- Bom                                   +\n");
  printf("+     5- Ótimo                                 +\n");
  printf("+----------------------------------------+\n\n");
  printf("Digite a sua nota:\n");
  deu_certo = scanf("%d", &nota);
 
switch (nota){

  case 1:
    printf("\nNota Do Atendimento enviada pelo user: |Ruim|\n");
    printf("\nMuito Obrigado! O IESB Agradece");
    break;
  
  case 2:
    printf("\nNota Do Atendimento enviada pelo user: |Insuficiente|\n");
    printf("Muito Obrigado! O IESB Agradece");
    break;
  
  case 3: 
    printf("\nNota Do Atendimento enviada pelo user: |Suficiente|\n");
    printf("\nMuito Obrigado! O IESB Agradece");
    break;
  
  case 4:
    printf("\nNota Do Atendimento enviada pelo user: |Bom|\n");
    printf("\nMuito Obrigado! O IESB Agradece");
    break;
  
  case 5:
    printf("\nNota Do Atendimento enviada pelo user: |Ótimo|");
    printf("\nMuito Obrigado! O IESB Agradece");
    break;
  
  default:
      printf("\nErro! O user digitou uma informação inválida");
}
  
  return 0;
}
