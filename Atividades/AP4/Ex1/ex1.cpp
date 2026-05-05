#include <iostream>
#include "date.h"

int main(){

    Date basic_date;
    Date change_date(10, 4, 2026);

    basic_date.display();
    change_date.display();

    return 0;
}