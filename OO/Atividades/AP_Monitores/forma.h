#ifndef FORMA_H
#define FORMA_H
#include <string>
using namespace std;

class Forma {

    protected:
        string nome;

    public:
        virtual ~Forma(){};
        virtual double area() const = 0; // Virtual Puro
        virtual double perimetro() const = 0;
        
        virtual string descricao() const{
            return this->nome + "| Area: " + to_string(this->area()) + "| Perimetro: " + to_string(this->perimetro());
        }
};

#endif
