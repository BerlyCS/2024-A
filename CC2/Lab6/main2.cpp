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

int power(int num, int p) {
    for (int i=0;i<p;i++){
        num *= num;
    }
    return num;
}

bool es_operador(char letra) {
    if ( letra=='+' || letra=='x' || letra=='-' || letra=='^' || letra=='/')
        return true;

    return false;
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

string extraer_expresion(string expr, int op_index) {
    int i=op_index-1;
    string tmp;
    if (i<0) tmp="0";
    while ( !es_operador(expr[i]) ) {
        tmp = expr[i] + tmp;
        i--;
        if (i<0) break;
    }
    i=op_index+1;
    tmp = tmp + expr[op_index];
    while ( !es_operador(expr[i]) ) {
        tmp = tmp + expr[i]; 
        i++;
        if (i >= expr.size()) break;
    }
    return tmp;
}

//3+4
double operacion(string suma) {
    string num;
    int op_index;
    double a,b;
    for (int i=0; i<suma.size(); i++) {
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

int operador(string key) {
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='^') {
            return i;
        }
    }
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='*' || key[i] == '/') {
            return i;
        }
    }
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='-') {
            return i;
        }
    }
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='+') {
            return i;
        }
    }
    return -1;
}

class calculadora {
    protected:
        string separar();
        void reescribir(double, int, int);
    public:
        string key;
        void set(string key) {
            this->key=key;
        }
        calculadora(string s) : key(s) {}
        virtual double operacion(string, int&,int&) {
            return 0.0;
        };
        string operar();
        int op_index();
};

//CLASE
string calculadora::separar() {
    string expr;
    int op_ind = op_index();
    expr = extraer_expresion(key, op_ind);
    return expr;
}

bool tiene_operador(string key) {
    for (char i: key) {
        if (es_operador(i))
            return true;
    }
    return false;
}

void reescribir(string& key, double value, int ini, int fin) {
    key = key.substr(0,ini) + to_string(value) + key.substr(fin,key.size());
}

string calculadora::operar() {
    string expr = separar();
    int ini, fin;
    double resultado = operacion(expr, ini, fin);
    reescribir(resultado, ini, fin);
    return key;
}

void calculadora::reescribir(double value,int ini, int fin) {
    key = key.substr(0,ini) + to_string(value) + key.substr(fin,key.size());
}

int calculadora::op_index() {
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='^') {
            return i;
        }
    }
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='*' || key[i] == '/') {
            return i;
        }
    }
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='-') {
            return i;
        }
    }
    for (int i=0; i<key.size(); i++) {
        if (key[i]=='+') {
            return i;
        }
    }
    return 0;
}

class suma : public calculadora {
    public:
        suma(string s) : calculadora(s) {}
        double operacion(string, int&, int&) override;
};

double suma::operacion(string expr, int& ini, int& fin) {
    string num;
    int op_index;
    double a,b;
    for (int i=0; i<expr.size();i++) {
        if (expr[i] == '+') {
            op_index = i;
            break;
        }
    }
    a = str_double(expr.substr(0,op_index));
    b = str_double(expr.substr(op_index+1, expr.size()));
    /* cout << a << ' ' << b; */
    return a+b;
}

int main() {
    string expr = "3+50";
    cout<<operacion(expr);
}
