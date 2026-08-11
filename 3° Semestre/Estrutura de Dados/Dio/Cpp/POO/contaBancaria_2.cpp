/*Neste exemplo, temos uma classe base chamada Conta, 
que define os membros comuns a todas as contas, como 
o nome do titular e o saldo. As funções virtuais depositar, 
sacar e mostrarSaldo são definidas na classe base e podem ser 
sobrescritas pelas classes derivadas ContaCorrente e ContaPoupanca.

A classe ContaCorrente redefine a função sacar, adicionando 
uma taxa de 0,10 a cada saque. A classe ContaPoupanca redefine 
a função depositar, aumentando o saldo em 5% a cada depósito.

Na função main, criamos uma instância de cada tipo de conta 
e fazemos algumas operações para demonstrar o funcionamento das 
funções virtuais. */


#include <iostream>
#include <string>

using namespace std;

// Classe base Conta
class Conta {
protected:
    string titular;
    double saldo;

public:
    Conta(string nome, double saldo_inicial) {
        titular = nome;
        saldo = saldo_inicial;
    }

    virtual void depositar(double valor) {
        saldo += valor;
    }

    virtual void sacar(double valor) {
        saldo -= valor;
    }

    virtual void mostrarSaldo() {
        cout << "Saldo atual: " << saldo << endl;
    }
};

// Classe derivada ContaCorrente
class ContaCorrente : public Conta {
public:
    ContaCorrente(string nome, double saldo_inicial) : Conta(nome, saldo_inicial) {}

    virtual void sacar(double valor) {
        saldo -= valor + 0.10;
    }
};

// Classe derivada ContaPoupanca
class ContaPoupanca : public Conta {
public:
    ContaPoupanca(string nome, double saldo_inicial) : Conta(nome, saldo_inicial) {}

    virtual void depositar(double valor) {
        saldo += valor * 1.05;
    }
};

int main() {
    // Cria uma ContaCorrente e faz algumas operações
    ContaCorrente contaCorrente("João", 5000);
    contaCorrente.mostrarSaldo();
    contaCorrente.sacar(500);
    contaCorrente.mostrarSaldo();

    // Cria uma ContaPoupanca e faz algumas operações
    ContaPoupanca contaPoupanca("Maria", 2000);
    contaPoupanca.mostrarSaldo();
    contaPoupanca.depositar(1000);
    contaPoupanca.mostrarSaldo();

    return 0;
}
