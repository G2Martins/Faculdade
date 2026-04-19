#include <iostream>

// Definindo a estrutura do nó da lista
struct No {
  int valor;
  No* proximo;
};

int main() {
  // Criando os nós da lista
  No* n1 = new No();
  No* n2 = new No();
  No* n3 = new No();

  // Inicializando os valores dos nós
  n1->valor = 10;
  n2->valor = 20;
  n3->valor = 30;

  // Criando a lista circular
  n1->proximo = n2;
  n2->proximo = n3;
  n3->proximo = n1;

  // Percorrendo a lista circular
  No* atual = n1;
  do {
    std::cout << atual->valor << " ";
    atual = atual->proximo;
  } while (atual != n1);

  std::cout << std::endl;

  // Liberando a memória dos nós
  delete n1;
  delete n2;
  delete n3;

  return 0;
}

