/*Utilizando ponteiros, realize a troca de valores entre as variáveis n1 e n2.*/

#include <stdio.h>

int main() {
    int n1, n2, *troca_n1, *troca_n2;
    n1 = 3;
    n2 = 5;
    troca_n1 = &n1;
    troca_n2 = &n2;
   

  
	
	printf("n1: %d, n2: %d\n", n1, n2); // espera-se exibir n1: 5, n2: 3
	return 0;
}
