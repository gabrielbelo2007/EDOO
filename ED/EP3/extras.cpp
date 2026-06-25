#include <list>
#include <vector>
#include <stack>
using namespace std;

int main(){

    vector<list<int>> array_num_lists(1000); // Cria um array de 1000 listas vazias
    list<int> num_lists;

    // Para o insert posição precisa ser um ponteiro
    num_lists.insert(num_lists.begin(), 10); // Posição, Valor
    num_lists.push_front(2); // Insere ao começo da lista
    num_lists.push_back(5); // Insere ao final da lista
    num_lists.remove(10); // Remove elemento da lista
    num_lists.empty(); // Verifica se a lista está vazia (true || false)

    // Método moderno
    for(int elemento : num_lists){
        if(elemento == 10){
            // cout << "Achou!";
        }
        // cout << "Não achou!";
    }

    // Método tradicional
    list<int>::iterator it;
    for(it = num_lists.begin(); it != num_lists.end(); it++){}
    
    stack<string> array_leaves;
    array_leaves.push("test"); // Adiciona ao topo
    array_leaves.pop(); // retira do topo
    array_leaves.empty(); // true = vazia

    return 0;
}