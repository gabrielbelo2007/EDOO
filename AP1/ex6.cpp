#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int number;
    int total = 0;

    for (int i=0; i<n; i++){
        cin >> number;
        total += number;
    }

    cout << "Average = " << total / n;
}