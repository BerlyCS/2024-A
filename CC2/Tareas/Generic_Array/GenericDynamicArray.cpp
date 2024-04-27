#include "GenericDynamicArray.h"
#include <iostream>
using namespace std;

template <typename T>
int GenericDynamicArray<T>::getsize() {
    return this->size;
}

template <typename T>
GenericDynamicArray<T>::GenericDynamicArray() {
    size=0;
    data = new T[size];
}

template <typename T>
GenericDynamicArray<T>::GenericDynamicArray(GenericDynamicArray<T> &b) {
    size = b.getsize();
    data = new T[size];

    for (int i=0; i<size; i++) {
        data[i] = b.data[i];
    }
}

template <typename T>
GenericDynamicArray<T>::~GenericDynamicArray(){
    delete[] data; 
}

template <typename T>
void GenericDynamicArray<T>::push_back(T val) {
    T* tmp = new T[size + 1];
    for (int i=0; i<size; i++) {
        tmp[i] = data[i];
    }
    tmp[size] = val;
    size++;
    delete[] data;
    data = tmp;
}

template <typename T>
T GenericDynamicArray<T>::pop_back() {
    T* tmp= new T[size -1];
    for (int i=0; i<size-1; i++) {
        tmp[i] = data[i];
    }
    T pop_obj = data[size-1];
    delete[] data;
    data = tmp;
    size--;
    return pop_obj;
}

template <typename T>
void GenericDynamicArray<T>::insert(int index, T val) {
    T* tmp = new T[size +1];
    for (int i =0;i<size+1; i++){
        if (i < index)
            tmp[i] = data[i];
        else if (i == index)
            tmp[index] = val;
        else 
            tmp[i] = data[i-1];
    }
    delete[] data;
    data = tmp;
    size++;
}

template <typename T>
void GenericDynamicArray<T>::remove(int index) {
    T* tmp = new T[size -1];

}


template <typename T>
void GenericDynamicArray<T>::print();

