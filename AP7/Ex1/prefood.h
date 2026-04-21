#include <string>
#include "product.h"
#ifndef PREFOOD_H
#define PREFOOD_H
using namespace std;

class PrepackedFood : public Product{

    private:

        long unit_price;

    public:

        PrepackedFood(long barcodem, string name, long unit_price);

};

#endif