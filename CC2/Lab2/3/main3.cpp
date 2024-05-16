#include <iostream>
#include <cstring>
using namespace std;
/****
 3. Cree una funci ́on que reciba un puntero de caracteres por referencia conteniendo un texto de 100 caracteres
como m ́ınimo. Utilizando aritm ́etica de punteros, reemplace cada vocal con una X y muestre el resultado del
contenido del puntero modificado.
 * ***/

void fun3(char *&text, int size) {
    char vocals[] = {'a','e','i','o','u','A', 'E', 'I', 'O', 'U'};

    for (int i=0; i<size; i++) {

        for (int j=0;j<10;j++) {
            if (text[i] == vocals[j]) {
                text[i] = 'X';
                break;
            }
        }
        cout<<text[i];
    }
    cout<<endl;
}

int main() {
    char* text = new char[5];
    strcpy(text, "aeiou");
    fun3(text, 5);
}

