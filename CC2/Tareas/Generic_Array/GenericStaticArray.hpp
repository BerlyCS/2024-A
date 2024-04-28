#ifndef GEN_STATIC_ARRAY_H
#define GEN_STATIC_ARRAY_H
#pragma once

#include <iostream>

template <typename T, int S>
class GenericStaticArray {
    private:
        int size;
        T* data;
    public:
        GenericStaticArray<T,S>();
        GenericStaticArray<T,S>(GenericStaticArray<T, S> &b);
        ~GenericStaticArray<T,S> ();
        T get(int index);
        void set(int index, T val);
        int getsize();
        void print(); 
};

template <typename T, int S>
GenericStaticArray<T,S>::GenericStaticArray() {
    size = S;
    data = new T[size];
}

template <typename T, int S>
GenericStaticArray<T,S>::GenericStaticArray(GenericStaticArray<T, S> &b) {
    size = b.getsize();
    data = new T[size];
    for (int i=0; i<size; i++) {
        data[i] = b.get(i);
    }
}

template <typename T, int S>
GenericStaticArray<T, S>::~GenericStaticArray() {
    delete[] data;
}

template <typename T, int S>
T GenericStaticArray<T, S>::get(int index) {
    return data[index];
}

template <typename T, int S>
int GenericStaticArray<T, S>::getsize() {
    return this->size;
}

template <typename T, int S>
void GenericStaticArray<T, S>::print() {
    for (int i=0; i<size; i++) {
        std::cout<<data[i]<<' ';
    }
    std::cout<<std::endl;
}

template <typename T, int S>
void GenericStaticArray<T, S>::set(int index, T val) {
    if (index < 0 || index >= size) 
        return;

    data[index] = val;
}

#endif
