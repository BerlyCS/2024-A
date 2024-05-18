/*
 * Utilizando Polimorfismo, desarrolle un programa que permita calcular como m ́ınimo las operaciones de suma,
resta, multiplicaci ́on, divisi ́on y potencia. Tenga en consideraci ́on que las operaciones ser ́an dadas en una
linea de texto (Se considera incorrecto pedir valores num ́ericos y operadores por separado). Por ejemplo:
Operacion 0 : 7+3 * 5 - 2
Operacion 1 : -5*3*2 + 210 - 60/0.5
Operacion 2 : 34/2 * 50/5
Operacion 3 : -3 * -3 - 3 - -3.5

Tenga en consideraci ́on que los resultados deben de respetar la precedencia de operadores. Se tendr ́a pun-
tuaci ́on extra por agregar m ́as operadores al programa.
 */ 
#include <iostream>
#include <string>
using namespace std;

//178.453
int power(int num, int p) {
    for (int i=0;i<p;i++){
        num *= num;
    }
    return num;
}

bool tiene_operador(string expr) {
    for (int i=0;expr[i++]!='\0';){
        if ()
    }
}

double str_double(string num) {
    double tmp= 0.0;
    bool decimal=false;
    int level=1;
    for (int i=0; i<num.size(); i++) {
        if ( num[i] == '.' )
            decimal=true;
        else if ( num[i] < '0' || num[i] > '9' ) continue;
        else if ( decimal ) {
            int parte_entera = tmp;
            tmp = tmp - parte_entera + (num[i] - 48)/pow(10, level++);
            tmp += parte_entera;
        }
        else {
            tmp *= 10;
            tmp += num[i] - 48;
        }
    }
    return tmp;
}

//3+4
double operacion(string suma) {
    string num;
    int op_index;
    double a,b;
    for (int i=0; suma[i++]!='\0';) {
        if (suma[i] == '+') {
            op_index = i;
            break;
        }
    }
    a = str_double(suma.substr(0,op_index));
    b = str_double(suma.substr(op_index+1, suma.size()));
    /* cout << a << ' ' << b; */
    return a+b;
}

class calculadora {
    protected:
        string key;
        string separar();
    public:
        calculadora(string s) : key(s) {}
        virtual void operacion() =0;
        void operar();
};

string calculadora::separar() {
    string expr;
    for (int i=0; key[i]!='\0';) {
        if ()
    }
    return expr;
}

class suma : public calculadora {
    public:
        suma(string s) : calculadora(s) {}
};

void completar(string expr) {
    for ( int i=0; i < expr.size(); i++ ) {

        return;
    }
}

int main() {

}
