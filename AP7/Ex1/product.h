#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;

class Product{

    private:

        long barcode;
        string name;

    public:

        Product(long barcode = 0, string name = "Default");

        void setCode(long barcode);
        long getCode();

        void scanner();
        void printer();

};

inline long Product::getCode(){
    return barcode;
}

#endif PRODUCT_H