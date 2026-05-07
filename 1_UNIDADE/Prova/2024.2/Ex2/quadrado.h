#include "figura.h"
#ifndef QUADRADO_H // If Not Defined - Evita mais de uma compilação
#define QUADRADO_H  // "define" aqui é o que permite usar o include

class Quadrado : public FiguraGeometrica{

    private:
        int lado;

    public:
        Quadrado(int x, int y, int lado) : FiguraGeometrica(x, y), lado (lado){};

        int get_lado() const;
        void set_lado(int lado);
        int area() override;
};

inline int Quadrado::get_lado() const{
    return this->lado;
}

#endif