#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename E>
class AQueue{

    private:
        int maxSize; // Lidar com cheio e vazio
        int front;
        int rear;
        int count_elements = 0;
        E* queue_array;

    public:

        AQueue(int size_queue){
            maxSize = size_queue + 1;
            front = 1;
            rear = 0;
            queue_array = new E[maxSize];
        }

        ~AQueue() { delete[] queue_array; } // No caso do teste não precisa

        void enqueue(const E& element){
            if ((rear + 2) % maxSize != front){
                rear = (rear + 1) % maxSize;
                queue_array[rear] = element;
                count_elements++;
            }
        }

        E dequeue(){ // Fiz a verificação do vazio na main
            E element = queue_array[front]; 
            front = (front + 1) % maxSize;
            count_elements--;
            return element;
        }

        bool isEmpty(){
            return count_elements == 0;
        }

        const E& frontValue() const { // Fiz a verificação do vazio na main
            return queue_array[front];
        }
};

int main() {

    int tests_cases;
    cin >> tests_cases;

    vector<int> outputs;
    for(int i = 0; i < tests_cases; i++){

        int meters_size_ferry;
        int count_cars;

        cin >> meters_size_ferry;
        cin >> count_cars;

        int centimeters_size_ferry = meters_size_ferry * 100;
        // A solução de array ocupa bastante espaço
        AQueue<int> left_queue(count_cars);
        AQueue<int> right_queue(count_cars);

        for (int j = 0; j < count_cars; j++){

            int centimeters_size_car;
            string side_car;

            cin >> centimeters_size_car;
            cin >> side_car;
            
            if (side_car == "left"){
                left_queue.enqueue(centimeters_size_car);
            }
            
            else{
                right_queue.enqueue(centimeters_size_car);
            }

        }

        // Esvaziar as filas começando do "left" (par = "left", ímpar = "right")
        int travels = 0;
        int total_size = 0;
        for (int exited_cars = 0, side = 0; exited_cars < count_cars;){

            if(side % 2 == 0){
                if(!left_queue.isEmpty() && (total_size + left_queue.frontValue() <= centimeters_size_ferry)){
                    total_size += left_queue.dequeue();
                    exited_cars++;
                } 
                else{
                    travels++;
                    side++;
                    total_size = 0;
                }
            }

            else{
                if(!right_queue.isEmpty() && total_size + right_queue.frontValue() <= centimeters_size_ferry){
                    total_size += right_queue.dequeue();
                    exited_cars++;
                } 
                else{
                    travels++;
                    side++;
                    total_size = 0;
                }
            }
        }
        travels++; // Adicionar última viagem
        outputs.push_back(travels);
    }   

    for(int i : outputs){
        cout << i << endl;
    }

    return 0;
}