#include "triangulo.h"

void Triangulo::set_altura(int altura){
    this->altura = altura;
}

void Triangulo::set_base(int base){
    this->base = base;
}

int Triangulo::area(){
    return (this->altura * this->base)/2;
}
