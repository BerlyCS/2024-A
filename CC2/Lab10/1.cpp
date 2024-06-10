/*1. Utilizando la librer´ıa y estructura vector<T>, implemente una funci´on que lea el archivo de texto adjunto
DataGen.txt y guarde la informaci´on en un Vector. El archivo de texto contiene n´umeros flotantes [x, y]*/
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


vector<vector<double>> leer() {
    vector<vector<double>> coleccion;
    ifstream file("DataGen.txt");
    string data; int parity;
    vector<double> tmp;
    while (file>>data) {
        if (data.size() == 9) data.pop_back();
        if (parity == 2) {
            coleccion.push_back( tmp );
            parity = 0;
        } else {
            tmp.push_back(stod(data));
            parity++;
        }
    }
    return coleccion;
}

int main() {
    vector<vector<double>> colection = leer();
    cout<<colection.size();
}

