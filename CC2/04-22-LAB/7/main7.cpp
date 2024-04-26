/**************
7. Cree una funcion que permita ingresar valores a un Array de valores decimales y muestre su contenido. Tanto
el ingreso de los valores dentro del Array como su impresi ́on de valores debe de realizarse con punteros.
**************/

#include <iostream> 
using namespace std;

void fun7(float *p, int n) {
	p = new float[n];
	float *t = p;

	for (int i=0; i<n; i++) {
		cin>>*(t++);
	}
	t=p;

	for (int i=0; i<n; i++) {
		cout << *(t++) << " ";
	}

}

int main() {
	int n=5;
	float *p;
	fun7(p, n);
}
	


