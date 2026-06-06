#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int table_size = 10;

    cout << setw(4) << "";
    for (int i = 1; i <= 10; i++)
    {   
        // Horizontal Line
        cout << setw(4) << i;
    }
    cout << "\n";
    
    // Vertical Line
    for (int i = 1; i <= 10; i++)
    {
        cout << setw(2) << i << " >";
        
        // Table
        for(int j = 1; j <= 10; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << "\n";
    }
}