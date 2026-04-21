#include <string>
#include "product.h"
#ifndef FRESHFOOD_H
#define FRESHFOOD_H
using namespace std;

class FreshFood : public Product{

    private:

        int weight;
        long price_kilo;

    public:

        FreshFood(long barcode, string name, int weight, long price_kilo);

};

#endif