#include "Veiculo.hpp"

Veiculo::Veiculo(double precolitro, double consumototal,double capacidade_max, double quilometragem){
    this->precolitro=precolitro;
    this->capacidade_max=capacidade_max;
    this->consumototal=consumototal;
    this->litros=(capacidade_max/10);
    this->quilometragem=quilometragem;
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
