#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Dict{

    private:

        struct Par{
            string key = "";
            int valor = 0;
            bool occuped = false;
        };
        
        vector<Par> hash_table;
        int total_occuped;
        int size;

        int hash(const string& key){

            unsigned int hash_key;

            unsigned int sum_chars = 0;
            int n = 1;
            for(char letter : key){
                sum_chars+= letter * n;
                n++;
            }

            hash_key = (19 * sum_chars) % 101;
            return hash_key;
        }

    public:
        Dict(int size) : hash_table(size){
            total_occuped = 0;
            this->size = size;
        }

        ~Dict(){}

        void insert(string key, int value = 0){
            if(find(key) == -1){ // Verifica se a key já existe

                unsigned int hash_key = hash(key);

                // j = 0 -> Sem colisão
                unsigned int index; 
                for(int j = 0; j < 20; j++){
                    index = (hash_key + (j*j) + 23*j) % 100;
                    
                    if(!hash_table[index].occuped){
                        hash_table[index] = {key, value, true};
                        total_occuped++;
                        break;
                    }
                }
            }
        }

        void remove(const string& key){
            int index = find(key);
            if(index != -1){
                hash_table[index].occuped = false;
                total_occuped--;
            }
        }

        int find(const string& key){
            unsigned int hash_key = hash(key);
            unsigned int index;
            
            for(int j = 0; j < 20; j++){
                index = (hash_key + (j*j) + 23*j) % 101;
                
                // Se o elemento for encotrado ele não pode ter sido deletado
                if(hash_table[index].key == key && hash_table[index].occuped){
                    return index;
                }
            }
            
            return -1;
        }

        int const total_keys() const { return total_occuped; }

        void print() const{

            int outputs = 0;
            int index = 0;
            while(outputs < total_occuped){
                if(hash_table[index].occuped){
                    cout << index << ":" << hash_table[index].key << endl;
                    outputs++;
                }
                index++;
            }
        }
};

int main() {

    int tests_cases;
    cin >> tests_cases;

    for(int test = 0; test < tests_cases; test++){

        Dict hash_table(100); // Tamanho fixo
        int operations;
        cin>>operations;
        for(int operation = 0; operation < operations; operation++){

            string line;
            cin>>line;

            string command = line.substr(0, 3);
            string key = line.substr(4);
            if(command == "ADD"){
                hash_table.insert(key);
            }
            else if (command == "DEL"){
                hash_table.remove(key);
            }
        }
        
        cout << hash_table.total_keys() << endl;
        hash_table.print();

    }

    return 0;
}