//Faça um programa em C que leia um número decimal e o converta em binário (ex.: 9 => 1001)
#include <stdio.h>

void decimal_Para_Binario(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }
    
    int binario[32];
    int i = 0;
    
    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
}

int main() {
    int numero_Decimal;
    
    printf("Digite um número decimal: ");
    scanf("%d", &numero_Decimal);
    
    printf("O número binário correspondente é: ");
    decimal_Para_Binario(numero_Decimal);
    
    return 0;
}
