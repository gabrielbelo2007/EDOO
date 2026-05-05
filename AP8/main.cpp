#include <iostream>
#include <cctype>
#include "product.h"
#include "freshfood.h"
#include "prefood.h"
using namespace std;

void print_items(Product** product, int indice);

void record(char c){
    static Product* products[100]; // Array de Ponteiros
    static int indice = 0;
    char item;
    
    if (c == 'n'){
        if (indice > 0){
            print_items(products, indice);
            indice = 0;
        }
        cout << "Cliente Finalizado!" << endl;
    }

    else{
        cout << "Qual o tipo de item Prepacked[p] ou Fresh[f]: ";
        cin >> item;

        if (item  == 'p'){
            products[indice] = new PrepackedFood();
            products[indice]->scanner();
            products[indice]->printer();
            indice++;
        }

        else if (item == 'f'){
            products[indice] = new FreshFood();
            products[indice]->scanner();
            products[indice]->printer();
            indice++;
        }

        else {
            cout << "Escolha um item válido!" << endl;
        }
    }
}

void print_items(Product** product, int indice){

    double total = 0;

    for (int i = 0; i < indice; i++){
        product[i]->printer();
        total += product[i]->get_price();
        delete product[i];
    }

    cout << "Valor total: " << total << endl;
}

int main() {

    char resposta_item;
    char operacao;

    while(operacao != 'n'){
        while (resposta_item != 'n'){
            cout << "Deseja registrar um item: [s][n] ";
            cin >> resposta_item;
            resposta_item = tolower(resposta_item);

            if(resposta_item == 's' || resposta_item == 'n'){
                record(resposta_item);
            }
            
            else if(resposta_item != 'n'){
                cout << "Escreva uma ação válida!" << endl;
                continue;
            }
        }
        
        resposta_item = 's';
        cout << "Deseja atender um novo cliente? ";
        cin >> operacao;
    }
    cout << "Até mais! Gabs' Market." << endl;
    return 0;
}
