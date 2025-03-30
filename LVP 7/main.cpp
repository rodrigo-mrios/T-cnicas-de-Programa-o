#include "Tesouro_Direto.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string nome = "";
    double saldo = 0, novoSaldo = 0;
    
    cout << "Insira o nome do cliente 1: ";
    getline(cin, nome);

    cout << "Insira o valor a ser depositado do poupador 1: ";
    cin >> saldo;

    TesouroDireto cliente1(nome, 1, saldo, novoSaldo);

    cin.ignore();

    cout << "Insira o nome do cliente 2: ";
    getline(cin, nome);

    cout << "Insira o valor a ser depositado do poupador 2: ";
    cin >> saldo;

    TesouroDireto cliente2(nome, 2, saldo, novoSaldo);
    cout << setprecision(2) << fixed;
    cout << "Primeiro mês" << endl;

    cout << "Renda mensal do poupador 1: " << cliente1.rendaMensal() << endl;
    cout << "Renda mensal do poupador 2: " << cliente2.rendaMensal() << endl;

    cout << "Segundo mês" << endl;

    cout << "Nova renda mensal do poupador 1: " << cliente1.novaRenda() << endl;
    cout << "Nova renda mensal do poupador 2: " << cliente2.novaRenda() << endl;

    return 0;
}