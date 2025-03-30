#ifndef VEICULO_HPP
#include <iostream>

using namespace std;

class Veiculo{
    private:
        double precolitro,consumototal,litros,totalgasto;
        double capacidade_max;
        double quilometragem;

    public:
        Veiculo(double preco,double capacidade,double consumo ,double km);
        ~Veiculo();
        double getPreco();
        void setPreco (double precolitro);

        double getCapacidade ();
        void setCapacidade (double capacidade_max);

        double getConsumoTotal();
        void setConsumoTotal(double consumototal);

        double getLitros();
        void setLitros(double litros);

        double& getQuilometragem();
        void setQuilometragem(double quilometragem);

        double getGastos();
        void setGastos(double totalgasto);
            
        double abastecimento(double litros);

        void custos(double litros);
        double autonomia();
        bool PercorrerDistancia(double distancia);
        void distpercorrida(double distancia);
};
#endif