#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
/*
 * 1. Dado un conjunto de numeros enteros aleatorios (1000 elementos como minimo), elabore una funcion que per-
mita identificar y retornar de un vector los k- ́esimos menores elementos. (La funcion recibe como parametros
un vector<int>, y la cantidad int k, retornando un segundo vector<int> con los elementos solicitados)
*/

vector<int> gen_random(int size) {
    vector<int> tmp(size); 
    
    for(int i=0;i<size;i++)
         tmp[i] = rand()%1000;
    return tmp;
}

vector<int> fun1(vector<int> vect, int k) {
	int size = vect.size();

	for (int i=size-1; i>=0; i--) {
		for (int j=1; j<i; j++) {
			if (vect[j]< vect[j+1]) {
				swap(vect[j], vect[j+1]);
			}
		}
	}

	vector<int> tmp;
	
	for (int i=0;i<k;i++) {
		tmp.push_back(vect[i]);
	}
	return tmp;
}

int main() {
	vector<int> test = gen_random(1000);
	vector<int> result = fun1(test,5);
	
	for (int i=0; i<5; i++) {
		cout<<result[i]<<" ";
	}
}
