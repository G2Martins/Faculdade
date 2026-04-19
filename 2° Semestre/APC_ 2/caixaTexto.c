#include <stdio.h>

int main (){
    char s[] = "Exame";
    char *ps = s;

    printf("%c %c",*ps, *(ps + 1));
    printf("%c %c",*(ps + 2), *(ps + 3));
}