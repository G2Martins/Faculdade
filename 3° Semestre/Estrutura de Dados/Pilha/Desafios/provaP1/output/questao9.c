#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1000

char pilha[TAM];
int topo = 0;

char pop();
int push(char x);

int main() {
    int qtd_testes;
    char *texto;
    
    scanf("%d", &qtd_testes);

    while (qtd_testes--) {
        texto = (char*)calloc(TAM, sizeof(char));
        fgets(texto, TAM, stdin);
        topo = 0;

        int erro = 0;
        for (size_t i = 0; i < strlen(texto) && !erro; i++) {
            if (texto[i] == '(') {
                push(texto[i]);
            } else if (texto[i] == ')') {
                if (pop() != '(') {
                    erro = 1;
                }
            }
        }

        if (topo != 0)
            erro = 1;

        if (erro)
            printf("NAO\n");
        else
            printf("SIM\n");

        free(texto);
    }

    return 0;
}

int push(char x) {
    if (topo == TAM) {
        return 0;
    }

    pilha[topo] = x;
    topo++;
    return 1;
}

char pop() {
    if (topo == 0) {
        return ' ';
    } else {
        topo--;
        return pilha[topo];
    }
}
