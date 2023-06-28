//Faça um programa em C que leia uma frase de até 30 caracteres preenchendo uma matriz 6x5 e depois imprima a matriz percorrendo coluna por coluna.
#include <stdio.h>
#include <string.h>
#define LINHAS 6
#define COLUNAS 5
#define MAX_CARACTERES 30

int main() {
    char frase[MAX_CARACTERES + 1];
    char matriz[LINHAS][COLUNAS];

    
    printf("Digite uma frase de ate %d caracteres: ", MAX_CARACTERES);
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Remover o caractere de nova linha

    // Preenchimento da matriz
    int linha = 0, coluna = 0;
    for (int i = 0; i < strlen(frase); i++) {
        matriz[linha][coluna] = frase[i];

        coluna++;
        if (coluna == COLUNAS) {
            linha++;
            coluna = 0;
        }

        if (linha == LINHAS) {
            break;  // Limite máximo da matriz atingido
        }
    }

    // Impressão da matriz
    printf("Matriz:\n");
    for (int j = 0; j < COLUNAS; j++) {
        for (int i = 0; i < LINHAS; i++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
