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
        unsigned int index;
    public:
        vect<X>() {
            size = 0;
            data = new X[size];
            index = 0;
        }
        ~vect<X>() {
            delete [] data;
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
        void operator++(int) {
            cout<<data[index++] << ' ';
            if (index == size) {
                index = 0;
            }
        }
};

int main() {
    vect<int> i;
    i.push_back(1);
    i.push_back(2);
    i.push_back(3);
    i.push_back(4);
    i.push_back(5);
    i.push_back(6);

    for (int p=0; p<i.length(); p++) {
        i++;
    }
}



