#include <iostream>
#include <iomanip>
const int max_alunos=10;
using namespace std;
int main(){
  float notas[max_alunos];
  float media=0.0,soma=0.0,nota=0.0;
  int n_alunos=0;
  cout<<"Informe as notas dos alunos(insira um valor negativo para parar): "<<endl;
  while(n_alunos<max_alunos){
    cout<<"Nota do aluno "<<n_alunos+1<<": ";
    cin>>nota;
    if (nota<0){ 
    break;
    }
    notas[n_alunos]=nota;
    soma+=nota;
    n_alunos++;
  }
  media=(soma/n_alunos);
  cout<<"Média = "<<setprecision(2)<<media<<endl;
  cout<<"Notas abaixo da média:"<<endl;
  for(int i=0;i<n_alunos;i++){
    if(notas[i]<media){
      cout<<notas[i]<<endl;
    }
  }
  return 0;
}