#include <stdio.h>

int main (){
    char s[] = "Exame";
    char *ps = s;

    printf("%d %c", ps, *(ps));
    return 0;
}