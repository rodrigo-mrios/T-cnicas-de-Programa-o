#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include <vector>
#include <string>
using namespace std;

class Paciente{
private:
  string nome;
  string cpf;
  string n_atendimento;
  string motivo;

public:
  Paciente(string nome, string cpf, string n_atendimento, string motivo);
  void setNome(string nome);
  string getNome()const;
  void setCpf(string cpf);
  string getCpf();
  void setN_atendimento(string n_atendimento);
  string getN_atendimento()const;
  void setMotivo(string motivo);
  string getMotivo();
  void imprimir_dados()const;
};

class Hospital{
private:
  vector<Paciente> lista_espera;
  vector<Paciente> lista_atendidos;

public:  
  void setLista_espera(vector<Paciente> lista_espera);
  vector<Paciente> getLista_espera();
  void setLista_atendidos(vector<Paciente> lista_atendidos);
  vector<Paciente> getLista_atendidos();
  void adicionar_paciente(const Paciente& paciente);
  void atender_paciente();
  void imprimir_lista_espera(string posicao) const;
  void imprimir_lista_atendidos()const;
};
#endif