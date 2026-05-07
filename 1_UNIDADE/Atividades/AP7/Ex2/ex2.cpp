#include <iostream>
#include "../Ex1/product.h"
#include "../Ex1/freshfood.h"
#include "../Ex1/prefood.h"
#include "islower.h"
using namespace std;

int main(){

    Product* products[3];

    products[0] = new Product;
    products[1] = new PrepackedFood;
    products[2] = new FreshFood;

    FreshFood* ff_pointer = new FreshFood;

    products[0]->printer();
    products[1]->printer();
    products[2]->printer();
    ff_pointer->printer();

    cout << "---------" << endl;

    (dynamic_cast<PrepackedFood*>(products[1]))->printer();
    (dynamic_cast<FreshFood*>(products[2]))->printer();
    (dynamic_cast<Product*>(ff_pointer))->printer();

    cout << "---------" << endl;
    
    Product& result = isLowerCode((*products[1]), (*products[2]));

    FreshFood* low_pointer_ff = dynamic_cast<FreshFood*>(&result);

    if(low_pointer_ff){
        low_pointer_ff->printer();
    }
    else{
        PrepackedFood* low_pointer_pf = dynamic_cast<PrepackedFood*>(&result);

        if (low_pointer_pf){
            low_pointer_pf->printer();
        }
        else{
            result.printer();
        }
    }

    for(int i = 0; i < 3; i++){
        delete products[i];
    }
    delete ff_pointer;
}

