#include <iostream>
#include <stdexcept>
#include "fraction.h"
using namespace std;

Fraction::Fraction(long numerator, long denominator) : numerator(numerator), denominator(denominator){

    if(denominator <= 0){
        throw invalid_argument("Denominador não pode ser menor ou igual a zero!");
    }

    this->numerator = numerator;
    this->denominator = denominator;

}

Fraction Fraction::operator-() const{
    return Fraction(-this->numerator, this->denominator);
};

Fraction& Fraction::operator--(){
    this->numerator -= this->denominator;
    return *this;
}

Fraction& Fraction::operator++(){
    this->numerator += this->denominator;
    return *this;
}

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

    return *this;
}

Fraction Fraction::operator+(long value){
    return *this += Fraction(value * this->denominator, value * this->denominator);
}

Fraction Fraction::operator-(long value){
    return *this -= Fraction(value * this->denominator, value * this->denominator);
}

Fraction Fraction::operator*(long value){
    return *this *= Fraction(value, 1);
}

Fraction Fraction::operator/(long value){
    return *this *= Fraction(1, value);
}

// Friend Functions:

ostream& operator<<(ostream& os, const Fraction& frac){
    os << frac.numerator << "/" << frac.denominator << endl;
    return os;
}

istream& operator>>(istream& is, Fraction& frac){
    is >> frac.numerator >> frac.denominator;
    return is;
}
Fraction operator+(long value, const Fraction& frac){
    Fraction frac1 = frac;
    return frac1 + value;
}

Fraction operator-(long value, const Fraction& frac){
    Fraction frac1 = frac;
    return frac1 - value;
}

Fraction operator*(long value, const Fraction& frac){
    Fraction frac1 = frac;
    return frac1 * value;
}

Fraction operator/(long value, const Fraction& frac){
    Fraction frac1 = frac;
    return frac1 / value;
}