#include "figura.h"
#ifndef TRIANGULO_H
#define TRIANGULO_H

class Triangulo : public FiguraGeometrica{

    private:
        int altura;
        int base;

    public:
        Triangulo(int x, int y, int altura, int base) : FiguraGeometrica(x, y), altura(altura), base(base){};

        int get_altura() const;
        int get_base() const;
        void set_base(int base);
        void set_altura(int altura);
        int area() override;
};

inline int Triangulo::get_altura() const{
    return this->altura;
}

inline int Triangulo::get_base() const{
    return this->base;
}

#endif