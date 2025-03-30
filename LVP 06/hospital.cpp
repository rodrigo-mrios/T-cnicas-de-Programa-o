#include "hospital.hpp"
#include <iostream>


Paciente::Paciente(string nome, string cpf, string n_atendimento, string motivo){
  this->nome = nome;
  this->cpf = cpf;
  this->n_atendimento = n_atendimento;
  this->motivo = motivo;
}

void Paciente::setNome(string nome){this->nome = nome;}
string Paciente::getNome()const{return this->nome;}
void Paciente::setCpf(string cpf){this->cpf = cpf;}
string Paciente::getCpf(){return this->cpf;}
void Paciente::setN_atendimento(string n_atendimento){this->n_atendimento = n_atendimento;}
string Paciente::getN_atendimento()const{return this->n_atendimento;}
void Paciente::setMotivo(string motivo){this->motivo = motivo;}
string Paciente::getMotivo(){return this->motivo;}
void Paciente::imprimir_dados()const{
  cout << "Nome: " << this->nome << endl;
  cout << "CPF: " << this->cpf << endl;
  cout<< "Número de atendimento: " << this->n_atendimento <<endl;
  cout << "Motivo: " << this->motivo << endl;
  cout<<"\n";
}


void Hospital::setLista_espera(vector<Paciente> lista_espera){this->lista_espera=lista_espera;}
vector<Paciente> Hospital::getLista_espera(){return this->lista_espera;}
void Hospital::setLista_atendidos(vector<Paciente> lista_atendidos){this->lista_atendidos=lista_atendidos;}
vector<Paciente> Hospital::getLista_atendidos(){return this->lista_atendidos;}
void Hospital::adicionar_paciente(const Paciente& paciente){
  lista_espera.push_back(paciente);
}
void Hospital::atender_paciente(){
  if(lista_espera.size() > 0){
    Paciente pacienteatendido =lista_espera.front();
    lista_atendidos.push_back(pacienteatendido);
    lista_espera.erase(this->lista_espera.begin());
  }
}
void Hospital::imprimir_lista_espera(string posicao) const{
  bool existe = false;
  for(const auto& paciente : lista_espera){
    if(paciente.getN_atendimento() == posicao || paciente.getNome() == posicao){
      paciente.imprimir_dados();
      existe = true;
      break;
    }
  }
  if(!existe){ 
    cout << "Não existe paciente com essa posição" << endl;}
}
  
void Hospital::imprimir_lista_atendidos()const{
  if(lista_atendidos.empty()){
    cout << "Não há pacientes atendidos" << endl;
  }
  else{
    for(const auto& paciente : lista_atendidos){
      paciente.imprimir_dados();
    }
  }
} 