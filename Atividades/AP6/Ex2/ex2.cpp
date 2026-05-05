#include <iostream>
#include "min.h"
using namespace std;

int main(){

    unsigned int arr[] = {100, 90, 80, 70, 120, 0};

    cout << min(arr, (sizeof(arr)/sizeof(arr[0]))) << endl;

    return 0;
}