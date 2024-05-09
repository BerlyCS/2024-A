#ifndef GEN_STATIC_ARRAY_H
#define GEN_STATIC_ARRAY_H
#pragma once

#include <iostream>

template <typename T, int SIZE>
class GenericStaticArray {
    private:
        int size;
        T* data;
    public:
        GenericStaticArray<T,SIZE>();
        GenericStaticArray<T,SIZE>(GenericStaticArray<T, SIZE> &b);
        ~GenericStaticArray<T,SIZE> ();
        T get(int index);
        void set(int index, T val);
        int getsize();
        void print(); 
};

template <typename T, int SIZE>
GenericStaticArray<T,SIZE>::GenericStaticArray() {
    size = SIZE;
    data = new T[size];
}

template <typename T, int SIZE>
GenericStaticArray<T,SIZE>::GenericStaticArray(GenericStaticArray<T, SIZE> &b) {
    size = b.getsize();
    data = new T[size];
    for (int i=0; i<size; i++) {
        data[i] = b.get(i);
    }
}

template <typename T, int SIZE>
GenericStaticArray<T, SIZE>::~GenericStaticArray() {
    delete[] data;
}

template <typename T, int SIZE>
T GenericStaticArray<T, SIZE>::get(int index) {
    return data[index];
}

template <typename T, int SIZE>
int GenericStaticArray<T, SIZE>::getsize() {
    return this->size;
}

template <typename T, int SIZE>
void GenericStaticArray<T, SIZE>::print() {
    for (int i=0; i<size; i++) {
        std::cout<<data[i]<<' ';
    }
    std::cout<<std::endl;
}

template <typename T, int SIZE>
void GenericStaticArray<T, SIZE>::set(int index, T val) {
    if (index < 0 || index >= size) 
        return;

    data[index] = val;
}

#endif
