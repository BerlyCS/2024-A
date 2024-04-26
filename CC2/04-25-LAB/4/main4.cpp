#include <iostream>
using namespace std;

/******
 * 4. Implemente una funci ́on que reciba dos punteros de caracteres, realice el proceso de concatenaci ́on de ambas
cadenas. Copie el contenido del segundo puntero al primero y muestre ambos punteros al finalizar el proceso.
*/
char* fun4(char* s1, int size1, char* s2, int size2) {
    char* tmp = new char[size1+size2];
    int i;
    for (i=0;i<size1;i++) 
	    tmp[i] = s1[i];
    for (int j=0; j<size2; j++, i++) 
	    tmp[i] = s2[j];



    cout<<s1<<endl;
    cout<<s2<<endl;

}
int main() {

}
