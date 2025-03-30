#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

#define MAX_MUSICAS 13
#define MAX_PALAVRAS 4
using namespace std;

void transforma_str(string &str){ 
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = toupper(static_cast<unsigned char>(str[i]));
  }
};

struct Musica {
  string nome = "";
  string artista = "";
  int duracao = 0;
  string url = "";
};

Musica dadosmusicas[MAX_MUSICAS];
int main() {
  setlocale(LC_ALL, "Portuguese");
  string nome_jogador,linha[MAX_MUSICAS];
  ifstream musicas;

  musicas.open("musicas_iniciais.csv", ios::in);
  if (musicas.is_open()) {
    for (int i = 0; i < MAX_MUSICAS; i++) {
      getline(musicas, linha[i]);
    }
  } else {
    cout << "Arquivo não pode ser lido!" << endl;
    return 0;
  }

  for (int i = 0; i < MAX_MUSICAS; i++) {
    stringstream ss(linha[i]);
    string palavras[MAX_PALAVRAS], palavra;
    int contador = 0;
    while (getline(ss, palavra, ',') && contador < MAX_PALAVRAS) {
      palavras[contador++] = palavra;
    }  
    if (i > 0) {
      for (int j = 0; j < contador; j++) {
        dadosmusicas[i].nome = palavras[0];
        dadosmusicas[i].artista = palavras[1];
        dadosmusicas[i].duracao = stoi(palavras[2], nullptr, 16);
        dadosmusicas[i].url = palavras[3];
      }
    }
  }

  cout << "Jogo qual é a música carregado!" << endl;
  cout << "Quem é o jogador?\nR: ";
  getline(cin, nome_jogador);
  cout<<endl;

  int cont = 0, contador_tentativas = 0, acertou = 0, errou = 0;
  ofstream arquivo_jogador;
  arquivo_jogador.open("jogo_" + nome_jogador + ".txt", ios::out);
  arquivo_jogador << nome_jogador << " iniciou a partida..." << endl;
  while (cont <= 9) {
    string resposta, resultado;
    srand(time(NULL));
    int n = rand() % MAX_MUSICAS + 1;
    cout << cont + 1 << ". Qual a Musica? - "<< dadosmusicas[n].url << endl;
    cout << "Resposta " << cont+1 << ": ";
    cont++;
    getline(cin, resposta);
    transforma_str(resposta);
    transforma_str(dadosmusicas[n].nome);

    if (resposta == dadosmusicas[n].nome) {
      cout << "Certa Resposta!\n" << endl;
      acertou++;
      contador_tentativas = 1;
      resultado = "ACERTOU";
    }else if (resposta != dadosmusicas[n].nome) {
      cout << "Errado! Tente novamente\n" << endl;
      errou++;
      contador_tentativas++;
      resultado = "ERROU";
    }
    arquivo_jogador << nome_jogador << "," << resposta << ","<< contador_tentativas << "," << dadosmusicas[n].nome << ","<< resultado << endl;
    if (resposta == "") {
      cout << "Não pode ser vazio!\n" << endl;
    }
    if (acertou == 3) {
      cout << "Parabéns " << nome_jogador << " você ganhou!" << endl;
      arquivo_jogador << nome_jogador << " venceu o jogo!";
      break;
    } else if (errou == 3) {
      cout << "Sem tentativas restantes" << endl;
      cout << "Que pena " << nome_jogador << " você perdeu!" << endl;
      arquivo_jogador << nome_jogador << " foi derrotado";
      break;
    }
  }
  arquivo_jogador.close();
  musicas.close();

  return 0;
}