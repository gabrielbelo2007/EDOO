#include <iostream>
#include "product.h"
#include "freshfood.h"
#include "prefood.h"
using namespace std;

int main() {

    /* Teste: Product 
    Product p1(123, "Caderno");
    Product p2;

    p1.printer();
    p2.printer();

    p2.scanner();
    p2.printer();

    p2.setCode(222);
    cout << p2.getCode() << endl;
    */
    
    cout << "-----------" << endl;

    /* Teste: PrepackedFood
    PrepackedFood pf1(789, "Bala", 2);
    PrepackedFood pf2;

    pf1.printer();
    pf2.printer();

    pf2.scanner();
    pf2.printer();

    pf1.set_unit_price(4);
    cout << pf1.get_unit_price() << endl;
    */

    /* Teste: FreshFood */
    FreshFood ff1(777, "Peixe", 2, 30);
    FreshFood ff2;

    ff1.printer();
    ff2.printer();

    ff2.scanner();
    ff2.printer();

    ff1.set_price_kilo(28);
    cout << ff1.get_price_kilo() << endl;
    ff1.set_weight(3);
    cout << ff1.get_weight() << endl;

    return 0;
}
