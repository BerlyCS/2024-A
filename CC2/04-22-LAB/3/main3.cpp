/**************
 * 3. Escriba una funcion donde se declare una variable y se le asigne un valor num ́erico. Cree un puntero num ́erico
que tenga asignado el valor de la variable anterior. Muestre el valor y la direcci ́on actual del ambas variables.
***************/

#include <iostream> 
using namespace std;

void fun3() {
	int x=5;
	int *n = &x;
	cout<<"Valores: "<<endl;
	cout<<x<<" "<<n<<endl;
	cout<<"Direcciones de memoria: "<<endl;
	cout<<&x<<" "<<&n<<endl;	
}

int main() {
	fun3();
	return 0;
}
	


