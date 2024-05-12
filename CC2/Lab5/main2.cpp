/*2. Defina una clase que utilice Templates para almacenar datos en un ´arbol binario. Inserte 1000 elementos sin
presentar problemas en tiempo de ejecuci´on. (se debe trabajar sin problemas con los datos int, float, double,
long y char ). Almacene los nodos hijos en un vector. Incluya una funci´on para mostrar en pantalla el ´arbol
de la mejor forma.*/
#include <cstdlib>
#include <iostream>
using namespace std;

template<typename T>
struct nodo {
    T value;
    nodo<T>* right;
    nodo<T>* left;

    nodo<T> (T val) : value(val), right(NULL), left(nullptr) {}
};

template<typename T>
void insertar(nodo<T>*& raiz, T val) {
    if (raiz == nullptr) {
        raiz = new nodo<T>(val);
    }

    else if (val < raiz->value ) {
        insertar(raiz->left, val);
    }
    else {
        insertar(raiz->right, val);
    }
}

template<typename T>
void InOrden(nodo<T>* raiz) {
    if (raiz != nullptr) {
        InOrden(raiz->left);
        cout << raiz->value << ' ';
        InOrden(raiz->right);
    }
}

int main() {
    nodo<int>* itree = new nodo<int>(5);
    nodo<float>* ftree = new nodo<float>(1.9);
    nodo<char>* ctree = new nodo<char>('c');
    nodo<long>* ltree = new nodo<long>(1);
    nodo<double>* dtree = new nodo<double>(1.0);

    for (int i=0; i<1000; i++) {
        insertar(itree, rand()%1000);
        insertar(ftree, static_cast<float>(rand()/45793882.9));
        insertar(ctree, char(rand()%26+97));
        insertar(ltree, static_cast<long>(rand()%1000));
        insertar(dtree, static_cast<double>(rand()/78262342.4));
    }
    InOrden(itree);
    cout<<endl;
    InOrden(ctree);
    cout<<endl;
    InOrden(ftree);
    cout<<endl;
    InOrden(ltree);
    cout<<endl;
    InOrden(dtree);
}
