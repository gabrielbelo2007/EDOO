#include "retangulo.h"
#include <iostream>

Retangulo::Retangulo(const string& nome, double largura, double altura) : largura(largura), altura(altura){
    this->nome = nome;
}