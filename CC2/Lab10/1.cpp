/*1. Utilizando la librer´ıa y estructura vector<T>, implemente una funci´on que lea el archivo de texto adjunto
DataGen.txt y guarde la informaci´on en un Vector. El archivo de texto contiene n´umeros flotantes [x, y]*/

/*2. Implemente una funci´on de ordenamiento de las coordenadas (sean los valores x o los valores y) donde la
funci´on de intercambio (swap) utilice una variable temporal para realizar el intercambio de posiciones de dos
valores, e implemente una segunda funci´on que utilice el m´etodo std::move para realizar el mismo procesos*/

/*3. Ejecute el c´odigo de ordenamiento con los datos de DataGen.txt y mida el tiempo de ambas funciones de
intercambio implementadas (std::chrono::high resolution clock::now();)*/

/*4. En base a los resultados, determine cual de los m´etodos Swap implementados tiene mejor rendimiento.*/
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

int partition(vector<vector<double>>& arr, int low, int high, int sub_index) {
    int pivot = arr[high][sub_index];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j][sub_index] <= pivot) {
            i++;
            swap_ref(arr[i], arr[j]);
        }
    }
    swap_ref(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(vector<vector<double>>& arr, int low, int high, int sub_index) {
    if (low < high) {
        int pi = partition(arr, low, high, sub_index);
        cout<<pi<<' ';
        quickSort(arr, low, pi - 1, sub_index);
        quickSort(arr, pi + 1, high, sub_index);
        
    }
}
int main() {
    vector<vector<double>> colection = leer();
    quickSort(colection, 0, colection.size()-1, 0); 
    cout<<colection[colection.size()-1][0]<<' '<<colection[0][0];
}


