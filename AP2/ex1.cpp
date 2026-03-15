#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double num = 0.123456;
    cout << left << setw(15) << num << endl;

    double num2 = 23.987;
    cout << right << setw(12) << fixed << setprecision(2) << num2 << endl;

    double num3 = -123.456;
    cout << right << setw(10) << scientific << fixed << setprecision(4) << num3 << endl;
 
    return 0;
}