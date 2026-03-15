#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    int seed;
    cin >> seed;

    srand(seed);

    for (int i = 0; i < 20; i++)
    {   
        int r_number = rand() % 101;
        cout << r_number << "\n";
    }

    return 0;
}