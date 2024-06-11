/*1. Utilizando la librer´ıa y estructura vector<T>, implemente una funci´on que lea el archivo de texto adjunto
DataGen.txt y guarde la informaci´on en un Vector. El archivo de texto contiene n´umeros flotantes [x, y]*/

/*2. Implemente una funci´on de ordenamiento de las coordenadas (sean los valores x o los valores y) donde la
funci´on de intercambio (swap_ref) utilice una variable temporal para realizar el intercambio de posiciones de dos
valores, e implemente una segunda funci´on que utilice el m´etodo move para realizar el mismo procesos*/

/*3. Ejecute el c´odigo de ordenamiento con los datos de DataGen.txt y medioa el tiempo de ambas funciones de
intercambio implementadas (chrono::high resolution clock::now();)*/

/*4. En base a los resultados, determine cual de los m´etodos Swap implementados tiene mejor rendimiento.*/
#include <chrono>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<vector<float>> leer() {
    vector<vector<float>> coleccion;
    ifstream file("DataGen.txt");
    string data; int parity = 0;
    vector<float> tmp;
    while (file>>data) {
        if (data.size() == 9) data.pop_back();
        if (parity == 2) {
            coleccion.push_back( tmp );
            parity = 0;
            tmp.clear();
        }
        tmp.push_back(stod(data));
        parity++;
    }
    coleccion.push_back( tmp );
    cout<<"Datos leidos.\n";
    return coleccion;
}

template <typename T>
void swap_ref(T& a, T& b ) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void swap_move(T& a, T& b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

void merge_ref(vector<vector<float>>& arr, int izq, int medio, int der, int sub_index) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    vector<vector<float>> izq_arr(n1);
    vector<vector<float>> der_arr(n2);
    for (int i = 0; i < n1; i++)
        izq_arr[i] = arr[izq + i];
    for (int i = 0; i < n2; i++)
        der_arr[i] = arr[medio + 1 + i];

    int i = 0; 
    int j = 0;
    int k = izq;
    while (i < n1 && j < n2) {
        if (izq_arr[i][sub_index] <= der_arr[j][sub_index]) {
            swap_ref(arr[k], izq_arr[i++]);
        } else {
            swap_ref(arr[k], der_arr[j++]);
        }
        ++k;
    }
    while (i < n1) {
        swap_ref(arr[k++], izq_arr[i++]);
    }
    while (j < n2) {
        swap_ref(arr[k++], der_arr[j++]);
    }
}

void ordenar_ref(vector<vector<float>>& array, int izq, int der, int sub_index) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        ordenar_ref(array, izq, medio, sub_index);
        ordenar_ref(array, medio + 1, der, sub_index);
        merge_ref(array, izq, medio, der, sub_index);
    }
}

void merge_move(vector<vector<float>>& arr, int izq, int medio, int der, int sub_index) {
    int n1=medio-izq+1;
    int n2=der-medio;

    vector<vector<float>> izq_arr(n1);
    vector<vector<float>> der_arr(n2);
    for (int i = 0; i < n1; i++)
        izq_arr[i] = arr[izq + i];
    for (int i = 0; i < n2; i++)
        der_arr[i] = arr[medio + 1 + i];

    int i = 0; 
    int j = 0;
    int k = izq;
    while (i < n1 && j < n2) {
        if (izq_arr[i][sub_index] <= der_arr[j][sub_index]) {
            swap_move(arr[k], izq_arr[i++]);
        } else {
            swap_move(arr[k], der_arr[j++]);
        }
        ++k;
    }
    while (i < n1) {
        swap_move(arr[k++], izq_arr[i++]);
    }
    while (j < n2) {
        swap_move(arr[k++], der_arr[j++]);
    }
}

void ordenar_move(vector<vector<float>>& array, int izq, int der, int sub_index) {
    if (izq < der) {
        int medio=izq+(der-izq)/2;
        ordenar_move(array, izq, medio, sub_index);
        ordenar_move(array, medio + 1, der, sub_index);

        merge_move(array, izq, medio, der, sub_index);
    }
}
void test_con_refs() {
    vector<vector<float>> colection = leer();
    cout<<"Usando swap por referencia\n";

    int resp = -1;
    auto start = std::chrono::high_resolution_clock::now();

    ordenar_ref(colection, 0, colection.size()-1, 0); 

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start); 
    cout<< resp << " por " << duration.count()/1000 << " ms" << endl;
}

void test_con_move() {
    vector<vector<float>> colection = leer();
    cout<<"Usando swap por std::move()\n";

    int resp = -1;
    auto start = std::chrono::high_resolution_clock::now();

    ordenar_move(colection, 0, colection.size()-1, 0); 

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start); 
    cout<< resp << " por " << duration.count()/1000 << " ms" << endl;
}

int main() {
    test_con_refs();
    test_con_move();
}


