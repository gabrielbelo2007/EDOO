#include "quadrado.h"

void Quadrado::set_lado(int lado){
    this->lado = lado;
}

int Quadrado::area(){
    return this->lado * this->lado;
}