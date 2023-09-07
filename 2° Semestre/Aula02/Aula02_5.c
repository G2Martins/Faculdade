#include <stdio.h>

int main(void) {
   int a,b,*c,*d,*e;
    a = 10;
    b = 3;
    c = &a;
    d = &b;
    *c /= 2; // c = 5 (Nesse Instante)
    e = c; // e = 5
    c = d; // c = 3
    d = e; // d = 5
    
    printf("%d %d", *c,*d);
    getchar();
    
    
    
    return 0;
}
