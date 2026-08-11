#include <stdio.h>
#include <stdlib.h>

// Define uma Lista
typedef struct Lista {
    int qtd;
    struct registro * inicio;
    struct registro * fim;
}Lista;

// Define um Registro
typedef struct registro {
    int valor;
    struct registro * prox;
    struct registro * ant;
}registro;

registro * cria_registro(){
    return (registro*)calloc(1,sizeof(registro));
}

Lista * cria_lista(){
    return (Lista*)calloc(1,sizeof(Lista));
}


void inserir_registro_fim(Lista * lista, int valor){
    registro *novo = cria_registro();
    novo->valor = valor;

    if(lista->inicio == NULL && lista->fim == NULL){

        lista->inicio = novo;
        lista->fim = novo;
    }else {
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;

    }
    lista->qtd++;
}

void inserir_registro_inicio(Lista *lista, int valor){
    registro *novo = cria_registro();
    novo->valor = valor;

    if(lista->inicio == NULL && lista->fim == NULL){

        lista->inicio = novo;
        lista->fim = novo;
    }else {
        lista->inicio->ant = novo;
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
    lista->qtd++;
}


void mostrar_lista(Lista *lista, int o){

}

void remover(Lista *lista, int valor){
    if(lista->inicio == NULL && lista->fim == NULL){
        printf("Elemento nao encontrado na lista");
        return;
    }else {
        registro * aux;

        aux = lista->inicio;

        while(aux != NULL){
            
            if(aux->valor == valor)
            {
                if(aux->ant == NULL){ // Caso Elemento  seja o Primeiro Elemento
                    lista->inicio = aux->prox;
                }else{
                    aux->ant->prox = aux->prox;
                }

            
            }
        }
    }
}



int main() { 
    Lista *a = cria_lista();

    return 0;
}