#include <iostream>
#include <locale>
#include <vector>
#include "hospital.hpp"
using namespace std;


int main() {
  Hospital hospital;
  int opcao=0;
  bool sistema = true;

  while(sistema){
    cout<<"\n------BEM VINDO AO SISTEMA DE ATENDIMENTO- HOSPITAL UNIVERSITÁRIO------\n"<<endl;
    cout << "1 - Adicionar paciente na fila de espera" << endl;
    cout << "2 - Atender paciente" << endl;
    cout << "3 - Imprimir posição do paciente na lista de espera" << endl;
    cout << "4 - Imprimir lista de pacientes atendidos" << endl;
    cout << "5 - Sair\n" << endl;
    cout << "Digite a opção desejada:";
    cin >> opcao;
    cout<<"\n";
    cin.ignore();
  switch(opcao){
    case 1:{
      string nome, cpf, n_atendimento, motivo;
      cout << "Digite o nome do paciente: ";
      getline(cin,nome);
      cout << "Digite o CPF do paciente: ";
      cin>>cpf;

      cin.ignore();
      
      cout << "Digite o número de atendimento: ";
      cin>>n_atendimento;
      
      cin.ignore();
      
      cout << "Digite o motivo da consulta: ";
      getline(cin,motivo);
      hospital.adicionar_paciente(Paciente(nome,cpf,n_atendimento,motivo));
      cout << "Paciente adicionado na fila de espera" << endl;
      break;}
    case 2:{
      hospital.atender_paciente();
      cout << "Paciente atendido" << endl;
      break;}
    case 3:{
      string posicao;
      cout << "Digite a posição do paciente na lista de espera: ";
      cin>>posicao;
      hospital.imprimir_lista_espera(posicao);
      break;}
    case 4:{
      hospital.imprimir_lista_atendidos();
      break;
    }
    case 5:{
        cout<<"Saindo do sistema"<<endl;
        sistema = false;
         break;
    }
    default:{
      cout << "Opção inválida" << endl;
      break;
      }
    }
  }
  return 0;
}