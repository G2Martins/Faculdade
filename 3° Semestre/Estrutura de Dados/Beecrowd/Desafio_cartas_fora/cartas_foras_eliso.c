#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados do registro de cada uma das cartas:
typedef struct registro{
    int valor;
    struct registro *prox;
} registro;

// Estrutura de dados do registro de cada uma das filas de cartas:
typedef struct fila {
    struct registro *inicio;
    struct registro *fim;
    int quantidade;
} fila;

// Craindo uma nova fila com as atribuições da estrutura:
fila *criar_fila(){ 
    fila *nova_fila;
    nova_fila = (fila*)calloc(1,sizeof(fila)); // Alocação dinâmica de uma nova fila de cartas
    nova_fila -> quantidade = 0; // Inicializando a quantidade de elementos como zero
    return nova_fila;
}

// Criando um novo registro com as atribuições da estrutura:
registro *criar_registro(){
    registro *novo_registro;
    novo_registro = (registro*)calloc(1,sizeof(registro)); // Alocação dinâmica de um novo registro de carta
    return novo_registro;
}

//Função destinada a criar um registro dentro de uma lista de escolha
void inserir_registro (fila *fila, int n){
    for (int i = 0; i < n; i ++){ // Laço de repetição para criar cartas com valores de 1 a n.
        registro *novo = criar_registro(); // Criando novo registro dentro da fila
        novo -> valor = i+1; 

        if(fila -> inicio == NULL){ // Se a fila não possuir nenhum elemento, então o seu início recebe o endereço do novo registro.
            fila-> inicio = novo; 
            fila -> fim = novo;
        } else { // Se a fila já possui elementos, então o último elemento recebe o endereço do novo registro
            fila -> fim -> prox = novo;
            fila -> fim = novo; // O fim precisa sempre ser igual ao novo elemento para que sempre esteja no final
        }
    }
    fila -> quantidade = n; // Atualizando a quantidade da fila devido a adição de elementos de 1 a n.
}

// Função destinada a tirar elementos do início/topo e colocar ao final.
void push (fila *fila, registro *novo){ 
        fila -> fim -> prox = novo; // O ultimo elemento recebe o endereço do antigo início
        fila -> fim = novo; // O fim aponta para o novo ultimo elemento
        fila -> inicio = fila -> inicio -> prox; // O início da fila recebe o endereço do antigo segundo elemento
        novo->prox = NULL; // O novo ultimo elemento aponta para NULL
}

// Função destinada a retirar o topo da fila e passar o segundo elemento para o final.
void pop (fila *fila){ 
    if (fila -> inicio == NULL || fila -> quantidade < 2){ // Se a lista não possui elementos ou só possui um único elemento, não tem o que fazer.
        return;
    } else { // Quando tem pelo menos 2 elementos
        printf("Discarded cards: ");
        while (fila -> quantidade > 1){ // Percorrendo todas as cartas até sobrar somente uma e realizando a operaçãod e troca de cartas.
            
            // Imprimindo valor do topo (Ou seja, o que está sendo descartado)
            if (fila -> quantidade != 2){
                printf("%d, ", fila-> inicio-> valor); 
            } else { 
                printf("%d", fila-> inicio-> valor); 
            }

            // Fazendo o inicio da fila apontar para o segundo elemento:
            fila -> inicio = fila -> inicio -> prox; 
            //Empurrando esse segundo elemento (agora igual à topo) para o fim da lista 
            push (fila, fila->inicio);
            // Fazendo o início da fila apontar para o terceiro elemento:
            fila -> quantidade--;
        }
        printf("\nRemaining card: %d\n", fila -> inicio -> valor); // Imprimindo o valor da última carta que sobrou
    }
}

int main (){
    int numero;
    fila *a;
    a = criar_fila();

    do{
        scanf("%d", &numero);
        inserir_registro(a, numero);
        pop(a);
        a->inicio = NULL;

    }while(numero != 0);

    return 0;
}