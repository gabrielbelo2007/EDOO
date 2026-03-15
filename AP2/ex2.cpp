#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    char ch;
    string word;

    cout << "Let's go! Presse the return key: ";
    cin >> ch;

    cout << "Enter a word containing three characters at most: ";
    cin >> setw(3) >> word;
    cout << "Your input: " << word << endl;

    return 0;
}