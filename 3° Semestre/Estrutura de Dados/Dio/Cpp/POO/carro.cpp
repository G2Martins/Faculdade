/* Nesse exemplo, a classe Carro tem três atributos: marca, modelo e ano. 
Ela também tem três métodos: imprimirDados, que imprime os valores dos 
atributos na tela; e setMarca, setModelo e setAno, que permitem alterar 
os valores dos atributos.

No main(), criamos um objeto da classe Carro com a marca "Fiat", 
modelo "Uno" e ano 2010, e imprimimos seus dados na tela usando o 
método imprimirDados. Em seguida, usamos os métodos setMarca, setModelo 
e setAno para alterar os valores dos atributos do objeto, e imprimimos 
os novos dados na tela usando o método imprimirDados.

Espero que ajude a entender como trabalhar com atributos e métodos em C++! */


#include <iostream>
using namespace std;

class Carro {
  private:
    string marca;
    string modelo;
    int ano;

  public:
    Carro(string m, string mod, int a) {
      marca = m;
      modelo = mod;
      ano = a;
    }

    void imprimirDados() {
      cout << "Marca: " << marca << endl;
      cout << "Modelo: " << modelo << endl;
      cout << "Ano: " << ano << endl;
    }

    void setMarca(string m) {
      marca = m;
    }

    void setModelo(string mod) {
      modelo = mod;
    }

    void setAno(int a) {
      ano = a;
    }
};

int main() {
  Carro meuCarro("Fiat", "Uno", 2010);
  meuCarro.imprimirDados();
  meuCarro.setMarca("Chevrolet");
  meuCarro.setModelo("Onix");
  meuCarro.setAno(2021);
  meuCarro.imprimirDados();
  return 0;
}
