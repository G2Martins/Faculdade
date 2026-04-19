#include <stdio.h>

int main ()
{
    char string[] = "Gustavo Martins";
    char *endConsoante = NULL;
    char *p = string;

    while(*p != '\0')
    {
        switch(*p){
            case 'b': case 'B':
            case 'c': case 'C':
            case 'd': case 'D':
            case 'f': case 'F':
            case 'g': case 'G':
            case 'h': case 'H':
            case 'j': case 'J':
            case 'k': case 'K':
            case 'l': case 'L':
            case 'm': case 'M':
            case 'n': case 'N':
            case 'p': case 'P':
            case 'q': case 'Q':
            case 'r': case 'R':
            case 's': case 'S':
            case 't': case 'T':
            case 'u': case 'U':
            case 'v': case 'V':
            case 'w': case 'W':
            case 'x': case 'X':
            case 'y': case 'Y':
            case 'z': case 'Z':
            endConsoante = p;
        }
        
        p++;
    }
    if(endConsoante)
    printf("Endereço encontrado: %p, (%c)\n", endConsoante, *endConsoante);
  else
    printf("Nenhuma vogal encontrada!\n");
   return 0;
}