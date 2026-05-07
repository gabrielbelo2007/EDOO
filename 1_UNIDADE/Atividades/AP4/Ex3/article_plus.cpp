#include <iostream>
#include "article_plus.h"
using namespace std;

int ArticlePlus::articles_counter = 0;

ArticlePlus::ArticlePlus(long number, const string& name, double price): number(number), name(name), price(price){
    articles_counter++;

    cout << "O artigo: *" << this->name << "* foi construído." << endl;
    cout << "Agora existem " << articles_counter << " artigo(s)." << endl;
}

ArticlePlus::ArticlePlus(const ArticlePlus &obj) : number(obj.number), name(obj.name + " copy"), price(obj.price){
    articles_counter++;

    cout << "O artigo é uma cópia: *" << name << "*." << endl;
    cout << "Agora existem " << articles_counter << " artigo(s)." << endl;
}

ArticlePlus::~ArticlePlus(){
    articles_counter--;

    cout << "O artigo: *" << name << "* foi destruído." << endl;
    cout << "Ainda restam: " << articles_counter << " artigos." << endl;
 }

void ArticlePlus::display(){
    cout << name << ": (";
    cout << "number = " << number;
    cout << ", price = " << price << ")" << endl;
}

void ArticlePlus::set_number(long number){
    this->number = number;
}

void ArticlePlus::set_name(const string& name){
    this->name = name;
}

void ArticlePlus::set_price(double price){
    if(price < 0.0){
        this->price = 0.0;
    }
    else{
        this->price = price;
    }
}



