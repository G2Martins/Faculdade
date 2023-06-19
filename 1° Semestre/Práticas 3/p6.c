/*Faça um programa em C que liste todos os múltiplos de 3, entre 1 e 100.*/

#include <stdio.h>

int main() 
{
    int numero = 0;
    int multiplo_3 = 0;

    for(numero = 0; numero <=100 ; ++numero)
    { 
       multiplo_3 = numero % 3; 
        
        if(multiplo_3 == 0)
        { 
            printf("\n%d é múltiplo de 3\n", numero); 
        }
    }      
    
  return 0; 
 }
