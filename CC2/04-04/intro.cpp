#include <stdio.h>

using namespace std;
struct nodo {
    int a;
    nodo* next;
    nodo* prev;
};

struct complejo {
    int real;
    double imag;

    complejo(int r, double i) : real(r), imag(i) {}
};

int main(int argc, char* argv[]) {
    complejo hola(1,1.1);

    printf("%f",hola.imag);
}
