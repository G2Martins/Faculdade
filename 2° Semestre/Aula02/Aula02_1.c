#include <stdio.h>

int main(void) {
    int i = 5;
    int *p;
    p = &i;
    printf("&p: %p\n", &p);
    printf("p  (&i - endereço de i): %p\n",  p);
    printf("*p ( i -    valor de i): %d\n"  , *p);
    *p = 7; // i = 7 --> i recebe 7 rescrevendo o valor
    printf("*p ( i -    valor de i): %d\n"  , i);
    printf("\n Insira o valor de I: ");
    scanf("%d", p);
    printf("Valor Alterado de i: %d", i);
    
    
    
    return 0;
}
