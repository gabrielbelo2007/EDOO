#include <iostream>
#include <stdexcept>
#include "fraction.h"
using namespace std;

// Construtor
Fraction::Fraction(long numerator, long denominator){

    if(denominator == 0){
        throw Fraction::DivError();
    }

    // Padrão de Fração: Numerador negativo, quando fração negativa
    if(denominator < 0){
        denominator = -denominator;
        numerator = -numerator;
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

// Sobrecarga de operadores
Fraction Fraction::operator-() const noexcept {
    // Const pois retorna uma cópia, sem mudar o original
    return Fraction(-(this->numerator), this->denominator);
};

Fraction& Fraction::operator--() noexcept {   
    this->numerator -= this->denominator;
    return *this;
}

Fraction& Fraction::operator++() noexcept{
    this->numerator += this->denominator;
    return *this;
}

// Construtor age implicitamente convertendo o valor recebido em uma fração com denominador 1
Fraction& Fraction::operator+=(const Fraction& frac) noexcept {
    long new_denominator = this->denominator * frac.get_denominator();

    this->numerator = this->numerator * (new_denominator / this->denominator) + frac.get_numerator() * (new_denominator / frac.get_denominator());
    this->denominator = new_denominator;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& frac) noexcept {
    long new_denominator = this->denominator * frac.get_denominator();

    this->numerator = this->numerator * (new_denominator / this->denominator) - frac.get_numerator() * (new_denominator / frac.get_denominator());
    this->denominator = new_denominator;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& frac) noexcept {
    this->numerator *= frac.get_numerator();
    this->denominator *= frac.get_denominator();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& frac){
    if (frac.get_numerator() == 0){
        throw Fraction::DivError();
    }

    this->numerator *= frac.get_denominator();
    this->denominator *= frac.get_numerator();

    if (this->denominator < 0){
        this->numerator = -(this->numerator);
        this->denominator = -(this->denominator);
    }

    return *this;
}

// Construtor age implicitamente convertendo o valor recebido em uma fração com denominador 1
Fraction Fraction::operator+(const Fraction &frac) const noexcept {
    Fraction temp = *this;
    temp += frac;
    return temp;
}

Fraction Fraction::operator-(const Fraction &frac) const noexcept {
    Fraction temp = *this;
    temp -= frac;
    return temp;
}

Fraction Fraction::operator*(const Fraction &frac) const noexcept {
    Fraction temp = *this;
    temp *= frac;
    return temp;
}

Fraction Fraction::operator/(const Fraction &frac) const {
    if (frac.get_numerator() == 0){
        throw Fraction::DivError();
    }
    Fraction temp = *this;
    temp /= frac;
    return temp;
}

// Friend Functions: (Sobrecarga de operadores com objeto de outra classe na esquerda)

ostream& operator<<(ostream& os, const Fraction& frac) noexcept {
    os << frac.numerator << "/" << frac.denominator << endl;
    return os;
}

istream& operator>>(istream& is, Fraction& frac) {
    int numerator, denominator;
    is >> numerator >> denominator;

    if (denominator == 0){
        cout << "Denominador não pode ser 0. Tente novamente: ";

        is >> denominator;

        if (denominator == 0){
            throw Fraction::DivError();
        }
    }

    frac.numerator = numerator;
    frac.denominator = denominator;
    return is;
}

Fraction operator+(long value, const Fraction& frac) noexcept {
    return frac + value;
}

Fraction operator-(long value, const Fraction& frac) noexcept { // Operador não comutativo
    return -(frac - value);
}

Fraction operator*(long value, const Fraction& frac) noexcept {
    return frac * value;
}

Fraction operator/(long value, const Fraction& frac) noexcept { // Operador não comutativo
    return Fraction(value, 1) / frac;
}