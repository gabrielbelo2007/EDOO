#include <iostream>
#include <string>
#include "product.h"
#ifndef FRESHFOOD_H
#define FRESHFOOD_H
using namespace std;

class FreshFood : public Product{

    private:

        double weight;
        double price_kilo;

    public:

        FreshFood(long barcode = 44, string name = "FF_Default", double weight = 1, double price_kilo = 1);

        void set_weight(double weight);
        void set_price_kilo(double price_kilo);
        double get_weight();
        double get_price_kilo();

        void scanner() /* override */;
        void printer() const  /* override */;
};

inline double FreshFood::get_weight(){
    return weight;
}

inline double FreshFood::get_price_kilo(){
    return price_kilo;
}

#endif