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
    */

    cout << Fraction(2, 4) + 2 << endl;
    cout << 2 + Fraction(2, 4) << endl; // Friend Function

    cout << Fraction(2, 4) - 2 << endl;
    cout << 2 - Fraction(2, 4) << endl; // Friend Function

    cout << Fraction(2, 4) * 2 << endl;
    cout << 2 * Fraction(2, 4) << endl; // Friend Function

    cout << Fraction(2, 4) / 2 << endl;
    cout << 2 / Fraction(2, 4) << endl; // Friend Function

    return 0;
}