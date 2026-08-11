#include <iostream>

// Declaração da classe Pessoa 
class Pessoa {

public:
    // Construtor da classe
    Pessoa(std::string nome, int idade){
        nome_ = nome;
        idade_ = idade;
    }

    // Métodos da Classe
    void saudacao(){
        std::cout << "Ola, meu nome e "<< nome_ << " e tenho "<< idade_ << " anos." << std::endl;
    }

    void aniversario(){
        idade_++;
        std::cout << "Feliz Aniversario! Agora tenho " << idade_ << " anos." << std::endl;
    }

private:
    std::string nome_;
    int idade_;
};

int main(){

    Pessoa pessoa1("Alice", 25);
    Pessoa pessoa2("Bob", 30);

    // Chamando métodos dos Objetos
    pessoa1.saudacao();
    pessoa2.saudacao();

    pessoa1.aniversario();
    pessoa2.aniversario();

    return 0;
}
