#include <stdio.h>

int main() {

    char String_1[] = "Hello Daniboy World";
    char String_2[20] = " ";
    char *ptr_1 = String_1;
    char *ptr_2 = String_2;

    printf("\nString_1 Original: %s", String_1);
    printf("\nString_2 Original: %s", String_2);

    while (*ptr_1 != '\0') 
    {
        *ptr_2 = *ptr_1;
        ptr_1++;
        ptr_2++;
        
        if (*ptr_1 == '\0') {
        *ptr_2 = '\0';
        }
    }

    printf("\n\nString_1 Concatenada na String_2: %s", String_2);

  return 0;
}