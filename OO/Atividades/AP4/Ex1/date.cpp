#include <iostream>
#include "date.h"
using namespace std;

Date::Date(){
    this->day = 1;
    this->month = 1;
    this->year = 2026;
}

Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::display(){
    cout << day << '-' << month << '-' << year << endl;
}
