#include <iostream>
#include <locale.h>
#include <cstdlib>
#include "Veiculo.hpp"

using namespace std;
Veiculo::Veiculo(double precolitro, double consumototal,double capacidade_max, double quilometragem){
    this->precolitro=precolitro;
    this->capacidade_max=capacidade_max;
    this->consumototal=consumototal;
    this->litros=(capacidade_max/10);
    this->quilometragem=quilometragem;
}
int main(){
  setlocale(LC_ALL, "Portuguese");
  int opcao=0;

  cout<<"-----------Bem Vindo ao computador de Bordo-----------\n"<<endl;
  cout<<"Escolha uma opção: \n"<<endl;
  cout<<"1 - Cadastrar novo veículo-----------------------------"<<endl;
  cout<<"2 - Computador de Bordo BMW M5 V8 Turbo 2022-----------\n"<<endl;
  cout<<"Digite sua escolha: ";
  cin>>opcao;

  switch(opcao){
    case 1:{
        double percuso=0,p=0,l=0,cons=0,c=0;
        cout<<"Insira o consumo do Veículo:";
        cin>>cons;
        cout<<"Insira a capacidade do Veículo:";
        cin>>c;
        cout<<"Insira o preço do Litro:";
        cin>>p;
        Veiculo Veiculo(p, cons, c, 0);
        do{
        cout<<"Quantidade de Litros que deseja abastecer:";
        cin>>l;
        Veiculo.abastecimento(l);
        cout<<"Insira o percuso a ser feito:";
        cin>>percuso;
        cout<< "Autonomia do Veiculo: " << Veiculo.autonomia() <<" km"<<endl;
        if(Veiculo.PercorrerDistancia(percuso) == true){
        cout<<"A viagem pode ser realizada!"<<endl;
        cout<<"Quilometragem atualizada: "<< Veiculo.getQuilometragem() <<" km"<<endl;
        cout<<"Quantidade de Litros restantes: "<< Veiculo.getLitros() <<" litros"<<endl;
        }else{
            cout<<"A viagem não pode ser realizada"<<endl;
        }
        cout<<"\n\nDeseja Abastecer Mais uma Vez? \n1-SIM                    0-NÃO\n"<<endl;
        cout<<"Digite sua escolha: ";
        cin>>opcao;} while(opcao==1);
        break;
        }
    case 2:{
        double percuso=0,l=0;
        cout<<"Insira o consumo do Veículo: 3.5 km/l"<<endl;
        cout<<"Insira a capacidade do Veículo: 34 l"<<endl;
        cout<<"Insira o preço do Litro: R$ 4,50"<<endl;
        class Veiculo BMWM5(4.50, 3.5, 34, 0);
        do{cout<<"Quantidade de Litros que deseja abastecer:";
        cin>>l;
        BMWM5.abastecimento(l);
        cout<<"Insira o percuso a ser feito:";
        cin>>percuso;
        cout<< "Autonomia do Veiculo: " <<" km"<< BMWM5.autonomia() <<endl;
        if(BMWM5.PercorrerDistancia(percuso) == true){
        cout<<" A viagem pode ser realizada! \n"<<endl;
        cout<<"Quilometragem atualizada: "<< BMWM5.getQuilometragem() <<" km"<<endl;
        cout<<"Quantidade de Litros restantes: "<< BMWM5.getLitros() <<" litros"<<endl;
        }else{
            cout<<"A viagem não pode ser realizada"<<endl;
        }
        cout<<"\n\nDeseja Abastecer Mais uma Vez? \n1-SIM                    0-NÃO\n"<<endl;
        cout<<"Digite sua escolha: ";
        cin>>opcao;} while(opcao==1);
        break;
    }

    default:{
      cout<<"Opção inválida"<<endl;
    }
  }
  return 0;
 system("pause");
}
Veiculo::~Veiculo() { cout << "Objeto destruido" << endl;}
void Veiculo::setPreco(double precolitro){
    this->precolitro=precolitro;
}
double  Veiculo :: getPreco(){
    return this-> precolitro;
}
void Veiculo::setCapacidade(double capacidade_max){
    this->capacidade_max=capacidade_max;
}
double Veiculo::getCapacidade() {
    return this->capacidade_max;
}
void Veiculo::setLitros(double litros) {
  this->litros = litros;
}
double Veiculo::getLitros(){
  return this->litros;
}
void  Veiculo::setConsumoTotal(double consumototal) {
    this->consumototal=consumototal;
}
double Veiculo::getConsumoTotal(){
    return this->consumototal;
}
void Veiculo::setQuilometragem(double quilometragem){
    this->quilometragem = quilometragem;
}
double& Veiculo::getQuilometragem() {
    return quilometragem;
}
void Veiculo::setGastos(double totalgasto){
   this->totalgasto = totalgasto;
}
double Veiculo::getGastos() {
    return this->totalgasto;
}
double Veiculo::abastecimento(double qntdlitros){
    if( litros+qntdlitros <= capacidade_max){
        double valortotal= (precolitro * qntdlitros)*1.025;
        cout<<"O valor abastecido foi de  R$ "<<valortotal<<endl;
        litros+=qntdlitros;
        custos(qntdlitros);
        return valortotal;
    }else{
      cout<<"Não é possível abastecer um volume maior que a capacidade máxima do tanque"<<endl;
      return 0.0;
    }
}
void Veiculo::custos(double qntdlitros){
    double valorabast= (precolitro*qntdlitros);
  totalgasto=valorabast;
}
double Veiculo::autonomia(){
   return consumototal*this->litros;
}
bool Veiculo::PercorrerDistancia(double distancia) {
    if (distancia <= autonomia()) {
        this->quilometragem = quilometragem + distancia;
        this->litros = litros - (distancia / consumototal);
        return true;
    }
    else {
      return false;
    }
}
