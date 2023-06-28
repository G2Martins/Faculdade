/*Faça um programa em C que leia matricula e email de 10 alunos, e depois localize o email do aluno a partir de uma matrícula lida.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

struct aluno_t{
    unsigned long int matricula;
    char email[61];
};

struct aluno_t alunos[10];

    for(int i = 0; i< 10; i++)
    {
        printf("Entre com a matricula do %i° Aluno: ", i + 1);
        scanf("%li", &alunos[i].matricula);
        getchar();
        printf("Entre com o email do %i° Aluno: ", i + 1);
        scanf("%s", alunos[i].email);
        getchar();
        system("clear");
    }
    
int achei = -1;
unsigned long int matricula;

printf("Entre Com a Matricula Para Procurar o Email: ");
scanf("%li", &matricula);

    for(int i = 0; i < 10; i++)
    {
        if(matricula == alunos[i].matricula)
        {
            achei = i;
            break;
        }
    }

    if(achei > -1)
    {
        printf("O Email do Aluno %li é %s\n", alunos[achei].matricula, alunos[achei].email);
    }else{
        printf("Aluno %li Não Encontrado\n", matricula);
    }





    return 0;
}
