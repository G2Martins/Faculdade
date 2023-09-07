/* Utilizando ponteiros, altere o conteúdo da variável numero para 5. */

#include <stdio.h>

int main() {
    int numero,*troca;
    numero = 10;
    troca = &numero;
    *troca /= 2;

    printf("Num: |%d| e Troca: |%d|", numero,*troca);
    getchar();
    
    
  
	
	return 0;
}
