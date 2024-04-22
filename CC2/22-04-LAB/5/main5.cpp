/************+
 * 5. Cree una funci ́on que reciba un puntero vac ́ıo y un n ́umero entero n, cree una lista de n elementos inicializados
en cero y sea retornado en el puntero dado. Imprima los valores desde donde se invoco la funci ́on creada.
**************/
#include <iostream> 
using namespace std;

int* fun5(int n) {
	int *p=new int[n]();
	return p;
}

int main() {
	int *p = fun5(5);
	for (int i=0; i<5; i++) {
		cout<<i[p]<<" ";
	}
	cout<<endl;
}
	


