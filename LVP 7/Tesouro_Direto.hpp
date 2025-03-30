#ifndef TESOURO_DIRETO_HPP
#define TESOURO_DIRETO_HPP

#include <string>
using namespace std;

class TesouroDireto {
private:
    static double taxaSelic;
    static double novaTaxaSelic;

public:
    string nome;
    int conta;
    double saldo;
    double novoSaldo;

    TesouroDireto(string nome, int conta, double saldo, double novoSaldo);

    double rendaMensal();

    double novaRenda();
};

#endif