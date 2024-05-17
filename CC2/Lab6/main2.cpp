/*
 * Utilizando Polimorfismo, desarrolle un programa que permita calcular como m ́ınimo las operaciones de suma,
resta, multiplicaci ́on, divisi ́on y potencia. Tenga en consideraci ́on que las operaciones ser ́an dadas en una
linea de texto (Se considera incorrecto pedir valores num ́ericos y operadores por separado). Por ejemplo:
Operacion 0 : 7+3 * 5 - 2
Operacion 1 : -5*3*2 + 210 - 60/0.5
Operacion 2 : 34/2 * 50/5
Operacion 3 : -3 * -3 - 3 - -3.5

Tenga en consideraci ́on que los resultados deben de respetar la precedencia de operadores. Se tendr ́a pun-
tuaci ́on extra por agregar m ́as operadores al programa.
 */ 
#include <cstdlib>
#include <iostream>
using namespace std;

template<typename T>
class nodo {
public:
    T value;
    nodo<T>* right;
    nodo<T>* left;

    nodo<T> (T val) : value(val), right(NULL), left(NULL) {}
    
    void insertar(T val);
    void InOrden();
};

template<typename T>
void nodo<T>::insertar(T val) {
    if (val < value) {
        if (left == nullptr) {
            left = new nodo<T>(val);
        }
        else
            left->insertar(val);
    }
    else {
        if (right == nullptr) {
            right = new nodo<T>(val);
        }
        else {
            right->insertar(val);
        }
    }
}

template<typename T>
void nodo<T>::InOrden() {
    if (this != nullptr) {
        left->InOrden();
        cout << value << ' ';
        right->InOrden();
    }
}

int main() {
    nodo<char> *ctree;

    string expr = "2*3+5";
}
