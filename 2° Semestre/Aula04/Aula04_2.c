#include <stdio.h>

int main(void) {
    int v[10] = {3, 5, 6, 2, 8, 9, 1, 5, 0, 7};
    
    for(int i = 0; i < 10; i++) 
    {
	   printf("índice %d:\n", i);
		printf("\tNotação de vetor: valor = %d, endereço = %p\n", v[i], &v[i]);
		printf("\tNotação de ponteiro: valor = %d, endereço = %p\n", *(v+i), v+i);
	}
  
    return 0;
}
