#include "min.h"

int min(unsigned int* arr, unsigned int size){
    unsigned int smallest_number = arr[0];

    for(int i = 0; i < size; i++){

        if(smallest_number > arr[i] && arr[i] != 0){
            smallest_number = arr[i];
        }
    }

    return smallest_number;
}