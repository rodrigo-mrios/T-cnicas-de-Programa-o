#include "colaborador.hpp"

Colaborador::Colaborador(string nome, string cpf, int idade, int pontuacao){
  this->nome = nome;
  this->cpf = cpf;
  this-> idade = idade;
  this->pontuacao=pontuacao;
};
Colaborador:: ~Colaborador(){cout<<"Objeto destruido"<<endl;}
void Colaborador::setNome(string nome){
  this->nome=nome;}
string Colaborador::getNome(){
  return this->nome;
}
void Colaborador::setCpf(string cpf){
  this->cpf=cpf;}
string Colaborador::getCpf(){
  return this->cpf;
}
void Colaborador::setIdade(int idade){
  this->idade=idade;}
int Colaborador::getIdade(){
  return this-> idade;
}
void Colaborador::setPontuacao(int pontuacao){
  this->pontuacao=pontuacao;
}
int Colaborador::getPontuacao(){
  return this-> pontuacao;
}
bool Colaborador::verificarEstado(int pontuacao){
  if (pontuacao==100&&idade>22){
    this->estado ="Contratado";
    return true;
  }
  else {
    this->estado="Não Contratado";
    return false;
  }
}
void Colaborador::retornarEstado(){
  if(estado=="Contratado"){
    cout<<"Parabéns, você foi contratado"<<endl;
    cout<<"\n----------CONTRATO ADMISSIONAL----------\n"<<endl;
    cout<<"Nome: "<<this->nome<<"    CPF: "<<this->cpf<<endl;
    cout<<"Idade: "<<this->idade<<endl;
    cout<<"Salário: R$ 2000 + bonificações "<<endl;
    cout<<"Contratante: Rodrigo Rios"<<endl;
    cout<<"\n----------------------------------------"<<endl;
  }else{
  cout<<"Infelizmente você não se encaixa no padrão da nossa empresa."<<endl;
  cout<<"Obrigado por se interessar em nossa empresa, até logo!"<<endl;
  }
}