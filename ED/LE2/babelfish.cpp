#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dict{

    private:

        struct Par{
            string key = "";
            string value = "";
            bool occuped = false;
        };

        vector<Par> hash_table;
        int size;

        int hash(const string& key){
            int length = key.length()/4;
            unsigned int sum = 0;

            for(int i = 0; i < length; i++){
                string sub = key.substr(i*4, (i*4)+4);
                int mult = 1;

                for(int j = 0; j <= 3; j++){
                    sum += (sub[j] * mult);
                    mult *= 256;
                }
            }

            string sub = key.substr(length * 4);
            int mult = 1;
            int s = sub.length();
            for(int j = 0; j < s; j++){
                sum += (sub[j] * mult);
                mult *= 256;
            }

            return sum % this->size;
        }

        /*
        void rehash(){
            int new_size = (size * 2) < 100000 ? size * 2 : size = 100000;
            hash_table.resize(new_size);

            for(int i = 0; i < size; i++){
                insert(hash_table[i].key, hash_table[i].value);
            }

            this->size = new_size;
        }
        */

    public:
        
        Dict(int size) : hash_table(size){
            this->size = size;
        } 
        ~Dict(){}

        void insert(const string& key, const string& value){

            if(find(key) == ""){ // Verificação se elemento já foi adicionado
                int index = hash(key);

                while(hash_table[index].occuped){
                    index = (index + 1) % this->size;
                }

                hash_table[index].key = key;
                hash_table[index].value = value;
                hash_table[index].occuped = true;
            }
            /*
            // Confirmando que achou posicao valida
            if(!hash_table[index].occuped){ 
                hash_table[index].key = key;
                hash_table[index].value = value;
                hash_table[index].occuped = true;
            }

            // Se não tinha posição, faz o rehash
            else{
                rehash();
                insert(key, value); // Tenta inserir novamente
            }
            */
        }

        string find(const string& key){
            int index = hash(key);
            int start_index = index;

            while(hash_table[index].occuped){
                if(hash_table[index].key == key){
                    return hash_table[index].value;
                }
                index = (index + 1) % this->size;

                if(index == start_index){
                    break; // Checou tudo
                }
            }

            return ""; // Caso chave não encontrada
        }

};

int main(){
    
    Dict dict_lang(200000);
    string linha;
    while(getline(cin, linha) && !linha.empty()){
        int pos = linha.find(' ');
        string eng_word = linha.substr(0, pos);
        string stg_word = linha.substr(pos + 1);
        dict_lang.insert(stg_word, eng_word);
    }

    string palavra_estrangeira;
    while(cin >> palavra_estrangeira){

        string word = dict_lang.find(palavra_estrangeira);
        if(word != ""){
            cout << word << "\n";
        }
        else{
            cout << "eh\n";
        }
    }
    
    return 0;
}