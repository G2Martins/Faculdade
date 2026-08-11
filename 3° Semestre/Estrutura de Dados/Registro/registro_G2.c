#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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

// Mostra a Lista

void mostrar_lista(Lista * lista)
{
    registro *aux;

    if (lista->inicio == NULL)
    {
        printf("\nNao existem elementos nessa lista!\n");
    }
    else
    {
        aux = lista->inicio;

        while (aux != NULL)
        {
            printf("\n Valor: %d", aux->valor);
            aux = aux->prox;
        }
    }
}

// Cria um registro

registro* cria_registro(){
   registro *novo_registro = (registro*)malloc(sizeof(registro));

    novo_registro->valor = 0;
    novo_registro->prox = NULL;


    return novo_registro;
}

// Insere o registro no fim

void inserir_registro_fim(int novo_valor, Lista * lista){
    registro *aux, *novo;
    
    if(lista ==NULL){
      return;
    }
    novo = cria_registro();
    novo->valor = novo_valor;

    
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    else
    {
        aux = lista->inicio;
        
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }    
    
    lista->qtd++;
}

// Insere o registro no Início

void inserir_registro_inicio(int novo_valor, Lista * lista){
    registro * novo;

    novo = cria_registro();
    novo->valor = novo_valor;
    
    if(lista->inicio == NULL)
    {
        lista->inicio = novo;
    }else{
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
    lista->qtd++;
}

// Insere o Registro de forma ordenado na lista

void inserir_registro_ordenado(int valor, Lista *lista){
    registro *novo, *aux, *ant = NULL;
    
    if(lista == NULL){
        return;
    }
    
    novo = cria_registro();
    novo->valor = valor;

    if (lista->inicio == NULL){
        lista->inicio = novo;
    
    } else {
        aux = lista->inicio;

        while (aux!= NULL && aux->valor < novo->valor) {
            ant = aux;
            aux = aux->prox;
        }
        
        if (ant == NULL){ // Para casos onde a condição não é sastisfeita logo no primeiro elemento
            lista->inicio = novo;
            novo->prox = aux;
        } else { // Para casos onde a condição não é satisfeita em qualquer elemento da lista sem ser o primerio
            novo -> prox = aux;
            ant -> prox = novo;
        }
    }
    lista->qtd++;
}

// Função para trocar dois valores
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ordenar a lista encadeada
void ordenarLista(Lista** lista) {
    registro* i;
    registro* j;

    for (i = *lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->valor > j->valor) {
                trocar(&(i->valor), &(j->valor));
            }
        }
    }
}



// Define um Menu 

void menu(Lista *lista) {
    int opcao;
    int numero;
    do{
        sleep(1);
        system("cls || clear");
        printf("\n");
        printf("+------------- MENU ----------------------+\n");
        printf("+- 1 - Inserir no registro inicio       --+\n");
        printf("+- 2 - Inserir no registro fim          --+\n");
        printf("+- 3 - Inserir Ordenado                 --+\n");
        printf("+- 4 - Mostrar a lista                  --+\n");
        printf("+- 5 - Ordenar Crescentemente a lista   --+\n");
        printf("+- 6 - Sair                             --+\n");
        printf("+- Operacao:");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("\nDigite o numero para inserir no fim:\n");
                scanf("%d", &numero);
                inserir_registro_inicio(numero, lista);
                printf("Numero Inserido com sucesso!");
                sleep(1);
                break;
            
            case 2:
                printf("\nDigite o numero para inserir no fim:\n");
                scanf("%d", &numero);
                inserir_registro_fim(numero, lista);
                printf("Numero Inserido com sucesso!");
                sleep(1);
                break;
            
            case 3:
                printf("\nDigite o numero para inserir ordenado:\n");
                scanf("%d", &numero);
                inserir_registro_ordenado(numero, lista);
                printf("Numero Inserido com sucesso!");
                sleep(1);
                break;
            
            case 4:
                printf("\nItens na lista:\n");
                mostrar_lista(lista);
                sleep(1);
                break;
            
            case 5:
                ordenarLista(lista);
                printf("Lista ordenada crescentemente");
                sleep(1);
                system("cls || clear");
                mostrar_lista(lista);
                sleep(1);
                break;

            case 6:
                system("cls || clear");
                printf("finalizando...");
                sleep(1);
                exit(0);
                break;
            
            default:
                printf("opcao invalida!");
                sleep(1);
                break;
        }
    }while(opcao != 6);

    printf("\n");
}

int main () {

    Lista *lista_1 = cria_lista();
    menu(lista_1);

    return 0;
}