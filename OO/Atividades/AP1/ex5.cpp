#include <iostream>
#include <string>
using namespace std;

int main(){

    string message = "I have learned something new again!";
    int len = message.length();

    cout << len << endl;

    string sentence1, sentence2;

    getline(cin, sentence1);
    getline(cin, sentence2);

    cout << sentence1 << "*" << sentence2 << endl;
 
    return 0;
}