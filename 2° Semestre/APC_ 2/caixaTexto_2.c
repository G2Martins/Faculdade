#include <stdio.h>

int main () {
    char s[] = "Exame";
    char *ps = s;

    printf("%c %c %c", s[3], *(ps + 3), *(s + 3));

    printf("\n%d %d %d", (&s[3]), (ps + 3), (s + 3));

}