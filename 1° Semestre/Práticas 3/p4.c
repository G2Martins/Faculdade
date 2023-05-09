/*Faça um programa em C que leia uma tecla pressionada e determine se ela é uma letra, um dígito ou um caractere especial.*/

#include <stdio.h>
#include <ctype.h>

int main();
  int tecla;

  printf("Digite uma tecla");
  scanf("%d", tecla);

  tecla = getchar();

if(isalpha(input)){
        printf("Você inseriu uma letra");
    }else if(isdigit(input)){
        printf("Você inseriu um número");
    }else if(ispunct(input)){
        printf("Você inseriu um caractere especial");
    }
  return 0;
}

