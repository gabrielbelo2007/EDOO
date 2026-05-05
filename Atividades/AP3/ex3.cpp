#include <iostream>
using namespace std;

long double factorial_loop (unsigned int number){

    long double result = 1;

    for(unsigned int i = number; i > 0; i--)
    {
        result *= i;
    }

    return result;
}

long double factorial_recursive (unsigned int number){

    long double result;

    if (number == 1){
        return 1;
    }

    result = factorial_recursive(number-1);

    result *= number;

    return result;
}

int main() {

    int number;

    cin >> number;
    
    cout << "Esse é o fatorial por loop: " << factorial_loop(number) << endl;
    cout << "Esse é o fatorial por recursão: " << factorial_recursive(number) << endl;

    return 0;
}