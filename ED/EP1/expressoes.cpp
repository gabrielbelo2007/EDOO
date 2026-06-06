#include <iostream>
#include <string>
using namespace std;

template <typename E>
class Node{

    public:
        E element;
        Node* next;

        Node(const E& element, Node* next = nullptr){
            this->element = element;
            this->next = next;
        }

    // Não precisa de header node
};

template <typename E>
class LStack{
    
    private:
        Node<E>* top;
    
    public:
        
        LStack(){
            top = nullptr;
        }

        void push(const E& element){
            top = new Node<E>(element, top);
        }

        E pop(){
            E popped_element = top->element;
            Node<E>* temp = top;
            top = top->next;
            delete temp;
            return popped_element;
        }

};

int main(){

    string expressao;
    LStack<int> fila;
    int num_1, num_2;
    while(cin >> expressao){
        
        if (expressao == "EOF") {
            break;
        }

        else if(expressao != "*" && expressao != "+" && expressao != "-" && expressao != "END"){
            int numero = stoi(expressao);
            fila.push(numero);
        }

        else{
            if(expressao != "END"){
                num_1 = fila.pop();
                num_2 = fila.pop();
                int result;

                if(expressao == "*"){
                    fila.push(num_2 * num_1);
                }

                else if(expressao == "+"){
                    fila.push(num_2 + num_1);
                }

                else if(expressao == "-"){
                    fila.push(num_2 - num_1);
                }
            }

            else{ 
                cout << fila.pop() << endl;
            }

        }

    }
    
    return 0;
}