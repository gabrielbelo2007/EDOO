#include <iostream>
using namespace std;

// Por referência (Recomendado)

void swap(float &p1, float &p2) {
    float temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
}

int main() {
    float x = 2.1;
    float y = 3.2;
    swap(x, y);
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}

/* 

Acessando os valores que os ponteiros apontam na memória com `*` (Operador de desreferenciação)

void swap(float *p1, float *p2) {
    float temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    float x = 2.1;
    float y = 3.2;
    swap(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}

*/