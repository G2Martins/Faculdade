//Faça um programa em C que leia nome e telefone de 10 contatos, e depois imprima todos os contatos no formato "nome - (telefone)".
#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main() {
  
  struct contatos_t {
    char nome[30];
    char numero[11];        // 
  };

    struct contatos_t contatos[10];

    for(int i = 0; i < 10; i++)
    {
        system("clear");
        printf("\nDigite o Nome do %d° Contato: \n", i + 1);
        scanf("%[^\n]s", contatos[i].nome);
        getchar();

        system("clear");
        printf("\nDigite o Telefone do %d° Contato: \n", i + 1);
        scanf("%[^\n]s", contatos[i].numero);
        getchar();
    }

    printf("\n+----------------------------+\n");
    printf("+-   LISTA DE CONTATINHOS   -+\n");
    printf(" NOME:           Telefone:\n");
    for(int i = 0; i < 10; i++) 
    {
        printf("\n%d° - %s - (83) %s \n", i+1, contatos[i].nome, contatos[i].numero);    
    }    
    printf("+----------------------------+");
    
    return 0;
}
