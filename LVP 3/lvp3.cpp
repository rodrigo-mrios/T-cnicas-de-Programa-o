#include <iostream>
using namespace std;

int inverte_digitos(int numero_inicial=0){
    int invertido=0,digito=0;
    while(numero_inicial>0){
        digito= numero_inicial%10;
        invertido = (invertido * 10) + digito;
        numero_inicial/=10;
    }
    return invertido;
}
int main(){
    int numero=0, resultado=0;
    cout<<"Informe um inteiro positivo para ser invertido: ";
    cin>>numero;
    resultado=inverte_digitos(numero);
    cout<<"Número invertido: "<<resultado;

    return 0;
}