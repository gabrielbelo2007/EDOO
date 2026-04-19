#include <iostream>
#include "article.h"

Article::Article(){
    number = 0;
    name = "";
    price = 0;
}

Article::Article(long number, const string& name, double price){
    this->number = number;
    this->name = name;
    this->price = price;
}

