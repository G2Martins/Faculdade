//Faça um programa em C que leia um verbo e imprima a conjugação no presente do indicativo caso ele termine em AR (ex.: PROGRAMAR, EU PROGRAMO, TU PROGRAMAS, ELE PROGRAMA, NÓS PROGRAMAMOS, VÓS PROGRAMAIS E ELES PROGRAMAM.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char verbo[21];

    printf("Digite um verbo terminado em AR:");
    scanf("%s", verbo);
    getchar();
    
    int tamanho_verbo = strlen(verbo); // DETERMINA O TAMNHO DA STRING

    for(int i = 0; i < tamanho_verbo; i++)
    {
        verbo[i] = toupper(verbo[i]); // Transforma de Minúsculo para Maiúsculo
    }
    
    if(verbo[tamanho_verbo - 2] == 'A' && verbo[tamanho_verbo -1] == 'R')
    {
        char radical[21];
        strcpy(radical, verbo);
        radical[tamanho_verbo - 2] = '\0';
        char pronomes[6][5] = {"EU", "TU", "ELE","NÓS","VÓS","ELES"};
        char sufixos[6][5] = {"O", "AS", "A", "AMOS", "AIS", "AM"};
        printf("Conjugação do verbo %s no presente do Indicativo\n", verbo);

        for(int i = 0; i < 6; i++)
        {
            printf("%s %s%s\n", pronomes[i], radical, sufixos[i]);
        }
    
    }else {
        printf("O verbo %s nao termina em AR\n", verbo);
    }

    
  
  return 0;
}
