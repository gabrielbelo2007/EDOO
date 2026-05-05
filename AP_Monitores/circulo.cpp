#include "circulo.h"
#include <string>

Circulo::Circulo(const string& nome, double raio){
    this->nome = nome;

    if(raio <= 0){
        throw "O Raio precisa ser positivo!";
    }

    this->raio = raio;
}

Circulo& Circulo::operator*=(double value){
    if (value <= 0){
        throw "Escala nula ou negativa não é permitida!";
    }

    this->raio *= value;
    return *this;
}

bool Circulo::operator==(const Circulo& circ) const{
    if (this->area() == circ.area()){
        return true;
    }
    return false;
}

Circulo Circulo::operator+(double value) const{
    Circulo temp = *this;
    temp.raio += value;

    if (temp.raio <= 0){
        throw "Resultado de soma negativa não é permitido!";
    }
    return temp;
}

Circulo Circulo::operator*(double value) const{
    if (value <= 0){
        throw "Escala nula ou negativa não é permitida!";
    }

    Circulo temp = *this;
    temp.raio *= value;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Circulo& circ){
    os << circ.descricao();
    return os;
}