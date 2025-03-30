#ifndef SISTEMA_INTERESTELAR_HPP
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct CorpoCeleste{
    string nomeCorpo;
    double raioCorpo,massaCorpo;
    string getNome()const{return nomeCorpo;}
    double getRaio()const{return raioCorpo;}
    double getMassa()const{return massaCorpo;}

    void setnome(const string&n){nomeCorpo= n;}
    void setraio(double r) {raioCorpo=r;}
    void setmassa(double m){massaCorpo = m;}
};

class Sistema_Interestelar{
    private:
        CorpoCeleste corpo1,corpo2;
        double distanciaCorpos,raiodomaispesado,massamaior;
        const double  G = 6.67e-11;
    public:
        void setdistancia(double d){
            distanciaCorpos=d;
            cin>>d;
            }
        void setinfo(){
            cout<<"Insira os dados do primeiro Corpo"<<endl;
            cout<<"Insira o nome do Corpo 1: ";
            cin.ignore();
            getline(cin,corpo1.nomeCorpo);
            cout<<"Insira a massa do Corpo 1: ";
            cin>>corpo1.massaCorpo;
            cout<<"Insira o raio do Corpo 1 em km: ";
            cin>>corpo1.raioCorpo;
            
            cout<<"Insira os dados do Segundo Corpo"<<endl;
            cout<<"Insira o nome do Corpo 2: ";
            cin.ignore();
            getline(cin,corpo2.nomeCorpo);
            cout<<"Insira a massa do Corpo 2: ";
            cin>>corpo2.massaCorpo; 
            cout<<"Insira o raio do Corpo 2 em km: ";
            cin>>corpo2.raioCorpo;

            if(corpo1.getMassa()>corpo2.getMassa()){
                massamaior=corpo1.massaCorpo;
                raiodomaispesado=corpo1.raioCorpo;
            }else {
                massamaior=corpo2.massaCorpo;
                raiodomaispesado=corpo2.raioCorpo;
                }
        }
        void getdistancia(){
            cout<<"Insira a distância entrer os Corpos:";
            cin>>distanciaCorpos;
        }
        void calcularFG(){
            double FG = G*corpo1.massaCorpo*corpo2.massaCorpo/pow(distanciaCorpos,2);
            cout<<"A força gravitacional entre os Corpos é de: "<<fixed << setprecision(2) << scientific << FG<<" N"<<endl;
        }
        void calcularcampo(){
            double CG = G*(massamaior/pow(raiodomaispesado,2));
            cout<<"O campo Gravitacional é de: "<<fixed << setprecision(2) << scientific << CG <<" m/s²"<<endl;
        }
        void velocidadeorbita(){
            double VO = sqrt(G*(massamaior/distanciaCorpos));
            cout<<"A Velocidade de Orbita do menor corpo em relação ao maior é: "<<fixed << setprecision(2) << scientific <<VO<<" km/s"<<endl;
        }
        void velocidadeescape(){
            double VE = sqrt((2*G*massamaior)/raiodomaispesado);
            cout<<"A Velocidade de escape é de: "<<fixed << setprecision(2) << scientific <<VE<<" km/s"<<endl;
        }
};
#endif