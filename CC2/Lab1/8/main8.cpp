/**************
8. Escriba una funci ́on que copie el contenido de un Array de valores decimales a otro usando solo punteros. Su
funci ́on no debe de tener la sentencia return.
**************/

#include <iostream> 
using namespace std;

void fun8(float *f1, float *f2, int n) {
	float *p1 = f1, *p2 = f2;

	for (int i=0;i<n;i++) {
		*p2 = *p1;
		p1++; p2++;
	}
}

int main() {
	float *f1, *f2;
	int n=5;
	f1 = new float[n];
	f2 = new float[n];
	fun8(f1,f2,n);

	for (int i=0; i<n; i++) {
		cout<<f1[i]<<" "<<f2[i]<<endl;
	}
}
	


