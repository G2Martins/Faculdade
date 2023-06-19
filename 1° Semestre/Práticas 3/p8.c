/*Faça um programa em C que calcule o fatorial de um número inteiro.*/

#include <stdio.h>

int main()
{ 
    float numero;
    float total = 1;

    printf("Digite um Numero para calcular o seu Fatorial:\n");
    scanf("%f", &numero);

    for(; numero >= 1; --numero)
    {
       total = total * numero;
    }

    printf("Resultado: |%.2f|", total);
  
    return 0;
}
