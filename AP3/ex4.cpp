#include <iostream>
#include <iomanip>
using namespace std;
int var = 0;
namespace Special { int var = 100; }

int main() {
    int var = 10;
    cout << setw(10) << var; // 10
    {
        int var = 20;
        cout << setw(10) << var << endl; // 20
        {
            ++var;
            cout << setw(10) << var; // 21
            cout << setw(10) << ++ ::var; // 1
            cout << setw(10) << Special::var * 2 << endl; // 200
        }
        
        cout << setw(10) << var - ::var; // 20
    }
    cout << setw(10) << var << endl; // 10
    return 0;
}