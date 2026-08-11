#include <stdio.h>
#include <stdlib.h>

// Define uma Lista

typedef struct Lista {
    struct registro * inicio;
    int qtd;
}Lista;

// Define um Registro

typedef struct registro {
    int valor;
    struct registro * prox;
}registro;

// Cria uma Lista 

Lista* cria_lista(){
    Lista *nova_lista;
    nova_lista = (Lista*)malloc(sizeof(Lista));
    
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;
    
    return nova_lista;
}

// Cria um registro

registro* cria_registro(Lista *lista){
   registro *novo_registro = (registro*)malloc(sizeof(registro));

    novo_registro->valor = 0;
    novo_registro->prox = NULL;
    lista->qtd += 1;
    
    if(lista->inicio == NULL){
        lista->inicio = novo_registro;
    }
    
    return novo_registro;
}

void inserir_prox(registro *anterior_registro, registro *atual_registro){
    anterior_registro->prox = atual_registro;
}

int main () {

    Lista *lista_1 = cria_lista();
    
    registro *reg_1 = cria_registro(lista_1);
    
    registro *reg_2 = cria_registro(lista_1);
    inserir_prox(reg_1, reg_2);
    
    registro *reg_3 = cria_registro(lista_1);
    inserir_prox(reg_2, reg_3);

    
    printf("A Quantidade de Registros %d", lista_1->qtd);

    return 0;
}
