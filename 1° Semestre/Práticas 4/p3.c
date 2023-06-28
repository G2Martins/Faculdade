//Faça um programa em C que leia a quantidade e o preço de 10 produtos de um nota fiscal e imprima o valor total de cada produto e o valor total da nota.

#include <stdio.h>

int main() {

    float produtos[10][3]; // 10x3 -> 0 = QTDE; 1 = Preço; 2 = Total
    
    for (int i = 0; i < 10; i++)
    {
        printf("Entre com a Quantidade do %i° produto", i+1);
        scanf("%f", &produtos[i][0]);
        getchar();
        printf("Entre com o preço de %i° produto", i);
        scanf("%f", &produtos[i][1]);
        getchar();
        produtos[i][2] = produtos[i][0] * produtos[i][1];
    }
    
    printf("\n\n");
    printf("+--------------------------+\n");
    printf("+  N O T A   L E G A L     +\n");
    printf("+--------------------------+\n");
    printf("QTDE:     Preco:    Total:\n");
    
    float total = 0.0f;
    for(int i = 0; i < 10; i++)
    {
        total = total + produtos[i][2];
        printf("%03.f\t%10.2f\t%10.2f\n", produtos[i][0], produtos[i][1], produtos[i][2]);
    }
    printf("\nTOTAL:\t%10.2f\n", total);


    
  return 0;
}
