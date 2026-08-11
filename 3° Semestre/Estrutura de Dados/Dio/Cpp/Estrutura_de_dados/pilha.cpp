#include <iostream>
#include <stack>

using namespace std;

// Função para buscar um elemento na pilha
bool busca_pilha(stack<int> pilha, int elemento) {
    // Percorre a pilha do topo até a base
    while (!pilha.empty()) {
        // Verifica se o elemento atual é o elemento desejado
        if (pilha.top() == elemento) {
            return true;
        }
        // Remove o elemento atual da pilha
        pilha.pop();
    }
    // Elemento não encontrado na pilha
    return false;
}

int main() {
    // Cria uma pilha de inteiros
    stack<int> pilha;

    // Insere elementos na pilha
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    // Busca o elemento 20 na pilha
    if (busca_pilha(pilha, 20)) {
        cout << "Elemento encontrado!" << endl;
    } else {
        cout << "Elemento nao encontrado!" << endl;
    }

    // Busca o elemento 40 na pilha
    if (busca_pilha(pilha, 40)) {
        cout << "Elemento encontrado!" << endl;
    } else {
        cout << "Elemento nao encontrado!" << endl;
    }

    return 0;
}

