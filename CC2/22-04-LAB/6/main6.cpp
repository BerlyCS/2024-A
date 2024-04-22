/**************
6. Escriba una funcion que cree dos lista de punteros con igual cantidad de elementos de n elementos aleatorios.
Escriba una segunda funcion que reciba las dos listas de valores almacenados en punteros, e intercambie
ambos valores. Muestre el contenido de ambos punteros antes y despues del intercambio.
**************/

#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

void fun6_1(int *&p1, int *&p2, int n) {
	srand(time(NULL));

	p1 = new int[n];
	p2 = new int[n];

	for (int i=0; i<n; i++) {
		p1[i] = rand()%100;
		p2[i] = rand()%100;
	}
}

void fun6_2(int *p1, int *p2, int n) {
	for (int i=0; i<n; i++) {cout << p1[i] << " ";}
	cout<<endl;
	for (int i=0; i<n; i++) {cout << p2[i] << " ";}
	cout<<endl;

	for (int i=0; i<n; i++) {
		swap(p1[i], p2[i]);
	}

	for (int i=0; i<n; i++) { cout << p1[i] << " "; }
	cout<<endl;
	for (int i=0; i<n; i++) { cout << p2[i] << " "; }
	cout<<endl;

}

int main() {
	int *p1,*p2;
	fun6_1(p1,p2,5);
	fun6_2(p1,p2,5);
}
	


