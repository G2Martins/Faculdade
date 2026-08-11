#include <stdio.h>
#include <stdlib.h>

//Criação das estruturas, o primeiro new_carta cria um tipo de variável (new_carta)
//e o segundo o nome da struct
typedef struct New_card {
	int valor;
	struct New_card *proximo;
} New_card;

typedef struct Deque {
	struct New_card *first;
	struct New_card *end;
	int qtd;
} Deque;

// Função que define a crição do Deque
Deque *cria_deque() {
		Deque *novo_deque;
		novo_deque = (Deque*)calloc(1, sizeof(Deque));
		novo_deque -> qtd = 0;
	
		return novo_deque;
}

// Função que define a crição das Cartas
New_card *cria_card() {
		New_card *new_card;
		new_card = (New_card*)calloc(1,sizeof(New_card));
		return new_card;
}

// Função que insere as cartas dentro do Deque
void inserir_card(Deque *deque, int n) {
	for(int i = 0; i < n; i ++){
		New_card *new_card = cria_card();
		new_card -> valor = i+1;

		if(deque -> first == NULL){
			deque->first = new_card;
			deque->end = new_card;
		}else {
			deque -> end -> proximo = new_card;
			deque -> end = new_card;
		}
	}
	deque -> qtd = n;
}

// Função que empurra o elemento que está no topo para a base/final
void push(Deque *deque, New_card *new_card){
	deque -> end -> proximo = new_card;
	deque-> end = new_card;
	deque -> first = deque -> first -> proximo;
	new_card -> proximo = NULL;

}

void pop (Deque *deque){
	if(deque->first == NULL || deque->qtd < 2){
		return;
	} else {
		printf("Discarded cards: ");
		while(deque->qtd > 1){

			if(deque->qtd != 2){
				printf("%d, ", deque->first->valor);
			}else {
				printf("%d", deque->first->valor);
			}

			deque->first = deque->first->proximo;

			push(deque, deque->first);

			deque->qtd --;
		}
		printf("\nRemaining card: %d\n", deque->first->valor);
	}
}


int main() {
    int n;
	Deque *novo_deque;
	novo_deque = cria_deque();

	do{
		scanf("%d", &n);
		inserir_card(novo_deque, n);
		pop(novo_deque);
		novo_deque->first = NULL;

	}while(n != 0);

    return 0;
}
