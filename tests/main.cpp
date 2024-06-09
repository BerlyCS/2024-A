/*1. Defina una funci´on Template que permita ordenar Array est´aticos de tipo int, float, double, long y char de
forma ascendente y descendente*/
#include <iostream>
using namespace std;

template<typename T>
void print(T* begin, T* end) {
    for ( T* i = begin; i != end; i++ ) {
        cout<< *i << ' ' ;
    }
}

template<typename T>
void ordenar(T* begin, T* end) {
    for (T* i=end-1; i!=begin-1; i--) {
        for (T* j=begin;j!=i;j++) {
            if (*j > *(j+1)) {
                swap(*j,*(j+1));
            }
        }
    }
}

int main(){
    int size=10;
    int arr[10] = {4,2,1,10,4,5,81,3,1,-3};
    ordenar(arr, arr+size);
    print(arr, arr+size);
}
