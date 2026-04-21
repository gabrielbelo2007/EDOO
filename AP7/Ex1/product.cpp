#include "product.h"

Product::Product(long barcode, string name): barcode(barcode), name(name){}

void Product::setCode(long barcode){
    this->barcode=barcode;
}
