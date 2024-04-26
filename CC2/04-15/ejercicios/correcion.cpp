#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void generar(vector<int> &vect) {
    srand(time(nullptr));
    for (int i=0; i<10; i++) {
        vect[i] = rand()%1000;
    }
}

void retirar(vector<int> &array) {
    swap(array[0], *array.end());
    array.pop_back();
    int min=0;
    for (int i=1; i<array.size(); i++) {
        if (array[i] < array[min] ) {
            min=i;
        }
    }
    swap(array[0], array[min]);
}

void imprimir(vector<int> &array) {
    for (int i=0; i<array.size(); i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void insertar(vector<int> &array, int value) {
    array.push_back(value);
}
int main() {
    vector<int> array(10);
    generar(array);
    int i=10;
    while (i--) {
        int value; 
        cin>>value;
        /* insertar(array, int value); */
        retirar(array);
        cout<<"Array[0]: "<<array[0]<<endl;
        imprimir(array); 
    }
}
