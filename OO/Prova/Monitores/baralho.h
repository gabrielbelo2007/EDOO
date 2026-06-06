#include <string>
#ifndef BARALHO_H
#define BARALHO_H
using namespace std;

class Baralho {

    protected: 
        int tamanho;
        string* cartas;

    public:
        Baralho(int tamanho, string* cartas);
        virtual ~Baralho();

        string& operator[](int i);
        bool operator==(const Baralho& bar) const;

        friend ostream& operator<<(ostream& os, const Baralho& bar);

        virtual void embaralhar(int i) = 0;
};

#endif