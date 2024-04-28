#include <iostream>
#include "GenericDynamicArray.hpp"
#include "GenericStaticArray.hpp"

using namespace std;

int main() {
    cout<<"Arreglo generico dinamico:"<<endl;
    GenericDynamicArray<int> vect_i;
    vect_i.push_back(4);
    vect_i.print();
    vect_i.push_back(2);
    vect_i.print();
    vect_i.remove(0);
    vect_i.print();
    vect_i.insert(0, 8);
    vect_i.print();
    cout<<vect_i.pop_back()<<endl;
    vect_i.print();

    cout<<"Arreglo generico estatico:"<<endl;
    GenericStaticArray<float, 5> vect_f;
    vect_f.set(2, 1.1);
    vect_f.set(0, 2.12);
    vect_f.set(1, 3.141933);
    vect_f.set(3, 129);
    vect_f.set(4, 320923);
    vect_f.print();
    cout<<vect_f.get(3)<<endl;
    cout<<vect_f.getsize()<<endl;
}
