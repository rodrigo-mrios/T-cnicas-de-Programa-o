#ifndef CONTABANCARIA_HPP
#include  <iostream>
using namespace std;

class ContaBancaria{
    private: 
        string nome_titular,senha;
        float saldo; 
        int conta;
    public: 
        void setTitular(string t){nome_titular = t;}
        string getTitular() {return nome_titular;}
        void setSenha(string s){senha = s;}
        void setConta(int v){conta = v;}
        bool verificarsenha(string s){return (s == senha);}
        void setSaldo(float s){saldo=s;}
        void inicializar(string n, int v, float i){
            setTitular(n); 
            setConta(v); 
            setSaldo(i);
            }
        void realizarsaque(float valor,string senha_inserida){
            while(!verificarsenha(senha_inserida)){
                cout<<"Senha incorreta!Digite Novamente:"<<endl;
                cin>>senha_inserida;
            }
            if(saldo>=valor){
                saldo-=valor;
                cout<< "Saque de R$ "<<valor<<" realizado com sucesso"<<endl;
            }else{
                cout << "Saldo insuficiente para o saque."<< endl;
            }
        }
        void fazerdeposito(float valor) {
        saldo += valor;
        cout << "Depósito de R$ " << valor << " realizado com sucesso na conta de "<<nome_titular<<"." << endl;
        }
        float consultarSaldo() {
            return saldo;
        }
};
#endif