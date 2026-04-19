#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Define Um Registro
typedef struct registro {
    int valor;
    struct registro* proximo;
}registro;

// Define uma fila
typedef struct Fila {
    registro* inicio;
    registro* fim;
}Fila;

// Prototipagem
void menu(Fila *Fila);
registro* cria_registro();
Fila* cria_fila();
void inserir_registro(Fila *fila, int novo_valor);
void remover_registro(Fila *fila, int N);
void remover_registro_fila(Fila *fila);
void mostrar_fila(Fila *fila);
void zerar_fila(Fila *fila);
void inverter_fila(Fila *fila);

int main () {
    Fila *fila_1 = cria_fila();
    menu(fila_1);

    return 0;
}

void menu(Fila *fila) {
    int opcao;
    int numero;
    do{
        sleep(1);
        system("cls || clear");
        printf("\n");
        printf("+------------- MENU ----------------+\n");
        printf("+- 1 - Inserir registro no fim    --+\n");
        printf("+- 2 - Remover da fila            --+\n");
        printf("+- 3 - Mostrar a Fila             --+\n");
        printf("+- 4 - Zerar a Fila               --+\n");
        printf("+- 5 - Inverter a fila            --+\n");
        printf("+- 6 - Remover como fila          --+\n");
        printf("+- 7 - Sair                       --+\n");
        printf("+- Operacao:");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("\nDigite o numero para inserir no fim:\n");
                scanf("%d", &numero);
                inserir_registro(fila, numero);
                printf("Numero Inserido com sucesso!");
                sleep(1);
                break;
            
            case 2:
                printf("\nDigite o numero que deseja remover:\n");
                scanf("%d", &numero);
                remover_registro(fila, numero);
                sleep(1);
                break;

            case 3:
                mostrar_fila(fila);
                break;
            
            case 4:
                zerar_fila(fila);
                printf("Fila Zerada com sucesso!!");
                break;

            case 5:
                inverter_fila(fila);
                printf("Fila Invertida com sucesso");
                break;

            case 6:
                remover_registro_fila(fila);
                printf("Numero removido com sucesso!");
                break;
            
            case 7:
                break;

            default:
                printf("opcao invalida!");
                sleep(1);
                break;
        }
    }while(opcao != 7);

    printf("\n");
}

registro* cria_registro(){
    registro* novo_registro = (registro*) malloc(sizeof(registro));
    novo_registro->valor = 0;
    novo_registro->proximo = NULL;
    
    return novo_registro;
}

Fila* cria_fila(){
    return (Fila*) calloc(0, sizeof(Fila)); 
}

void inserir_registro(Fila *fila, int novo_valor){
    registro *novo;
    
    novo = cria_registro();
    novo->valor = novo_valor;
    
    if(fila->inicio == NULL && fila->fim == NULL){  // Verificação se a fila está vazia
        
        fila->inicio = novo;                        // Se a fila estiver vazia, o novo registro será tanto o 
        fila->fim = novo;                           // início quanto o fim da fila
    }
    else 
    {
        fila->fim->proximo = novo;                  // Se a fila não estiver vazia, o novo registro será adicionado 
        fila->fim = novo;                           // ao final da fila
    }
    
}

void remover_registro(Fila *fila, int N)
{    
    if(fila->inicio == NULL && fila->fim == NULL){          // Verifica se a fila está vazia
        return;
    }

    registro *aux_atual = fila->inicio;
    registro *aux_anterior = NULL;

    while(aux_atual != NULL && aux_atual->valor != N){  // Percorre a fila até encontrar o elemento N ou chegar ao final 
        aux_anterior = aux_atual;
        aux_atual = aux_atual->proximo;
    }

    // Se o elemento N não foi encontrado
    if (aux_atual == NULL) {
        printf("Numero nao encontrado!");
        return; 
    }

    // Se o elemento N foi encontrado e é o primeiro da fila
    if (aux_anterior == NULL) {
        fila->inicio = aux_atual->proximo;
    } else {
        // Se o elemento N foi encontrado no meio ou no fim da fila
        aux_anterior->proximo = aux_atual->proximo;
        
    }

    // Se o elemento N foi encontrado e é o último da fila
    if (aux_atual == fila->fim) {
        fila->fim = aux_anterior;
    }

    printf("Numero removido com sucesso!");
    // Libera a memória do registro removido
    free(aux_atual);
}

void remover_registro_fila(Fila *fila){
    if(fila->inicio == NULL){
        printf("Fila vazia");
        return;
    }
    
    registro *aux = fila->inicio;   // Igual o Aux para apontar o inicio da fila

    fila->inicio = aux->proximo; // Coloca o inicio para o proximo

    free(aux);

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

}


void mostrar_fila(Fila *fila) {
    // Verifica se a fila está vazia
    if (fila->inicio == NULL && fila->fim == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Elementos da fila: ");

    // Ponteiro auxiliar para percorrer a fila
    registro *aux_atual = fila->inicio;

    // Percorre a fila e exibe os elementos
    while (aux_atual != NULL) {
        printf("%d ", aux_atual->valor);
        aux_atual = aux_atual->proximo;
    }

    printf("\n");
}

void zerar_fila(Fila *fila) {
    // Verifica se a fila está vazia
    if (fila->inicio == NULL && fila->fim == NULL) {
        return; // Se a fila estiver vazia, retorna sem fazer nada
    }

    registro *atual = fila->inicio;
    registro *proximo;

    // Percorre a fila e remove todos os elementos
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual); // Libera a memória do registro atual
        atual = proximo; // Move para o próximo registro
    }

    // Atualiza os ponteiros da fila para indicar que está vazia
    fila->inicio = NULL;
    fila->fim = NULL;
}

void inverter_fila(Fila *fila) {
    
    if (fila->inicio == NULL || fila->inicio == fila->fim) {
        return; 
    }

    registro *anterior = NULL;
    registro *atual = fila->inicio;
    registro *proximo;

    // Percorre a fila e inverte os ponteiros dos registros
    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    // Atualiza os ponteiros da fila para refletir a nova ordem
    fila->fim = fila->inicio;
    fila->inicio = anterior;
}


