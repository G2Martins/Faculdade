#include <stdio.h>

int main(void) {
    int v[10] = {3, 5, 6, 2, 8, 9, 1, 5, 0, 7};
    int *p = v;
	
    for(int i = 0; i < 10; i++) 
    {
		printf("índice %d:\n", i);
		printf("\t   Notação de vetor: valor = %d, endereço = %p\n",   p[i], &p[i]);
		printf("\tNotação de ponteiro: valor = %d, endereço = %p\n", *(p+i),   p+i);
	}
  
    return 0;
}
