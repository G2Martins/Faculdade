#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    private: string nome;
    int idade;

    public: Pessoa(string n, int i) {
        nome = n;
        idade = i;
    }

    string getNome() {
        return nome;
    }

    int getIdade() {
        return idade;
    }
};

int main() {
    string nome;
    int idade;

    cin >> nome;
    cin >> idade;

    //TODO: Criar uma instância de Pessoa com os dados de entrada.
    Pessoa pessoa1(nome, idade);
    //TODO: Imprimir a saída de acordo com o enunciado deste desadio.
    cout << "Nome: "<< pessoa1.getNome() << ", Idade: " << pessoa1.getIdade() << endl;

    return 0;
}