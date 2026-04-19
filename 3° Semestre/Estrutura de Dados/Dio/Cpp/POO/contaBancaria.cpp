#include <iostream>
using namespace std;

class ContaBancaria{
    protected:
        double saldo;

    public:
        ContaBancaria(double saldo_conta){
            saldo = saldo_conta;
        }

    virtual void depositar (double valor){
        saldo += valor;
        cout << "Depósito de R$ " << valor << " Realizado. Novo Saldo: R$ "<< saldo << endl;
    }

    virtual void sacar (double valor) {
        if(saldo >= valor){
            saldo -= valor;
            cout  << "Saque de R$ " << valor << " Realizado. Novo Saldo: R$ " << saldo << endl;
        } else {
            cout << "Saldo Insuficiente para realizar saque."<< endl;
        }
    }
};

class ContaPoupanca : public ContaBancaria{
    private:
        double taxaJuros;

    public:
        ContaPoupanca(double saldo_conta, double taxa_juros) : ContaBancaria (saldo_conta) {
            taxaJuros =  taxa_juros;
        }
    
    void depositar(double valor) override {
        saldo += valor;
        cout << "Depósito de R$ " << valor << " Realizado na Conta poupanca. Novo Saldo: R$ "<< saldo << endl;
        saldo += saldo *taxaJuros;
        cout << "Juros de R$" << saldo * taxaJuros << "Adicionado a conta poupanca Novo Saldo: R$ " << saldo << endl;
    }
};

int main() {

    ContaBancaria* conta1 = new ContaBancaria(5000);
    ContaPoupanca* conta2 = new ContaPoupanca(2000, 0.05);

    conta1->depositar(1000);
    conta2->depositar(500);

    conta1->sacar(2000);
    conta2->sacar(10000);

    delete conta1;
    delete conta2;

    return 0;
}