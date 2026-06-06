#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    long sec;
    time(&sec);
    srand( (unsigned) sec);

    char go = 's';
    
    int c_number;
    do{
        int attempts = 3;
        int r_random = (rand() % 15) + 1;

        while (attempts > 0)
        {   
            cout << "Try a number: " << endl;
            cin >> c_number;

            if (c_number == r_random){
                cout << "You win!" << endl;
                break;
            }

            else if (c_number > r_random){
                cout << "The number is smaller" << endl;
            }

            else if(c_number < r_random){
                cout << "The number is bigger" << endl;
            }

            attempts -= 1;
        }

        if (attempts == 0) 
        {
            cout << "You lose!" << endl;
        }

        cout << "You want to continue (s/n): ";
        cin >> go;

    } while (go == 's');
    
    return 0;
}