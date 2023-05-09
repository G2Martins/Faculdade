#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float valor_em_gb;
    
    printf("\nDigite um valor em Gigabytes:\n");
    scanf("%f", &valor_em_gb);
    
    float conversao = (valor_em_gb * 1024 * 1024 * 1024);
    
    printf("Conversao de %.f GB = %.f Bytes\n", valor_em_gb, conversao);
    
    return 0;

}
