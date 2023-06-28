//Faça um programa em C que preencha uma matriz com 10 números, depois leia um número e localize a posição dele na matriz.

#include <stdio.h>

int main() {
//         Posição =   0   1  2  3  4  5  6  7  8  9  
    int numeros[10] = {10, 5, 2, 1, 4, 7, 6, 9, 3, 0};

/* numeros[0] = 10;
    numeros[1] = 5;
    numeros[2] = 2;
    numeros[3] = 1;
    numeros[4] = 4;
    numeros[5] = 7;
    numeros[6] = 6;
    numeros[7] = 9;
    numeros[8] = 3;
    numeros[9] = 0;
*/  

int numero = 0;

printf("Digite um numero inteiro:\n");
scanf("%i", &numero);

int achei = -1;
        
    for(int i = 0; i < 10; i++)
    {
        if(numero == numeros[i])
        {
            achei = i;
            break;
        }
        
    }

    if(achei < 0)
    {
        printf("Nao Achei o numero %i\n", numero);
    }else
    {
        printf("Achei o Numero %i na posicao %i", numero, achei);
    }

    return 0;
}
