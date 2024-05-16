#include <iostream>
using namespace std;
/*******
 *2. Implemente una funci ́on que reciba dos punteros de caracteres con contenido y que indique si el contenido
del primer puntero es lexicogr ́aficamente mayor, menor o igual al contenido del segundo puntero. Retorne de
la funci ́on un valor num ́erico que indique el resultado obtenido.
********/

int compare(char* str1, int size1, char* str2, int size2){
	int min=size1;
	if (size1>size2) min=size2;
	for (int i=0;i<min;i++) {
		if (str1[i] < str2[i]) {
			return 1;
		}
		else if (str1[i] > str2[i]) {
			return -1;
		}
	}
	return 0;

}

int main() {
	char* str1;
	char* str2;
	str1 = "iola";
	str2 = "hola";
	cout<<compare(str1,4,str2,4)<<endl;

}

	
