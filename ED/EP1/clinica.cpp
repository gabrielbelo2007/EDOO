#include <iostream>
#include <string>
#include <cctype>
using namespace std;

template <typename E>
class Node{
    public:
        Node* next;
        E element;

        // Construtor geral para elementos adicionados
        Node(const E& element, Node* next=nullptr){
            this->element = element;
            this->next = next;
        }

        // Construtor para header node
        Node(Node* next=nullptr){
            this->next = next;
        }
};

template <typename E>
class LQueue {

    private:

        Node<E>* front;
        Node<E>* rear;

    public:

        LQueue(){
            rear = front = new Node<E>();
        }

        ~LQueue(){};

        void add(const E& element, int index = -1){ // Enqueue
            
            if(index == -1){
                rear->next = new Node<E>(element, nullptr);
                rear = rear->next;
            }

            // Caso: Adicionar elemento em posição específica
            else{
                Node<E>* curr = front; 
                for(int i = 1; i <= (index-1); i++){ // Um nó antes da posição desejada
                    curr = curr->next; 
                }
            
                Node<E>* temp = curr->next;
                curr->next = new Node<E>(element, temp);
                if ( == nullptr) { rear = curr->next; }
            }
        }

        void next(){ // Dequeue
            if(front->next != nullptr){

                Node<E>* temp = front->next;
                if(rear == temp){ rear = front; }
        
                front->next = front->next->next;
                delete temp;
            }
        }

        void status(){
            Node<E>* curr = front;

            if(front->next == nullptr){
                cout << "---" << endl;
            }
            
            else{
                while(curr->next != nullptr){
                    cout << curr->next->element;

                    if (curr->next->next != nullptr){
                        cout << ", ";
                    }

                    curr = curr->next;
                }
                cout << endl;
            } 
        }
};

int main(){

    int casos;
    cin >> casos;

    for(int caso = 1; caso <= casos; caso++){

        LQueue<string> fila;
        cout << "caso " << caso << ':' << endl;

        int operacoes;
        cin >> operacoes;

        for(int num_operacao = 1; operacoes >= num_operacao; num_operacao++){

            string comando;
            string segundo_elemento; // numero ou nome

            cin >> comando;
            
            if (comando == "next"){
                fila.next();
            }

            else if (comando ==  "status"){
                fila.status();
            }
            
            else { // Add
                int set_index = 0;
                string nome;
                
                cin >> segundo_elemento;

                if(isdigit(segundo_elemento[0]) != 0){
                    set_index = stoi(segundo_elemento);
                    cin >> nome;
                }
                else{
                    nome = segundo_elemento;
                }

                if(segundo_elemento != nome){
                    fila.add(nome, set_index);
                }
                else{
                    fila.add(nome);
                }
            }
        }
    }
            
    return 0;
}