#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pop(int *pilha, int *topo);
void min(int *pilha, int topo);

int main (){
    
    int total_operacao;                                             
    char operacao[10];
    int valor;
    
    scanf("%d", &total_operacao);

    int *pilha = (int *) malloc(total_operacao * sizeof(int));  // Inicializa a pilha com o tamanho das operações
    int topo = -1;  

    for(int i = 0; i < total_operacao; i++){
         scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0 || 
            strcmp(operacao, "Push") == 0  || 
            strcmp(operacao, "push") == 0) {
            
            scanf("%d", &valor);
            pilha[++topo] = valor;              // Insere o Valor dentro da pilha
            printf("Inseri %d\n", valor); 
        
        }
        if (strcmp(operacao, "POP") == 0 || 
            strcmp(operacao, "Pop") == 0 || 
            strcmp(operacao, "pop") == 0) {
            pop(pilha, &topo);
        
        }
        if (strcmp(operacao, "MIN") == 0 || 
            strcmp(operacao, "Min") == 0 || 
            strcmp(operacao, "min") == 0) {
            min(pilha, topo);
        
        }
    }

    free(pilha);
    return 0;
}

void pop(int *pilha, int *topo) {
    if (*topo == -1) {                          // Verifica se o topo está Vazio
        printf("Pilha vazia.\n");
    } else {                                    // Acessa o Valor que está no topo e o Exclui
        printf("Removi %d\n", pilha[*topo]);    
        (*topo)--;
    }
}

void min(int *pilha, int topo) {
    if (topo == -1) {                           // Verifica se o topo está Vazio
        printf("Pilha vazia.\n");
    } else {
        int min = pilha[0];                     

        for (int i = 1; i <= topo; i++) {
            if (pilha[i] < min) {              // Verifica se o Valor que está na posição 0 do vetor pilha
                min = pilha[i];                // é menor que o proximo valor da pilha  Caso seja ele altera     
            }                                  // min para o valor da pilha na posição i correspondente 
        }

        printf("MIN: %d\n", min);
    }
}