#include <iostream>
#include <algorithm>
using namespace std;

int* count_primes(int n);
int* make_list(int n);

int main(){
    int size = 1000;
    int* final_list = count_primes(size);

    for(int i = 0; i < size/2; i++){
        cout << final_list[i] << " ";
    }

    return 0;
}

int* count_primes(int n){

    int* numbers_list = make_list(n);
    int index = 0;
    int* end_list = numbers_list + n;

    int* primers = make_list(n/2);

    for(int k = 2, i = 0; k < n; k++){

        if(find(numbers_list, end_list, k) == end_list)
        {
            primers[i] = k;
            i++;

            for(int z = 1, f = 0; f < n; f = k * z, z++){

                if(find(numbers_list, end_list, f) == end_list){
                    numbers_list[index] = f;
                    index++;
                }
            }
        }
    }

    return primers;
}

int* make_list(int n){
    int* list_initializer = new int[n];

    for(int i = 0; i < n; i++)
    {
        list_initializer[i] = 0;
    }

    return list_initializer;
}
