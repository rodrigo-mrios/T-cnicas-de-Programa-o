#include <iostream>
#include <locale.h>
#include "ContaBancaria.hpp"
using namespace std;
#define MAX_CONTAS 2

int main(){
    setlocale(LC_ALL,"Portuguese");
    string titular,senha;
    cout<<"------------Bem vindo ao Banco!--------------"<<endl;
    ContaBancaria cliente1, cliente2;
    cout<<"Qual o seu nome ?"<<endl;
    getline(cin,titular);
    cout <<"Digite uma senha:";
    cin>>senha;
    cout << "O número da sua conta é 001" << endl;

    cliente1.inicializar(titular,001,20.00);
    cliente1.setSenha(senha);

    cout<<"Qual o seu nome ?"<<endl;
    cin.ignore();
    getline(cin,titular);
    cout << "Digite uma senha:";
    cin>>senha;
    cout << "O número da sua conta é 002" << endl;
    cliente2.inicializar(titular,002,30.00);
    cliente2.setSenha(senha);
    cout << "Saldo na conta de " <<cliente1.getTitular()<<" é de R$: " << cliente1.consultarSaldo() << endl;
    cout << "Saldo na conta de " <<cliente2.getTitular()<<" é de R$: " << cliente2.consultarSaldo() << endl;
    float valorsaque;
    cout<<"Cliente "<<cliente1.getTitular()<<": Qual o valor do saque?"<<endl;
    cin >> valorsaque;
    cout<<"Digite a Senha:"<<endl;
    cin.ignore();
    cin>>senha;
    cliente1.realizarsaque(valorsaque,senha);

    cout<< "Cliente " <<cliente2.getTitular()<<": Qual o valor do saque?"<<endl;
    cin >> valorsaque;
    cout<<"Digite a Senha:"<<endl;
    cin.ignore();
    cin>>senha;
    cliente2.realizarsaque(valorsaque,senha);

    cout<<"Cliente "<<cliente1.getTitular()<<": Qual o valor do saque?"<<endl;
    cin >> valorsaque;
    cout<<"Digite a Senha:"<<endl;
    cin.ignore();
    cin>>senha;
    cliente1.realizarsaque(valorsaque,senha);
    cliente2.fazerdeposito(valorsaque);
    cout << "Saldo na conta de " <<cliente1.getTitular()<<" é de R$: " << cliente1.consultarSaldo() << endl;
    cout << "Saldo na conta de " <<cliente2.getTitular()<<" é de R$: " << cliente2.consultarSaldo() << endl;
return 0;
}