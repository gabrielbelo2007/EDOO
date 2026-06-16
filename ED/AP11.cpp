#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Dict{

    private:

        vector<list<int>> hash_table;

        int hash(const int& value){
            return (value % 10);
        }

    public:

        Dict():hash_table(10){}

        void insert(int value){
            
            if(!find(value)){
                int position = hash(value);
                hash_table[position].push_back(value);
            }

        }

        bool find(const int& value){

            int position = hash(value);
            
            for(int elemento : hash_table[position]){
                if(elemento == value){
                    return true;
                }
            }

            return false;
        }

        void show(){
            for(int index = 0; index < 10; index++){
                cout << index << ": ";
                for(int elemento : hash_table[index]){
                    cout << elemento << " ";
                }
                cout << endl;
            }
        }

};

int main(){

    Dict open_hashing;

    int entries;
    cin >> entries;

    for(int entry = 0; entry < entries;  entry++){
        int new_value;
        cin >> new_value;

        open_hashing.insert(new_value);
    }
    
    open_hashing.show();

    return 0;
}