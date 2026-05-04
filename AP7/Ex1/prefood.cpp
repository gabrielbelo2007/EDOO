#include <iostream>
#include "prefood.h"
#include "product.h"

PrepackedFood::PrepackedFood(long barcode, string name, long unit_price) : Product(barcode, name), unit_price(unit_price){}

void PrepackedFood::set_unit_price(long unit_price){
    this->unit_price = unit_price;
}

void PrepackedFood::scanner() {
    Product::scanner(); // Chama o método da classe base

    cout << "Digite o valor da unidade: ";
    cin >> unit_price;

}

void PrepackedFood::printer() const {
    Product::printer();

    cout << "Valor da unidade: " << unit_price << endl;

}