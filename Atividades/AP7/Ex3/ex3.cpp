#include <iostream>
#include "fraction.h"
using namespace std;

int main(){

    /*
    Fraction base = Fraction(1, 2);
    cout << base << endl;
    cout << -base << endl;
    cout << --base << endl;
    cout << ++base << endl;

    Fraction frac = Fraction(2, 3);

    base += frac;
    cout << base << endl;

    base -= frac;
    cout << base << endl;

    base *= frac;
    cout << base << endl;

    base /= frac;
    cout << base << endl;
    
    Fraction frac1;
    cin >> frac1;
    cout << frac1 << endl;
    
    cout << Fraction(2, 4) + 2 << endl;
    cout << 2 + Fraction(2, 4) << endl; // Friend Function

    cout << Fraction(2, 4) - 2 << endl;
    cout << 2 - Fraction(2, 4) << endl; // Friend Function

    cout << Fraction(2, 4) * 2 << endl;
    cout << 2 * Fraction(2, 4) << endl; // Friend Function

    cout << Fraction(2, 4) / 2 << endl;
    cout << 2 / Fraction(2, 4) << endl; // Friend Function
    */

    // 1) Tentativa de construtores
    try {
        Fraction frac(2,0);
    }
    catch (Fraction::DivError) {
        cerr << "Erro: Tentativa de construção de fração com 0 no denominador!" << endl;
    }

    // 2) Tentativa divisão por zero
    try {
        Fraction frac(1, 2);
        frac /= 0;
    }
    catch (Fraction::DivError){
        cerr << "Erro: Tentativa de divisão por zero!" << endl;
    }

    try {
        Fraction frac(1, 2);
        frac = frac / 0;
    }
    catch (Fraction::DivError){
        cerr << "Erro: Tentativa de divisão por zero!" << endl;
    }

    // 3) Leitura de numerador e denominador
    try {
        Fraction frac;
        cin >> frac;
    }
    catch (Fraction::DivError){
        cerr << "Erro: Não é possível ler uma fração com 0 no denominador!" << endl;
    }

    return 0;
}