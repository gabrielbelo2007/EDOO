#include "retangulo.h"
#include "circulo.h"
#include "template.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

    // Teste 1 - Polimorfismo
    /* 
    vector<Forma*> formas;
    formas.push_back(new Retangulo("R", 4, 3));
    formas.push_back(new Circulo("C", 2));
    for (auto f : formas){
        cout << f->descricao() << endl;
    }
       
    for (auto f : formas){
        delete f;
    }

    formas.clear();
    */

    // Teste 2 - Operadores
    /*
    Retangulo r1("R1", 2, 3);
    Retangulo r2("R2", 1, 1);
    r1 *= 2.5;
    cout << r1 << endl;
    cout << (r1 + r2) << endl;
    cout << (r1 * 2) << endl;
    */

    // Teste 3 - Template
    /*
    // Par<Retangulo, Circulo>
    Retangulo r1("R1", 3, 4);
    Circulo c1("C1", 5);

    Par<Retangulo, Circulo> p1(r1, c1);
    cout << p1 << endl;

    // invertido() gera Par<Circulo, Retangulo>
    Par<Circulo, Retangulo> p2 = p1.invertido();
    cout << p2 << endl;
    */

    // Teste 4 - Exceção
    try{
        Retangulo r2("R2", 1, 1);
        r2 *= -1;
    }
    catch(char const* error){
        cerr << error << endl;
    }
    
    try{
        Circulo c1("C1", -5);
    }
    catch(char const* error){
        cerr << error << endl;
    }
}
