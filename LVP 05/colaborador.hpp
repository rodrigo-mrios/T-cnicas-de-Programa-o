#ifndef COLABORADOR_HPP
#include <iostream>
using namespace std;

class Colaborador{
  private:
  string nome;
  string cpf;
  int idade;
  int pontuacao;
  string estado;
  public:
  Colaborador(string nome,string cpf, int idade,int pontuacao);
  ~Colaborador();

//getters e setters
  void setNome(string nome);
  string getNome();
  void setCpf(string cpf);
  string getCpf();
  void setIdade(int idade);
  int getIdade();
  void setPontuacao(int pontuacao);
  int getPontuacao();
  bool verificarEstado(int pontuacao);
  void retornarEstado();
};

#endif