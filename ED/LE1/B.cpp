#include <iostream>
#include <vector>
using namespace std;

template <typename E>
class AStack{

    private:
        int maxSize; // Registrar o tamanho máximo que o "top" pode chegar
        int top;
        E* stack_array;

    public:

        AStack(int size){
            maxSize = size;
            top = 0;
            stack_array = new E[size];
        }

        ~AStack(){ delete[] stack_array; }

        void clear(){ top = 0; }

        void push(const E& element){
            if(top < maxSize){
                stack_array[top] = element;
                top++;
            }
        }

        E pop(){
            return stack_array[--top];
        }

        const E& topValue() const {
            return stack_array[top-1];
        }

        int length() const {
            return top;
        }
};

int main(){

    int n_vagoes;
    while(cin >> n_vagoes && n_vagoes != 0){

        while(true){ 
            vector<int> vagoes_desejados(n_vagoes);
            cin >> vagoes_desejados[0];
            
            if(vagoes_desejados[0] == 0){
                break;
            }

            for(int i = 1; i < n_vagoes; i++){
                cin >> vagoes_desejados[i];
            }

            AStack<int> tremA(n_vagoes); 
            
            // ptr_vagao_desejado = indice do vector de vagoes_desejados
            // Vagao_atual = vagao que chega em A
            for(int vagao_atual = 1, ptr_vagao_desejado = 0; vagao_atual <= n_vagoes; vagao_atual++){
                tremA.push(vagao_atual);

                while(tremA.length() > 0 && tremA.topValue() == vagoes_desejados[ptr_vagao_desejado]){
                    tremA.pop();
                    ptr_vagao_desejado++;
                }
            }
            
            if(tremA.length() == 0){
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }

        cout << endl;
    }
    
    return 0;
}