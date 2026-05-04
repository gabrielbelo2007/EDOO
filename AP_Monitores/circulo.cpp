#include "circulo.h"
#include <string>

Circulo::Circulo(const string& nome, double raio) : raio(raio){
    this->nome = nome;

    // if(raio <= 0){
    //     throw 
    // }
}