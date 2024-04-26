#include <cstdio>
#include <iostream>
using namespace std;

/******
 * 1. Utilizando un puntero de caracteres (char*) , cree una funci ́on que reciba dicho puntero y se le asigne
contenido mediante el ingreso de texto por teclado. Cree una segunda funci ́on que transforme dicha cadena
en May ́usculas. Ambas funciones deben ser de tipo void, es decir, no retornan valores. Muestre el texto en
may ́usculas desde la funci ́on principal.
**********/
void input(char*& cadena, int size) {
	cadena = new char[size]();
	cin.getline(cadena, 30);
}

void to_upper(char* cadena,int size) {
	for (int i=0;i<size;i++) {
		if (cadena[i] >= 97 && cadena[i] <= 122) {
			cadena[i] = cadena[i] - 32;
		}
	}
}

int main() {
	int size = 30;
	char* chp;
	input(chp, size);
	to_upper(chp, size);
	
	for (int i=0;i<size;i++) {
		cout<<chp[i];
	}
	cout<<endl;
}

