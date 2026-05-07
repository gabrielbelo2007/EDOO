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
        virtual ~Product();

        void setCode(long barcode);
        long getCode() const;
        
        virtual double get_price() const = 0;
        virtual void scanner();
        virtual void printer() const;

};

inline long Product::getCode() const{
    return barcode;
}

#endif