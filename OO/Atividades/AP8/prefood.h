#include <string>
#include "product.h"
#ifndef PREFOOD_H
#define PREFOOD_H
using namespace std;

class PrepackedFood : public Product{

    private:

        long unit_price;

    public:

        PrepackedFood(long barcode = 111, string name ="PF_Default", long unit_price = 1);

        void set_unit_price(long unit_price);
        long get_unit_price();

        double get_price() const override;
        void scanner() override;
        void printer() const override;

};

inline long PrepackedFood::get_unit_price(){
    return unit_price;
}

inline double PrepackedFood::get_price() const {
    return unit_price;
}

#endif