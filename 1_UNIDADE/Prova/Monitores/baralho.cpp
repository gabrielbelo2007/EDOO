#include "baralho.h"
using namespace std;

Baralho::Baralho(int tamanho, string* cartas){
    string* cartas = new string[tamanho];
}

Baralho::~Baralho(){
    delete[] cartas;
}

string& Baralho::operator[](int i){
    if (i < 0 || i >= this->tamanho){
        throw "IndiceInvalidoException";
    }

    return this->cartas[i];
}

bool Baralho::operator==(const Baralho& bar) const{
    if(this->tamanho == bar.tamanho){

        for(int i = 0; i < tamanho; i++){

            if(this->cartas[i] != bar.cartas[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

// Friend Function
ostream& operator<<(ostream& os, const Baralho& bar){
    for (int i = 0; i < bar.tamanho; i++){
        os << bar.cartas[i];
    }
    return os;
}