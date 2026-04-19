/*
    Gustavo Martins Gripaldi - 2312082034
    Mayron Malaquias Oliveira - 2312082003
*/

#include <stdio.h>

int main() 
{	
    char destino[100] = "Autônoma";
	char origem[100] = "Universidade";

	// inclua a lógica abaixo da concatenação da origem no início de destino

    char *ptr_1 = destino;
    char *ptr_2 = origem;

    for(int i = 9; i >= 0; i--){
        *(ptr_1 + i + 12) = *(ptr_1 + i);
    }

    for(int i = 0; i < 12; i++){
        *(ptr_1 + i) = *(ptr_2 + i);
    }
        
	// inclua a lógica acima da concatenação da origem no início de destino
	
    printf("%s\n", destino); // Resultado esperado: "UniversidadeAutônoma"
	return 0;
}