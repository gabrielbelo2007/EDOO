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
        long getCode() const;
        
        void scanner();
        void printer() const;

};

inline long Product::getCode() const{
    return barcode;
}

#endif