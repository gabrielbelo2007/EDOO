#include <iostream>
#include "article.h"
using namespace std;

Article::Article(long number, const string& name, double price): number(number), name(name), price(price){
    counter++;

    cout << "O artigo: *" << this->name << "* foi construído." << endl;
    cout << "Agora existem " << counter << " artigo(s)." << endl;
}

Article::~Article(){
    counter--;

    cout << "O artigo: *" << name << "* foi destruído." << endl;
    cout << "Ainda restam: " << counter << " artigos." << endl;
 }

void Article::display(){
    cout << name << ": (";
    cout << "number = " << number;
    cout << ", price = " << price << ")" << endl;
}

void Article::set_number(long number){
    this->number = number;
}

void Article::set_name(const string& name){
    this->name = name;
}

void Article::set_price(double price){
    if(price < 0.0){
        this->price = 0.0;
    }
    else{
        this->price = price;
    }
}



