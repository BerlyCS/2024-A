/*
1. Sobrecargue el operador coma para permitir inicializar un vector<T> con n valores. Por ejemplo:
Mylist<int> myList;
myList, 10, 20,30,40,50,60,70,1,2,3,6,7,8,9;
Debe de iniciar un vector<int> con cada uno de los valores separados en comas.
*/

#include <iostream>
using namespace std;

template <typename X>
class vect {
    private:
        X *data;
        unsigned int size;
    public:
        vect<X>() {
            size = 0;
            data = new X[size];
        }
        void push_back(X val) {
            X* tmp = new X[size+1];
            for (int i=0; i<size; i++) 
                tmp[i] = data[i];

            tmp[size] = val;
            delete[  ] data;
            data = tmp;
            size++;
        }
        void print() const {
            for (int i=0; i<size; i++) {
                cout<< data[i] << ' ';
            }
            cout<< endl;
        }
};

template <typename X>
vect<X>& operator,(vect<X>& a, X val) {
    a.push_back(val);
    return a;
}

int main() {
    vect<int> a;
    a, 10, 20, 30, 40, 50, 7, 8, 9, 3, 5 ,6 ,7;

    a.print();
}
