#include <iostream>
#include <string>

using namespace std;

class Robo {
    private: string nome;
    string modelo;
    int anoFabricacao;
    
    public: Robo(string nome, string modelo, int anoFabricacao) {
        this -> nome = nome;
        this -> modelo = modelo;
        this -> anoFabricacao = anoFabricacao;
    }
    void exibirInformacoes() {
        //TODO: Imprimir as informações de acordo com o enunciado deste desafio.
       cout << "O robô " << nome << ", modelo " << modelo << ", foi fabricado em " << anoFabricacao << "." << endl; 
    }
};

int main() {
    string nome, modelo;
    int ano;
    
    getline(cin, nome);
    getline(cin, modelo);
    cin >> ano;
    
    //TODO: Instanciar um Robo passando os valores lidos em seu construtor.
    Robo* robo;
    robo = new Robo(nome, modelo, ano);
    //TODO: Invocar o método "exibirInformacoes".
    robo->exibirInformacoes();
    
    return 0;
}