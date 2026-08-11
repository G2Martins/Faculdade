#include <stdio.h>

int main()
{
    char string_original[] = "Hello Daniboy World";
    char *ptr_1 = string_original;
    char *ptr_2 = string_original;
    unsigned char count;
    unsigned char *ptr_troca = &count;

    printf("\nString Original: %s\n", string_original);

    while (*ptr_2 != '\0') {
        if (*(ptr_2 + 1) == '\0')
        break;
        ptr_2++;
    }

    while (ptr_1 != ptr_2){
        
        *ptr_troca = *ptr_2;
        *ptr_2 = *ptr_1;
        *ptr_1 = *ptr_troca;
        ptr_1++;
        ptr_2--;
    }

    printf("\nString Invertida: %s\n", string_original);
}