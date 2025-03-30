#include <iostream>
#include <string>
#include <locale>
#define MAX_FUNCIONARIOS 5
using namespace std;

struct Funcionario{
    string nome_func="";
    double cpf=0;
    int numhoras=0;
    float valorhr=0.0, salario=0.0;
    
};

int main(){
    setlocale(LC_ALL,"Portuguese");
    
    int cont=0;
    float maiorsalario=0.0;
    string nome="";
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    for(int i=0;i<MAX_FUNCIONARIOS;i++){
        cont++;
        cout<<"Qual o nome do usuário ?"<<endl;
        cin>>funcionarios[i].nome_func;
        cout<<"Qual o número do CPF ?"<<endl;
        cin>>funcionarios[i].cpf;
        cout<<"Qual o número de horas trabalhadas ?"<<endl;
        cin>>funcionarios[i].numhoras;
        cout<<"Qual valor ?"<<endl;
        cin>>funcionarios[i].valorhr;
        funcionarios[i].salario=funcionarios[i].numhoras*funcionarios[i].valorhr;
    }
    /*for(int i=0;i<MAX_FUNCIONARIOS;i++){
        cout<<"Funcionário "<<i+1<<": "<<funcionarios[i].nome_func<<endl;
        cout<<"CPF : "<<funcionarios[i].cpf<<endl;
        cout<<"Horas Trabalhadas: "<<funcionarios[i].numhoras<<endl;
        cout<<"Valor da hora trabalhada: "<<funcionarios[i].valorhr<<endl;
        cout<<"Salário: "<<funcionarios[i].salario<<endl;
    }
    */
    for(int i=0;i<MAX_FUNCIONARIOS;i++){
        if(funcionarios[i].salario>maiorsalario){
            maiorsalario=funcionarios[i].salario;
            nome=funcionarios[i].nome_func;
        }
    }
    cout<<"O funcionário com o maior salário é "<<nome<<" que tem o salário: R$"<<maiorsalario<<endl;
return 0;
}