#include <stdio.h>

int main() {
    int numero1 = 0;
    int deu_certo = 0;

    printf("\nDigite um numero:\n");
    deu_certo = scanf("%d", &numero1);

    if (numero1 % 2 == 0){
        printf("\nO Numero %d = Par\n", numero1);
    }else{
        printf("\nO Numero %d = Impar\n", numero1);
    }

    return 0;
}
