/*
aula 6  15-06-2026
POO Erika
*/

#include <iostream>
#include <string>

class ContaBanco
{

public:
    std::string titular;
    float saldo;

    ContaBanco(std::string nome, float saldoInicial)
    {
        titular = nome;
        saldo = saldoInicial;
    }

    void depositar(float valor)
    {
        if (valor > 0)
        {
            saldo += valor;
            std::cout << "Deposito de R$ " << valor << "  realizado. \n";
        }
    }

    void sacar(float valor)
    {
        if (valor > 0 && valor <= saldo)
        {
            saldo -= valor;
            std::cout << "Saque R$ " << valor << "realizado. \n";
        }
        else
        {
            std::cout << "Saldo indisponivel\n\n";
        }
    }

    void exibir()
    {
        std::cout << "Conta do titular: " << titular << " Saldo atual R$ " << saldo << "\n";
    }
};

int main()
{
    ContaBanco minhaConta("Andre Phylyp", 1000.0);

    minhaConta.depositar(380.00);

    minhaConta.sacar(2000.00);

    minhaConta.exibir();

    return 0;
}