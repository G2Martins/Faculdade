#include <stdio.h>
#include <stdlib.h>

int main() {

  struct produto_t {
    char nome[31];
    float preco;
    int quantidade;
  };

  struct produto_t produtos[3];

  for (int i = 0; i < 3; i++) {
    printf("Entre com o nome do produto: ");
    scanf("%[^\n]s", produtos[i].nome);
    getchar();
    printf("Entre com a quantidade do produto: ");
    scanf("%i", &produtos[i].quantidade);
    getchar();
    printf("Entre com o valor do produto: ");
    scanf("%f", &produtos[i].preco);
    getchar();
    "clear";
  }

  for(int i=0; i<2; i++)//     bubble sort
  { 
    for(int j=i+1; j<3; j++) 
    {
      if (produtos[i].preco < produtos[j].preco) 
      {
        struct produto_t troca = produtos[i];
        produtos[i] = produtos[j];
        produtos[j] = troca;
      }
    }
  }
  
  printf("\n\n\n");
  printf("-------------------------------------\n");
  printf("         N O T A   L E G A L         \n");
  printf("-------------------------------------\n");
  printf("Item                 Qtd        Valor\n");

  float total = 0.0f;
    for (int i = 0; i < 3; i++) 
    {
        total = total + produtos[i].quantidade * produtos[i].preco;
        printf("%-20.20s %03i %12.2f\n", produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }

  printf("-------------------------------------\n");
  printf("Total da Nota %23.2f\n", total);

  return 0;
}
