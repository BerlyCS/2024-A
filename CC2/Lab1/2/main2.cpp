/**************
2. Cree una funcion que reciba un puntero por referencia y asigne le un valor de NULL. Muestre el contenido
del puntero antes y despues de llamar a esta funci ́on.
**************/

#include <iostream> 
using namespace std;

void fun1(int *&p) {
	p=NULL;
}

int main() {
	int x=0;
	int *p=&x;
	cout<<p<<endl;
	fun1(p);
	cout<<p<<endl;
}
	


