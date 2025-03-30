#include <iostream>
#include "colaborador.hpp"
#include <locale.h>
using namespace std;

int Verificarrespostas(int resposta[],int gabarito[],int pontuacao){
  for(int i=0;i<4;i++){
  if(resposta[i]==gabarito[i]){
    pontuacao+=25;
    }
  }
  return pontuacao;
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    string nome="";
    string cpf="";
    int idade=0;
    int pontuacao=0;
    int gabarito[4]={2,2,2,1};
    int resposta[4];
    
    cout<<"----------Bem vindo a seleção de funionários----------\n"<<endl;
    cout<<"Siga o passo a passo para se cadastrar no nosso banco de dados:"<<endl;
    cout<<"Insira seu nome:";
    getline(cin,nome);
    cout<<"Insira seu CPF:";
    cin>>cpf;
    cout<<"Insira sua idade:";
    cin>>idade;
    cin.ignore();
    cout<<"\nCadastro realizado com sucesso!!"<<endl;
    cout<<"Agora vamos realizar uma prova de C++ para a seleção de funcionários\n"<<endl;
    cout<<"A estrutura Union pode atribuir e armazenar mais de um valor a um atributo por execução"<<endl;
    cout<<"Para Responder Digite 1 para verdadeiro e 2 para falso:"<<endl;
    cin>>resposta[0];
    cout<<"Ao determinarmos o comando 'cout<<fixed<<setprecision(2)<<endl' estamos arredondando um valor de float para inteiro"<<endl;
    cout<<"Para Responder Digite 1 para verdadeiro e 2 para falso:"<<endl;
    cin>>resposta[1];
    cout<<"Usando a biblioteca ctime podemos gerar um número aleatório a partir da função srand(time(0))"<<endl;
    cout<<"Para Responder Digite 1 para verdadeiro e 2 para falso:"<<endl;
    cin>>resposta[2];
    cout<<"Podemos utilizar estruturas como classes, struct e union em programação orientada a objeto"<<endl;
    cout<<"Para Responder Digite 1 para verdadeiro e 2 para falso:"<<endl;
    cin>>resposta[3];
    pontuacao=Verificarrespostas(resposta,gabarito,pontuacao); 
    cout<<"Sua pontuação foi: "<<pontuacao/25<<" acertos das 4 perguntas"<<endl;
    class Colaborador entrevistado(nome,cpf,idade,pontuacao);
    entrevistado.verificarEstado(pontuacao);
    entrevistado.retornarEstado();
    return 0;
}