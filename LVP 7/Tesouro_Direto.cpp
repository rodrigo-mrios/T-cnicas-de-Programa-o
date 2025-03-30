#include "Tesouro_Direto.hpp"

using namespace std;

double TesouroDireto::taxaSelic = 0.1375;

TesouroDireto::TesouroDireto(string nome, int conta, double saldo, double novoSaldo) : nome(nome), conta(conta), saldo(saldo), novoSaldo(novoSaldo) {}

double TesouroDireto::rendaMensal() {
    double renda = saldo + saldo * (taxaSelic / 12) - (0.003 * saldo);
    return renda;
}

double TesouroDireto::novaTaxaSelic = 0.1325;

double TesouroDireto::novaRenda() {
    novaTaxaSelic = 0.1325;
    novoSaldo = saldo + saldo * (taxaSelic / 12) - (0.003 * saldo);
    double rendaNova = novoSaldo + novoSaldo * (novaTaxaSelic / 12) - (0.003 * novoSaldo);
    return rendaNova;
}