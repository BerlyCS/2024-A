/*2. Defina una clase que utilice Templates para almacenar datos en un ´arbol binario. Inserte 1000 elementos sin
presentar problemas en tiempo de ejecuci´on. (se debe trabajar sin problemas con los datos int, float, double,
long y char ). Almacene los nodos hijos en un vector. Incluya una funci´on para mostrar en pantalla el ´arbol
de la mejor forma.*/
//USANDO CLASES
#include <cstddef>
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
    nodo<int>* itree = new nodo<int>(5);
    nodo<float>* ftree = new nodo<float>(1.9);
    nodo<char>* ctree = new nodo<char>('c');
    nodo<long>* ltree = new nodo<long>(1);
    nodo<double>* dtree = new nodo<double>(1.0);

    for (int i=0; i<1000; i++) {
        itree->insertar(rand()%1000);
        ftree->insertar(static_cast<float>(rand()/45793882.9));
        ctree->insertar(static_cast<char>(rand()%26+97));
        ltree->insertar(static_cast<long>(rand()%1000));
        dtree->insertar(static_cast<double>(rand()/78262342.4));
    }
    itree->InOrden();
    cout<<endl;
    ftree->InOrden();
    cout<<endl;
    ctree->InOrden();
    cout<<endl;
    ltree->InOrden();
    cout<<endl;
    dtree->InOrden();
}
