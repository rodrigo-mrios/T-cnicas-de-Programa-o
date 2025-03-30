#include <iostream>
#include <locale.h>
#include "Sistema_Interestelar.hpp"

using namespace std;

int main(){
    Sistema_Interestelar Sistema_Solar;
    Sistema_Solar.setinfo();
    Sistema_Solar.getdistancia();
    Sistema_Solar.calcularFG();
    Sistema_Solar.calcularcampo();
    Sistema_Solar.velocidadeorbita();
    Sistema_Solar.velocidadeescape();

    return 0;
}