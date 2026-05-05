#include "circulo.h"
#include <string>

Circulo::Circulo(const string& nome, double raio){
    this->nome = nome;

    if(raio <= 0){
        throw "O Raio precisa ser positivo";
    }

    this->raio = raio;
}