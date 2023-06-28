/*Faça um programa em C que leia dez números e imprima o maior e o menor entre eles.*/

#include <stdio.h>
#include <stdlib.h>


int main() {

    struct numeros_t{
        int numeros;
    };

    struct numeros_t numeros[10];

    for(int i = 0; i < 10; i++)
    {
        system("clear");
        printf("Digite o %i° numero:\n", i + 1);
        scanf("%i", &numeros[i].numeros);
        getchar();
    }
    
    for(int i=0; i<9; i++)//     bubble sort
    { 
        for(int j=i+1; j < 10; j++) 
        {
            if (numeros[i].numeros < numeros[j].numeros) 
            {
            struct numeros_t troca = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = troca;
            }
        }    
    }

    system("clear");
    printf("\n\n\n");
    printf("+-------------------------------------+\n");
    printf("+        Ordem Decrescente            +\n");
    printf("+-------------------------------------+\n");
    
    for(int i = 0; i < 10; i++)
    {
        printf("%d° = %d\n", i + 1, numeros[i].numeros);
    }
    
    
    
    return 0;
}
