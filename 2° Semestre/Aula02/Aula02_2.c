#include <stdio.h>

int main(void) {
   int a,b,*c;
    a = 3;
    b = -1;
    c = &a;
    b++; b++;
    *c = a + 2;
    printf("%d %d", a, b);
    getchar();
    
    
    
    return 0;
}
