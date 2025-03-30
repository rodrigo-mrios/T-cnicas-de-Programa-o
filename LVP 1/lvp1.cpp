#include <iostream>

using namespace std;

int main(){
    //Definindo variaveis
    float operando1=0.0,operando2=0.0,saida=0.0;
    string operador="";
    //Colocando entradas e saidas de dados
    cout<<"Informe o primeiro operando:";
    cin>>operando1;
    cout<<"Informe o segundo operando:";
    cin>>operando2;
    cout<<"Informe o operador(+,-,*ou/):";
    cin>>operador;

    if (operador == "+"){
            saida=(operando1+operando2);
            cout<<"Resultado da adicao= "<<saida;
    }else  if (operador =="-"){
            saida=(operando1-operando2);
            cout<<"Resultado da subtracao= "<<saida;
    }else if (operador =="*"){
            saida=(operando1*operando2);
            cout<<"Resultado da multiplicacao= "<<saida;
    }else  if (operador =="/"){
            if (operando2 !=0){
                saida=(operando1/operando2);
                cout<<"Resultado da divisao= "<<saida;
                }else{
                cout<<"Divisao por 0 invalida!";
            }
    }else{
        cout<<"\nOperador invalido";}

    return 0;
}
