#include <iostream>
#include "product.h"
using namespace std;

Product::Product(long barcode, string name): barcode(barcode), name(name){}

Product::~Product(){}

void Product::setCode(long barcode){
    this->barcode=barcode;
}

void Product::scanner(){
    cout << "Digite o nome do produto: ";
    cin >> name;
    cout << "Digite o código de barras: ";
    cin >> barcode;
}

void Product::printer() const{
    cout << "----Dados----" << endl;
    cout << "Nome do produto: " << name << endl;
    cout << "Cṍdigo do produto: " << barcode << endl;
}