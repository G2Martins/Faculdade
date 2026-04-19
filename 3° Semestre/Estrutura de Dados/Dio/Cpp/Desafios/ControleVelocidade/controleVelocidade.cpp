#include <iostream>
#include <string>

class Robo {
public:
    int velocidadeAtual = 0;
    int velocidadeMaxima;
    int velocidadeMinima;
    
    Robo(int vmin, int vmax) : velocidadeMinima(vmin), velocidadeMaxima(vmax) {
        velocidadeAtual = vmin;
    }
    
    void acelerar() {
        //TODO: Implementar a lógica especificada para o método "acelerar".
        if(velocidadeAtual < velocidadeMaxima){
            velocidadeAtual++;
        }
    }
    
    void desacelerar() {
        //TODO: Implementar a lógica especificada para o método "desacelerar".
        if(velocidadeAtual > velocidadeMinima){
            velocidadeAtual--;
        }
    }
};

int main() {
    int vmin, vmax;
    std::string comandos;
    
    std::cin >> vmin >> vmax;
    std::cin >> comandos;
    
    Robo robo(vmin, vmax);

    for (char comando : comandos) {
        //TODO: Considerar os comandos para invocar seu respectivo método.
        if (comando == 'A' || comando == 'a')
            robo.acelerar();
        else if (comando == 'D' || comando == 'd')
            robo.desacelerar();
    }
    std::cout << robo.velocidadeAtual << std::endl;
    return 0;
}