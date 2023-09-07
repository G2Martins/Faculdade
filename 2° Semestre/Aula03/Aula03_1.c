#include <stdio.h>

int main() {
    int n = 1025;
    int *pn = &n;
    char *pchar = (char *)&n;
    
    printf("\nPN (&n): %u \n", pn);
    printf("PN + 1 (&n): %u \n", pn+1);

    printf("\nPCHAR (&n): %u \n", pchar);
    printf("PCHAR + 1 (&n): %u \n", pchar+1);
    
    printf("\nByte 1 - *PCHAR: %d\n", *pchar);
    printf("Byte 2 - *PCHAR: %d\n", *(pchar + 1));
    
    
    return 0;
}
