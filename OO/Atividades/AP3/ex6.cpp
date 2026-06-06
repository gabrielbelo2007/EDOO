#include <iostream>
#include <iomanip>
using namespace std;
double x = 0.5,
fun(void);

int main() {

    while(x < 10.0){
        x += fun();
        cout << "\tWithin main(): " << setw(5) << x << endl;
    }

    return 0;
}

double fun() {
    static double x = 0; // A cada chamada o valor anterior é preservado
    cout << "Within fun(): " << setw(5) << x++; // 0

    return x;
}