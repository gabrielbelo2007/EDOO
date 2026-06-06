#include <string>
#include <iostream>
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

        Node(Node* next = nullptr){
            this->next = next;
        }
};

template <typename E>
class LList{

    private:
        Node<E>* head;
        Node<E>* curr; // Esse 'curr' sempre se posiciona na ultima letra adicionada
        Node<E>* tail;
        int count_elements;

        void init(){
            curr = head = tail = new Node<E>;
            count_elements = 0;
        }

    public:

        LList(){
            init();
        }

        void insert(const E& element){
            Node<E>* temp = curr->next; // Pode ser nullptr ou outro elemento
            curr->next = new Node<E>(element, temp);

            if(tail == curr){
                tail = curr->next;
            }

            curr = curr->next;

            count_elements++;
        }

        void moveToHead(){ curr = head; }
        void moveToTail(){ curr = tail; }

        void next(){
            if (curr != tail){
                curr = curr->next;
            }
        }

        void showChars() {
            curr = head;
            for (int i = 0; i < count_elements; i++){
                cout << curr->next->element;
                curr = curr->next;
            }
            cout << endl;
        }
};

int main(){

    string baiju_text;
    
    while(cin >> baiju_text){

        LList<char> final_text;
        for (char c : baiju_text){

            if(c == '['){ // Home -> vai para o inicio da lista
                final_text.moveToHead();
            }

            else if(c == ']'){ // End -> vai para o final da lista
                final_text.moveToTail();
            }
            
            else{
                final_text.insert(c);
            }
        }

        final_text.showChars();
    }

    return 0;
}