#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {

    string message = "\nLearn from your mistakes!";
    cout << message << endl;

    int len = message.length();
    cout << "Length of the string: " << len << endl;

    int a, b;

    srand(12.5);

    a = rand();
    b = rand();

    cout << "\nRandom number: " << a << ", " << b << endl;

    return 0;
}