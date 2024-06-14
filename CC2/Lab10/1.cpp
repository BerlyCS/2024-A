/*1. Utilizando la libreria y estructura vector<T>, implemente una funci´on que lea el archivo de texto adjunto
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

vector<vector<double>> leer() {
    vector<vector<double>> coleccion;
    ifstream file("DataGen.txt");
    string data; int parity = 0;
    vector<double> tmp;
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
    cout<<"Datos leidos.\t";
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

void merge_ref(vector<vector<double>>& arr, int izq, int medio, int der, int sub_index) {
    int izq_size = medio - izq + 1;
    int der_size = der - medio;
    vector<vector<double>> izq_arr(izq_size);
    vector<vector<double>> der_arr(der_size);
    for (int i{0}; i<izq_size; i++)
        izq_arr[i] = arr[izq+i];
    for (int i{0}; i<der_size; i++)
        der_arr[i] = arr[medio+1+i];

    int i = 0; 
    int j = 0;
    int k = izq;
    while (i < izq_size && j < der_size) {
        if (izq_arr[i][sub_index] <= der_arr[j][sub_index]) {
            swap_ref(arr[k], izq_arr[i++]);
        } else {
            swap_ref(arr[k], der_arr[j++]);
        }
        k++;
    }
    while (i < izq_size) {
        swap_ref(arr[k++], izq_arr[i++]);
    }
    while (j < der_size) {
        swap_ref(arr[k++], der_arr[j++]);
    }
}

void ordenar_ref(vector<vector<double>>& array, int izq, int der, int sub_index) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        ordenar_ref(array, izq, medio, sub_index);
        ordenar_ref(array, medio + 1, der, sub_index);
        merge_ref(array, izq, medio, der, sub_index);
    }
}

void merge_move(vector<vector<double>>& arr, int izq, int medio, int der, int sub_index) {
    int izq_size=medio-izq+1;
    int der_size=der-medio;

    vector<vector<double>> izq_arr(izq_size);
    vector<vector<double>> der_arr(der_size);
    for (int i{0}; i < izq_size; i++)
        izq_arr[i] = arr[izq+i];

    for (int i{0}; i < der_size; i++)
        der_arr[i] = arr[medio+1+i];

    int i=0; 
    int j=0;
    int k=izq;
    while (i<izq_size && j<der_size) {
        if (izq_arr[i][sub_index] <= der_arr[j][sub_index]) {
            swap_move(arr[k], izq_arr[i++]);
        } else {
            swap_move(arr[k], der_arr[j++]);
        }
        ++k;
    }
    while (i < izq_size) {
        swap_move(arr[k++], izq_arr[i++]);
    }
    while (j < der_size) {
        swap_move(arr[k++], der_arr[j++]);
    }
}

void ordenar_move(vector<vector<double>>& array, int izq, int der, int sub_index) {
    if (izq < der) {
        int medio=izq+(der-izq)/2;
        ordenar_move(array, izq, medio, sub_index);
        ordenar_move(array, medio + 1, der, sub_index);

        merge_move(array, izq, medio, der, sub_index);
    }
}
void test_con_refs() {
    vector<vector<double>> colection = leer();
    
    int resp = -1;
    auto start = std::chrono::high_resolution_clock::now();

    ordenar_ref(colection, 0, colection.size()-1, 0); 

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
    cout<< resp << " por " << duration.count() << " ms" << endl;
}

void test_con_move() {
    vector<vector<double>> colection = leer();

    auto start = std::chrono::high_resolution_clock::now();

    ordenar_move(colection, 0, colection.size()-1, 0); 

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
    cout << " por " << duration.count() << " ms" << endl;
}

int main() {
    cout<<"Usando swap por referencia\n";
    for (int i=0; i<5; i++) {
        cout<< "Test N°: "<<i+1<<"-> ";
        test_con_refs();
    }
    cout<<"Usando swap por std::move()\n";
    for (int i=0; i<5; i++) {
        cout<< "Test N°: "<<i+1<<"-> ";
        test_con_move();
    }
}


