#include "retangulo.h"
#include "circulo.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

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
}
