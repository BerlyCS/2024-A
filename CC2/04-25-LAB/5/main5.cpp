#include <iostream>
using namespace std;

/**
 * 5. Genere un ejemplo de dangling pointer con un puntero de caracteres.
 * */
int main() {
	char* ptr = new char[3];
	ptr[0]='a'; ptr[1]='b'; ptr[2]='c';
	char* ptr2 = ptr;
	delete[] ptr;
	cout<<ptr<<endl;
	cout<<ptr2<<endl;
	cout<<*ptr2<<endl;
}

