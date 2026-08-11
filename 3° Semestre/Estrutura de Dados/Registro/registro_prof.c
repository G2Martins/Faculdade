#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Insere o registro no fim

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

// Define um Menu 

void menu(Lista *lista) {
    int opcao;
    int numero;
    do{
        sleep(1);
        system("cls || clear");
        printf("\n");
        printf("+------------- MENU ----------------+\n");
        printf("+- 1 - Inserir no registro inicio --+\n");
        printf("+- 2 - Inserir no registro fim    --+\n");
        printf("+- 3 - Mostrar a lista            --+\n");
        printf("+- 5 - Sair                       --+\n");
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
                printf("\nItens na lista:\n");
                mostrar_lista(lista);
                sleep(1);
                break;
            case 5:
                break;
            
            default:
                printf("opcao invalida!");
                sleep(1);
                break;
        }
    }while(opcao != 5);

    printf("\n");
}

int main () {

    Lista *lista_1 = cria_lista();
    menu(lista_1);

    return 0;
}