#include <iostream>
#include "splice.h"
using namespace std;

int main(){

    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {60, 70, 80, 90};
    
    unsigned int length_arr1 = (sizeof(arr1)/sizeof(arr1[0]));
    unsigned int length_arr2 = (sizeof(arr2)/sizeof(arr2[0]));
    unsigned int total_size = length_arr1 + length_arr2;

    int* new_arr = splice(arr1, arr2, length_arr1, length_arr2, 2);

    for(int i = 0; i < total_size; i++){
        cout << new_arr[i];
    }

    

    return 0;
}