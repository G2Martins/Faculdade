#include <stdio.h>
#include <ctype.h>

int main() {
    char string[100];
    int i;

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    printf("String em maiúsculo: ");
    for (i = 0; string[i] != '\0'; i++) {
        putchar(toupper(string[i]));
    }

    printf("\nString em minúsculo: ");
    for (i = 0; string[i] != '\0'; i++) {
        putchar(tolower(string[i]));
    }

    return 0;
}
