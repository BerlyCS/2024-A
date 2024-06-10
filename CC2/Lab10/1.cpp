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
#include <ostream>
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
    return coleccion;
}

template <typename T>
void invertir(T& a, T& b ) {
    T tmp = a;
    a = b;
    b = tmp;
}
void ord_selection(vector<vector<double>>& array, int sub_index){
    int pointer,max,
        num = array.size(),
        count = 0;

    for (int i=num;i>=0;i--) {
        if (count == 10000) {
            cout<<i<<' '<<flush;
            count=0;
        }
        max=0;
        for (int j=0;j<i;j++) {
            if (array[max][sub_index]<array[j][sub_index]) {
                max=j;
            }
        }
        invertir(array[i-1],array[max]);
        count++;
    }
}

int main() {
    vector<vector<double>> colection = leer();
    ord_selection(colection, 0); 
}


