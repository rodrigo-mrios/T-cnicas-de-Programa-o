#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <sstream>

#define MAX_MUSICAS 13
#define MAX_PALAVRAS 4
using namespace std;

struct Musica{
    string nome="";
    string artista="";
    int duracao=0;
    string url="";
};
Musica dadosmusicas[MAX_MUSICAS];
// Função para Mostrar as Músicas no Programa
void mostrar_musicas(){
  for (int j = 0; j < MAX_MUSICAS; j++) {
    if(j>=1){
      cout << "Nome "<<j<<" : "<<dadosmusicas[j].nome << endl;
      cout << "Artista "<<j<<" : "<<dadosmusicas[j].artista << endl;
      cout << "Duração "<<j<<" : "<<dadosmusicas[j].duracao << endl;
      cout << "URL "<<j<<" : "<<dadosmusicas[j].url << endl;
    }
  }
};
int main() {
  setlocale(LC_ALL,"Portuguese");
  string nome_jogador;
  ifstream musicas;string linha[MAX_MUSICAS];
  musicas.open("musicas_iniciais.csv",ios::in);
  
  if(musicas.is_open()){
    for(int i=0;i<MAX_MUSICAS;i++){
      getline(musicas,linha[i]);
    }
  }
  else{
    cout<<"Arquivo não pode ser lido!"<<endl;
    return 0;
  }
  
  for(int i=0;i<MAX_MUSICAS;i++){
    stringstream ss(linha[i]);
    string palavras[MAX_PALAVRAS]; 
    string palavra;
    int contador = 0;
    while (getline(ss, palavra, ',') && contador < MAX_PALAVRAS) {
        palavras[contador++] = palavra;
    }if(i>0){
      for(int j=0;j<contador;j++){
      dadosmusicas[i].nome=palavras[0];
      dadosmusicas[i].artista=palavras[1];
      dadosmusicas[i].duracao=stoi(palavras[2],nullptr,16);
      dadosmusicas[i].url=palavras[3];
      }
    }
  }
  cout<<"Jogo qual é a música carregado!"<<endl;
  cout<<"Quem é o jogador?\nR:";
 getline(cin,nome_jogador);
  int cont=0,contador_tentativas=0,acertou=0,errou=0;
  ofstream arquivo_jogador;
  arquivo_jogador.open("jogo_"+nome_jogador+".txt",ios::out);
  arquivo_jogador<<nome_jogador<<" iniciou a partida..."<<endl;
  while(cont<=9){
    string resposta;
    string resultado;
    int n=rand() % MAX_MUSICAS + 1;
    cout<<contador_tentativas+1<<". Qual a Musica? - "<<dadosmusicas[n].url<<endl;
    cout<<"Tentativa "<<cont+1<<": ";
    cont++;
    getline(cin, resposta);
    if(resposta==dadosmusicas[n].nome){
      cout<<"Certa Resposta!"<<endl;
      acertou++;
      contador_tentativas=0;
      resultado="ACERTOU";
    }else if(resposta!=dadosmusicas[n].nome){
      cout<<"Errado! Tente novamente"<<endl;
      errou++;
      contador_tentativas++;
      resultado="ERROU";
    }
    arquivo_jogador<<nome_jogador<<","<< resposta<<","<<contador_tentativas<< ","<<dadosmusicas[n].nome<<","<<resultado<<endl;
    if(resposta==""){
      cout<<"Não pode ser vazio!"<<endl;
    }
    if(acertou==3){
      cout<<"Parabéns "<<nome_jogador<<" você ganhou!"<<endl;
      arquivo_jogador<<nome_jogador<<" venceu o jogo!";
      break;
    }else if(errou==3){
      cout<<"Sem tentativas restantes"<<endl;
      cout<<"Que pena "<<nome_jogador<<" você perdeu!"<<endl;
      arquivo_jogador<<nome_jogador<<" foi derrotado";
      break;
    }
  }
  arquivo_jogador.close();
  musicas.close();

  return 0;
}