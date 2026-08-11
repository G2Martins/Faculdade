#include <stdio.h>

int main(void) {
    
    char String_1[11]= "Hello";
    char String_2[] = "World";
    char *ptr_1 = String_1 + 5;
    char *ptr_2 = String_2;
    
    printf("\nString_1 Sem concatencao: %s", String_1);

    while (*ptr_2 != '\0')
    {
        *ptr_1 = *ptr_2;
        ptr_1++;
        ptr_2++;
    }

    printf("\nString_1 com concatencao: %s", String_1);
  
  return 0;
}