#include "retangulo.h"
#include <iostream>
#include <string>

Retangulo::Retangulo(const string& nome, double largura, double altura){
    this->nome = nome;

    if (largura <= 0 || altura <= 0){
        throw "A Largura e a Altura precisam ser positivas!";
    }
}

Retangulo& Retangulo::operator*=(const Retangulo& ret){
    this->altura *= ret.altura;
    this->largura *= ret.largura;
}

bool Retangulo::operator==(const Retangulo& ret) const{
    if(this->altura == ret.altura && this->largura == ret.altura){
        return true;
    }
    return false;
}

Retangulo Retangulo::operator+(long value) const{
    Retangulo temp = *this;
    temp.altura += value;
    temp.largura += value;

    if(temp.altura <= 0 || temp.largura <= 0){
        throw "Resultado de soma negativa não é permitido!";
    }
    return temp;
}

Retangulo Retangulo::operator*(long value) const{
    if (value <= 0){
        throw "Escala negativa não é permitida!";
    }

    Retangulo temp = *this;
    temp.altura *= value;
    temp.largura *= value;
    return temp;
}

bool Retangulo::operator<(const Retangulo& ret) const{
    if(this->area() < ret.area()){
        return true;
    }
    return false;
}

bool Retangulo::operator>(const Retangulo& ret) const{
    if(this->area() > ret.area()){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Retangulo& ret){
    os << ret.descricao();
    return os;
}