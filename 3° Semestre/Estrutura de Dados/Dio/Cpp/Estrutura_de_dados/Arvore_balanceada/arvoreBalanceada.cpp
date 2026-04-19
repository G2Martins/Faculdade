#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int valor;
    Node *esquerda;
    Node *direita;
    int altura;
};

// Função para obter a altura de um nó
int altura(Node *n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

// Função para obter o fator de balanceamento de um nó
int fatorBalanceamento(Node *n) {
    if (n == NULL)
        return 0;
    return altura(n->esquerda) - altura(n->direita);
}

// Função para criar um novo nó
Node* criarNode(int valor) {
    Node* newNode = new Node;
    newNode->valor = valor;
    newNode->esquerda = NULL;
    newNode->direita = NULL;
    newNode->altura = 1; // Novo nó é adicionado na folha, portanto a altura é 1
    return newNode;
}

// Função para realizar uma rotação simples à direita
Node* rotacaoDireita(Node *y) {
    Node *x = y->esquerda;
    Node *T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

// Função para realizar uma rotação simples à esquerda
Node* rotacaoEsquerda(Node *x) {
    Node *y = x->direita;
    Node *T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza alturas
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

// Função para inserir um novo nó na árvore AVL
Node* insert(Node *raiz, int valor) {
    // Passo 1: Inserção normal de um nó de árvore binária de busca
    if (raiz == NULL)
        return criarNode(valor);

    if (valor < raiz->valor)
        raiz->esquerda = insert(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = insert(raiz->direita, valor);
    else // Valores iguais não são permitidos em uma árvore AVL
        return raiz;

    // Passo 2: Atualiza a altura do nó atual
    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    // Passo 3: Obtem o fator de balanceamento deste nó para verificar se ele se tornou desbalanceado
    int balance = fatorBalanceamento(raiz);

    // Se o nó se tornou desbalanceado, então existem quatro casos

    // Caso da esquerda esquerda
    if (balance > 1 && valor < raiz->esquerda->valor)
        return rotacaoDireita(raiz);

    // Caso da direita direita
    if (balance < -1 && valor > raiz->direita->valor)
        return rotacaoEsquerda(raiz);

    // Caso da esquerda direita
    if (balance > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Caso da direita esquerda
    if (balance < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função para percorrer a árvore em ordem
void inOrder(Node* raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esquerda);
        cout << raiz->valor << " ";
        inOrder(raiz->direita);
    }
}

int main() {
    Node* raiz = NULL;
    raiz = insert(raiz, 50);
    insert(raiz, 30);
    insert(raiz, 20);
    insert(raiz, 40);
    insert(raiz, 70);
    insert(raiz, 60);
    insert(raiz, 80);

    cout << "A ordem transversal da busca binária na árvore AVL: ";
    inOrder(raiz);

    return 0;
}
