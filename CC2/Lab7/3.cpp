/*
3. Sobrecargue el operador ++ para que permita imprimir uno a uno los elementos de un vector.
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
        int length() const {
            return size;
        }
        void operator++() {
            int p;
        }
};



