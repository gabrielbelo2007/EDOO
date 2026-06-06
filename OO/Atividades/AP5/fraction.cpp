#include <iostream>
#include <stdexcept>
#include "fraction.h"
using namespace std;

// Construtor
Fraction::Fraction(long numerator, long denominator){

    // Padrão de Fração: Numerador negativo, quando fração negativa
    if(denominator < 0){
        denominator = -denominator;
        numerator = -numerator;
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

// Sobrecarga de operadores
Fraction Fraction::operator-() const{
    // Const pois retorna uma cópia, sem mudar o original
    return Fraction(-(this->numerator), this->denominator);
};

Fraction& Fraction::operator--(){   
    this->numerator -= this->denominator;
    return *this;
}

Fraction& Fraction::operator++(){
    this->numerator += this->denominator;
    return *this;
}

// Construtor age implicitamente convertendo o valor recebido em uma fração com denominador 1
Fraction& Fraction::operator+=(const Fraction& frac){
    long new_denominator = this->denominator * frac.get_denominator();

    this->numerator = this->numerator * (new_denominator / this->denominator) + frac.get_numerator() * (new_denominator / frac.get_denominator());
    this->denominator = new_denominator;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& frac){
    long new_denominator = this->denominator * frac.get_denominator();

    this->numerator = this->numerator * (new_denominator / this->denominator) - frac.get_numerator() * (new_denominator / frac.get_denominator());
    this->denominator = new_denominator;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& frac){
    this->numerator *= frac.get_numerator();
    this->denominator *= frac.get_denominator();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& frac){
    this->numerator *= frac.get_denominator();
    this->denominator *= frac.get_numerator();

    if (this->denominator < 0){
        this->numerator = -(this->numerator);
        this->denominator = -(this->denominator);
    }

    return *this;
}

// Construtor age implicitamente convertendo o valor recebido em uma fração com denominador 1
Fraction Fraction::operator+(const Fraction &frac) const {
    Fraction temp = *this;
    temp += frac;
    return temp;
}

Fraction Fraction::operator-(const Fraction &frac) const {
    Fraction temp = *this;
    temp -= frac;
    return temp;
}

Fraction Fraction::operator*(const Fraction &frac) const {
    Fraction temp = *this;
    temp *= frac;
    return temp;
}

Fraction Fraction::operator/(const Fraction &frac) const{
    Fraction temp = *this;
    temp /= frac;
    return temp;
}

// Friend Functions: (Sobrecarga de operadores com objeto de outra classe na esquerda)

ostream& operator<<(ostream& os, const Fraction& frac){
    os << frac.numerator << "/" << frac.denominator << endl;
    return os;
}

istream& operator>>(istream& is, Fraction& frac){
    is >> frac.numerator >> frac.denominator;
    return is;
}

Fraction operator+(long value, const Fraction& frac){
    return frac + value;
}

Fraction operator-(long value, const Fraction& frac){ // Operador não comutativo
    return -(frac - value);
}

Fraction operator*(long value, const Fraction& frac){
    return frac * value;
}

Fraction operator/(long value, const Fraction& frac){ // Operador não comutativo
    return Fraction(value, 1) / frac;
}