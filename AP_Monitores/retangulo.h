#ifndef RETANGULO_H
#define RETANGULO_H
#include "forma.h"
#include <string>
#include <iostream>
using namespace std;

class Retangulo : public Forma{

    private:
        double largura;
        double altura;

    public:
        Retangulo(const string& nome, double largura, double altura);
        double area() const;
        double perimetro() const;
        bool quadrado() const;

        Retangulo operator+(const Retangulo& ret) const;
        Retangulo operator*(double value) const;
        bool operator<(const Retangulo& ret) const;
        bool operator>(const Retangulo& ret) const;
        bool operator==(const Retangulo& ret) const;
        Retangulo& operator*=(double value);

        friend ostream& operator<<(ostream& os, const Retangulo& ret);
};
 
inline double Retangulo::area() const {
    return largura * altura;
}

inline double Retangulo::perimetro() const {
    return (largura * 2) + (altura  * 2);
}

inline bool Retangulo::quadrado() const{
    return largura == altura;
}

#endif