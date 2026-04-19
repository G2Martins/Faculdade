/* Nesse exemplo, a função criarNode cria um novo nó e a função 
insert insere um novo nó na árvore, seguindo as regras de uma 
árvore binária de busca. A função inOrder percorre a árvore em ordem, 
imprimindo os valores dos nós. A função main cria a árvore binária de 
busca e realiza um percurso em ordem para imprimi-la.*/

#include <iostream>

using namespace std;

struct Node{
    int valor;
    Node *esquerda;
    Node *direita;
};

// Cria um novo nó
Node* criarNode(int valor){
    Node* newNode = new Node;
    newNode->valor = valor;
    newNode->esquerda = NULL;
    newNode->direita = NULL;
    
    return newNode;
}

Node* insert(Node *raiz, int valor){
    // Se a raiz for nula, logo o valor a ser inserido é a raiz
    if(raiz == NULL){
        return criarNode(valor);
    }

    // verifica se o elemento a inserir é menor que o valor da raiz, logo insere-se a esquerda
    if(valor < raiz->valor){
        raiz->esquerda = insert(raiz->esquerda, valor);
    }
    // verifica se o elemnto a inserir é maior que o valor da raiz, logo insere-se a direita
    else if(valor > raiz->valor){
        raiz->direita = insert(raiz->direita, valor);
    }

    return raiz;
}

void inOrder(Node* raiz){
    if(raiz != NULL){
        inOrder(raiz->esquerda);
        cout << raiz->valor << " ";
        inOrder(raiz->direita);
    }
}

int main(){
    Node* raiz = NULL;
    raiz = insert(raiz, 50);
    insert(raiz, 30);
    insert(raiz, 20);
    insert(raiz, 40);
    insert(raiz, 70);
    insert(raiz, 60);
    insert(raiz, 80);

    cout << "A ordem transversal da busca binaria na arvore:";
    inOrder(raiz);
}