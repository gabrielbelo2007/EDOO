#ifndef RETANGULO_H
#define RETANGULO_H
#include "forma.h"
#include <string>
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