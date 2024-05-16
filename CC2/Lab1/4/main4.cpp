/****************
 * 4. Escriba un programa que reciba dos valores enteros en dos punteros y realice la multiplicaci ́on de ambos
valores.
*****************/

#include <iostream> 
using namespace std;

int main() {
	int x=5,y=7;
	int *a = &x, *b = &y;

	cout<<"Multiplicacion: " << (*a)*(*b) << endl;

}
	


