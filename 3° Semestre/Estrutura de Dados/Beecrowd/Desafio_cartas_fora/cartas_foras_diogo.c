#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef struct lista{
    struct registro *inicio;
    struct registro *fim;
    int qtd;
    
}Baralho;

typedef struct registro{
    int valor;
    struct registro *prox;
}Carta;

Baralho *cria_baralho();
Carta *cria_carta();
void insere_carta(Baralho *baralho, int x);
void joga_para_baixo(Baralho *baralhix, Carta *cartix);
void descarta(Baralho *berelho);

int main (){
    int escolha;
    Baralho *baralhito;

    baralhito = cria_baralho();
    
     do{
        scanf("%d", &escolha);
        
        if(escolha > 50){
            scanf("%d", &escolha);
        }
       
        insere_carta(baralhito, escolha);
        
        descarta(baralhito);
        baralhito->inicio = NULL;
        
    }while(escolha != 0);
    
    
    
    
    return 0;
}

Baralho *cria_baralho(){
    Baralho * novo_baralho;
    novo_baralho = (Baralho*)calloc(1,sizeof(Baralho));
    novo_baralho->qtd = 0;

    return novo_baralho;
}

Carta *cria_carta()
{
    Carta *nova_carta;
    nova_carta = (Carta*)calloc(1,sizeof(Carta));
    return nova_carta;
}

void insere_carta(Baralho *baralho, int x){
    
    for(int i = 0; i < x; i++){
        Carta *nova_carta = cria_carta();
        nova_carta->valor = i+1;

        if(baralho->inicio == NULL){
        
            baralho->inicio = nova_carta;
            baralho->fim = nova_carta;
        }else {
            baralho->fim->prox = nova_carta;
            baralho->fim = nova_carta;
        }
    }

    baralho->qtd = x;
}



// joga_para_baixo(Empilhar) - Colocar no Base.
void joga_para_baixo(Baralho *baralhix, Carta *cartix){
    
    baralhix->fim->prox = cartix;
    baralhix->fim = cartix;
    baralhix->inicio = baralhix->inicio->prox;
    cartix->prox = NULL;
}

void descarta(Baralho *berelho){

    if(berelho->qtd < 2){
       return; 

    }else {
        printf("Discarded cards: ");

        while(berelho->qtd > 1){

            
            printf("%d, ", berelho-> inicio-> valor); //printa a carta a ser descartada 
            berelho -> inicio = berelho -> inicio -> prox; //descarta a carta do topo
            joga_para_baixo (berelho, berelho->inicio);//joga o inicio para baixo
            berelho->qtd--;
            
        }
        printf("\nRemaining card: %d\n ", berelho->inicio->valor);
    }
}