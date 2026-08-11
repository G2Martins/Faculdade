#include <stdio.h>
    
    char *endconsoante= NULL;
    char *p;

    char *localizarCh(char *p,char *endconsoante)
    {
        while (*p != '\0') 
        {
            switch(*p)
            {
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
                case 'v': case 'V': 
                case 'w': case 'W': 
                case 'x': case 'X': 
                case 'y': case 'Y': 
                case 'z': case 'Z': 
                endconsoante = p;
            }
            p++;
        }
        return endconsoante;
    }
    
int main() 
{
    char palavra[55];
    printf("Escreva a palavra: \n");
    scanf("%s",palavra);
    
    char *p = palavra;
    char *ultimaconsoante = localizarCh(p, ultimaconsoante);
    
    if(ultimaconsoante){
        printf("A ultima consoante da palavra %s é: %c\n\n",palavra,*ultimaconsoante);    
    }
    else{
        printf("A palavra %s não possui consoante",palavra);
    }
            
    return 0;
}