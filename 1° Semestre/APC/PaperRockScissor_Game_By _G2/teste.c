#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa       // DEFINIÇÃO DO "MOLDE" PARA PESSOAS
{
    int idade;      // Atributo de idade
    float salario;  // Atributo Salário
    char nome[225];  // Atributo Nome
};

int main()
{
   struct Pessoa pessoas[2];

   pessoas[0].idade = 25;                                   // MUDA IDADE DA PESSOA_1
   pessoas[0].salario = 500;                                // MUDA O SALÁRIO DA PESSOA_1
   strcpy (pessoas[0].nome, "Luisa Massae Nobrega Kiguti"); // MUDA O NOME DA PESSOA_1
//+-------"PARA ONDE MANDAR"// Qual Conteúdo Mandar"-----+

   pessoas[1].idade = 30;                                   // MUDA IDADE DA PESSOA_2
   pessoas[1].salario = 800;                                // MUDA O SALÁRIO DA PESSOA_2
   strcpy (pessoas[1].nome, "Gustavo Martins Gripaldi");    // MUDA O NOME DA PESSOA_2

   int i;
    //IMPRIME A LISTA DE PESSOAS 
    for(i = 0; i < 2; i++)
    {
        printf("\nNome: %s \n", pessoas[i].nome); // IMPRIME A STRING
        printf("Anos: %d  \nSalario: %.2f\n", pessoas[i].idade, pessoas[i].salario);
    }

    return 0;
}