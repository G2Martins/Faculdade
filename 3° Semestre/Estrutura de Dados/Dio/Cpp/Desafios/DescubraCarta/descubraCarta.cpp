#include <iostream>
#include <string>

using namespace std;

enum Naipe {
    Paus = 0, Ouros = 1, Copas = 2, Espadas = 3
};
enum Valor {
    As = 1, Valete = 2, Dama = 3, Rei = 4
};



// Função para converter valor da enumeração em string
string valorToString(Valor v) {
    switch (v) {
        case As:
            return "Ás";
        case Valete:
            return "Valete";
        case Dama:
            return "Dama";
        case Rei:
            return "Rei";
        default:
            return "Valor Inválido";
    }
}

// Função para converter naipe da enumeração em string
string naipeToString(Naipe n) {
    switch (n) {
        case Paus:
            return "Paus";
        case Ouros:
            return "Ouros";
        case Copas:
            return "Copas";
        case Espadas:
            return "Espadas";
        default:
            return "Naipe Inválido";
    }
}

class Carta {
private:
    Naipe naipe;
    Valor valor;

public:
    Carta(Naipe n, Valor v) {
        naipe = n;
        valor = v;
    }

    Naipe getNaipe() {
        return naipe;
    }

    Valor getValor() {
        return valor;
    }
};

int main() {
    int valorEscolhido, naipeEscolhido;

    cin >> valorEscolhido;
    cin >> naipeEscolhido;

    // Tratamento de exceções
    if (valorEscolhido < 1 || valorEscolhido > 4 || naipeEscolhido < 0 || naipeEscolhido > 3) {
        cout << "Valor ou naipe da carta inválido!" << endl;
        return 1; // Saída do programa com código de erro
    }

    // Criação da carta escolhida pelo usuário usando "static_cast" para converter as escolhas.
    Carta cartaEscolhida(static_cast<Naipe>(naipeEscolhido), static_cast<Valor>(valorEscolhido));

    //TODO: Implementar as condições necessárias para impressão da saída deste desafio.
    cout << "Carta escolhida: " << valorToString(cartaEscolhida.getValor()) << " de " << naipeToString(cartaEscolhida.getNaipe()) << endl;

    return 0;
}