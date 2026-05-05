#include "splice.h"
using namespace std;

int* splice(int* arr1, int* arr2, unsigned int length_arr1, unsigned int length_arr2, int position){
    unsigned int full_size = length_arr1 + length_arr2;
    int* full_arr = new int[full_size];

    for(int i = 0, i_arr1 = 0; i < full_size; i++, i_arr1++){
        
        if(i == position){
            for(int i_arr2 = 0; i_arr2 < length_arr2; i_arr2++){
                full_arr[i] = arr2[i_arr2];
                i++;
            }

            full_arr[i] = arr1[i_arr1];
        }
        else{
            full_arr[i] = arr1[i_arr1];
        }
    }

    return full_arr;
}
