/*Faça um programa em C que leia dez números e imprima o maior e o menor entre eles.*/
#include <stdio.h>

int main(){
    
    
    
    int numero;
    int maior; 
    int menor; 
    int i;
    
    printf("Insira 10 números \n");
    printf("1º : ");
    scanf("%i", &numero);
    
    maior = numero;
    menor = numero;

    for(i = 2; i<=10; ++i){
        printf("%iº: ", i);
        scanf("%i", &numero);

        if(numero>maior){
            maior = numero;
        }else if(numero<menor){
            menor = numero;
        }
    }

    printf("\nO menor número digitado foi: %i", menor);
    printf("\nO maior número digitado foi: %i", maior);

    return 0;
}
