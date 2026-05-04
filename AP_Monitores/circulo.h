#include "forma.h"
#include <string>
using namespace std;

class Circulo : public Forma{

    private:
        double raio;

    public:
        Circulo(const string& nome, double raio);
        double area() const;
        double perimetro() const;
};

inline double Circulo::area() const{
    return 2*(raio*raio);
}

inline double Circulo::perimetro() const{
    return 2*3.14*raio;
}