/* Um exemplo de polimorfismo em C++ pode ser a criação de uma 
classe abstrata "Animal", que possui um método virtual "fazerSom()" 
e duas classes derivadas "Cachorro" e "Gato" que implementam esse 
método de maneira diferente */

#include <iostream>
using namespace std;

// Classe abstrata Animal
class Animal {
public:
    virtual void fazerSom() = 0; // Método virtual puro
};

// Classe derivada Cachorro
class Cachorro : public Animal {
public:
    void fazerSom() override { // Implementação do método virtual
        cout << "O cachorro faz au au!" << endl;
    }
};

// Classe derivada Gato
class Gato : public Animal {
public:
    void fazerSom() override { // Implementação do método virtual
        cout << "O gato faz miau!" << endl;
    }
};

int main() {
    // Cria um ponteiro para Animal e duas instâncias de classes derivadas
    Animal *animal;
    Cachorro cachorro;
    Gato gato;
    
    // Atribui o ponteiro para a instância de Cachorro e chama o método fazerSom()
    animal = &cachorro;
    animal->fazerSom();
    
    // Atribui o ponteiro para a instância de Gato e chama o método fazerSom()
    animal = &gato;
    animal->fazerSom();
    
    return 0;
}