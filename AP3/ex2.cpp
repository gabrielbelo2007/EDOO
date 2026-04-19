#include <iostream>
#include <string>
using namespace std;

int main() {
    
    char go = 'S';

    while(go == 'S')
    {
        string word;
        cin >> word;

        bool palindrome = true;

        for(int i = 0, j = word.size() - 1; i < j; i++, j--)
        {
            if (word[i] != word[j])
            {
                palindrome = false;
            }
        }

        string text = palindrome ? "É um palíndromo!" : "Não é um palíndromo!";
        cout << text << endl;

        cout << "Aperte S para continuar e N para terminar: " << endl;
        cin >> go; 
    }
    return 0;
}