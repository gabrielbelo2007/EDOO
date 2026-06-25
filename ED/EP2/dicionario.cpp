#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Dict{

    private:
        struct Par{
            int key;
            string value;
        };

        vector<list<Par>> hash_table;
        int load_factor;

        int hash(int key){
            return key % 10;
        }

    public:
        Dict() : hash_table(10){ // Tamanho fixo de 10
            load_factor = 0;
        }

        bool find(int key){
            int position = hash(key);

            for(Par objeto : hash_table[position]){
                if(objeto.key == key){
                    return true;
                }
            }

            return false;
        }

        void add(int key, string value){

            if(!find(key)){
                Par objeto;
                objeto.key = key;
                objeto.value = value;

                int position = hash(key);
                hash_table[position].push_back(objeto);
                load_factor++;
            }   
            
        }

        void remove(int key){

            if(find(key)){
                int position = hash(key);

                for(auto it = hash_table[position].begin(); it != hash_table[position].end(); it++){
                    if(it->key == key){
                        hash_table[position].erase(it);
                        break;
                    }
                }
                load_factor--;
            }

            if(find(key)){
                int position = hash(key);

                for(Par object : hash_table[position]){
                    if(object.key == key){
                        hash_table[position].remove(object);
                    }
                }
                load_factor--;
            }
        }

        const int get_load(){
            return load_factor;
        }

        void show(){
            for(int i = 0; i < 10; i++){
                cout << i << ":";

                int size = hash_table[i].size();
                for(Par objeto : hash_table[i]){

                    if(size > 1){
                        cout << "(" << objeto.key << "," << objeto.value << "),";
                        size--;
                    }
                    else{
                        cout << "(" << objeto.key << "," << objeto.value << ")";
                    }

                }
                cout << "\n";
            }
        }

};

int main(){

    int casos;
    cin >> casos;

    for(int caso = 1; caso <= casos; caso++){

        Dict dicionario;

        int operacoes;
        cin >> operacoes;

        for(int operacao = 0; operacao < operacoes; operacao++){

            string tipo_operacao;
            cin >> tipo_operacao;

            int key;
            cin >> key;

            if(tipo_operacao == "add"){
                string value;
                cin >> value;

                dicionario.add(key, value);
            }

            else if(tipo_operacao == "del"){
                dicionario.remove(key);
            }

        }

        cout << "caso " << caso << ":" << endl;
        cout << "alpha = " << dicionario.get_load() << "/" << 10 << endl;
        dicionario.show();
    }

    return 0;
}