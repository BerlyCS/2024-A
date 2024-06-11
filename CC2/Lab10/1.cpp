/*1. Utilizando la librer´ıa y estructura vector<T>, implemente una funci´on que lea el archivo de texto adjunto
DataGen.txt y guarde la informaci´on en un Vector. El archivo de texto contiene n´umeros flotantes [x, y]*/

/*2. Implemente una funci´on de ordenamiento de las coordenadas (sean los valores x o los valores y) donde la
funci´on de intercambio (swap_ref) utilice una variable temporal para realizar el intercambio de posiciones de dos
valores, e implemente una segunda funci´on que utilice el m´etodo move para realizar el mismo procesos*/

/*3. Ejecute el c´odigo de ordenamiento con los datos de DataGen.txt y mida el tiempo de ambas funciones de
intercambio implementadas (chrono::high resolution clock::now();)*/

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
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
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

void merge_(vector<vector<double>>& arr, int left, int mid, int right, char**& grid) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<double>> L(n1);
    vector<vector<double>> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0;
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
    
}
void merge(vector<vector<double>>& arr, int left, int mid, int right, int sub_index) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<double>> L(n1);
    vector<vector<double>> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i][sub_index] <= R[j][sub_index]) {
            swap_ref(arr[k], L[i]);
            ++i;
        } else {
            swap_ref(arr[k], R[j]);
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        swap_ref(arr[k], L[i]);
        ++i;
        ++k;
    }

    while (j < n2) {
        swap_ref(arr[k], R[j]);
        ++j;
        ++k;
    }
}
void merge_sort(vector<vector<double>>& array, int izq, int der, int sub_index) {
    if (izq < der) {
        int mid = izq + (der - izq) / 2;
        merge_sort(array, izq, mid, sub_index);
        merge_sort(array, mid + 1, der, sub_index);

        merge(array, izq, mid, der, sub_index);
    }
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
    merge_sort(colection, 0, colection.size()-1, 0); 
    cout<<colection[colection.size()-1][0]<<' '<<colection[0][0];
}


