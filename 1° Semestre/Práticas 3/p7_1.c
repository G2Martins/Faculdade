#include <stdio.h>

int main() 
{
    int n1 = 0; 
    int n2 = 1; 
    int n3; 
    int i;

    printf("Os 10 primeiros números de Fibonacci são:\n");

    for (i = 0; i < 10; i++) 
    {
        if (i <= 1)
            n3 = i;
        else 
        {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }

        printf(" %d\n", n3);
    }

    return 0;
}
