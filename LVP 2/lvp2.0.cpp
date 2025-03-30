#include <iostream>
#include <iomanip>
#define max_alunos 10
using namespace std;

int main(){
  float notas[max_alunos];
  int num_alunos=0;
  float media=0.0,soma=0.0;
  cout<<"Informe as notas dos alunos(insira um valor negativo para parar): "<<endl;
  for(int i=0;i<max_alunos;i++){
    cout<<"Nota do aluno "<<num_alunos+1<<": ";
    notas[i] = 0;
    cin>>notas[i];
    if (notas[i]<0){
      break;
  }
    num_alunos++;
    soma+=notas[i];
  }
  media=(soma/num_alunos);
  cout<<"Média = "<<setprecision(2)<<media<<endl;
  cout<<"Notas abaixo da média:"<<endl;
  for(int y=0;y<num_alunos;y++){
    if(notas[y]<media){
      cout<<notas[y]<<endl;
    }
  }
  return 0;
}