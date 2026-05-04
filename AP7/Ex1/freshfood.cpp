#include <iostream>
#include "product.h"
#include "freshfood.h"
using namespace std;

FreshFood::FreshFood(long barcode, string name, double weight, double price_kilo) : Product(barcode, name), weight(weight), price_kilo(price_kilo){}

void FreshFood::set_weight(double weight){
    this->weight = weight;
}

void FreshFood::set_price_kilo(double price_kilo){
    this->price_kilo = price_kilo;
}

void FreshFood::scanner() {
    Product::scanner(); // Chama o método da classe base

    cout << "Digite o peso do produto (kg): ";
    cin >> weight;
    cout << "Digite o preço por quilo: ";
    cin >> price_kilo;
}

void FreshFood::printer() const {
    Product::printer();

    cout << "Peso do produto: " << weight << endl;
    cout << "Preço por quilo: " << price_kilo << endl;
    cout << "Preço final: " << weight * price_kilo << endl;
}