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
    int base = num;
    for (int i=0;i<p-1;i++){
        num *= base;
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

string extraer_expresion(string expr, int op_index, int& ini, int& fin) {
    int i=op_index-1;
    string tmp;
    if (i<0) tmp="0";
    else { 
        while ( !es_operador(expr[i]) ) {
            tmp = expr[i] + tmp;
            i--;
            if (i<0) break;
        }
    }
    ini = i+1;
    i=op_index+1;
    tmp = tmp + expr[op_index];
    if (i>=expr.size()) {
        tmp= tmp + '0';
    } else {
        while ( !es_operador(expr[i]) ) {
            tmp = tmp + expr[i]; 
            i++;
            if (i >= expr.size()) break;
        }
    }
    fin=i;
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

int find_operator(string key) {
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

bool tiene_operador(string key) {
    for (char i: key) {
        if (es_operador(i))
            return true;
    }
    return false;
}

void reescribir(string& key, double value, int ini, int fin) {
    /* cout<<key.substr(0,ini)<<' '<<key.substr(fin, key.size())<<endl; */
    key = key.substr(0,ini) + to_string(value) + key.substr(fin,key.size());
}

string operar(string expr) {
    int index = find_operator(expr);
    int ini, fin;
    string base = extraer_expresion(expr, index, ini, fin);
    double resultado = operacion(base);
    reescribir(expr, resultado, ini, fin);
    /* cout<<expr<<endl; */
    /* cout<<ini<<' '<<fin<<endl; */
    /* cout<<expr.substr(ini, fin)<<endl; */
    return expr;
}

class calculadora {
    public:
        virtual void operar(string&) {};
};

class suma : public calculadora {
    public:
        void operar(string& expr) override{
            int index = find_operator(expr);
            int ini, fin;
            string base = extraer_expresion(expr, index, ini, fin);
            double resultado;
            double sumando1,sumando2;
            sumando1 = str_double(base.substr(0,index));
            sumando2 = str_double(base.substr(index+1, expr.size()));
            resultado = sumando1 + sumando2;
            reescribir(expr, resultado, ini, fin);
        }
};

class resta : public calculadora {
    public:
        void operar(string& expr) override{
            int index = find_operator(expr);
            int ini, fin;
            string base = extraer_expresion(expr, index, ini, fin);
            double resultado;
            double sumando1,sumando2;
            sumando1 = str_double(base.substr(0,index));
            sumando2 = str_double(base.substr(index+1, expr.size()));
            resultado = sumando1 - sumando2;
            reescribir(expr, resultado, ini, fin);
        }
};

class multiplicacion : public calculadora {
    public:
        void operar(string& expr) override{
            int index = find_operator(expr);
            int ini, fin;
            string base = extraer_expresion(expr, index, ini, fin);
            double resultado;
            double sumando1,sumando2;
            sumando1 = str_double(base.substr(0,index));
            sumando2 = str_double(base.substr(index+1, expr.size()));
            resultado = sumando1 * sumando2;
            reescribir(expr, resultado, ini, fin);
        }
};


class division : public calculadora {
    public:
        void operar(string& expr) override{
            int index = find_operator(expr);
            int ini, fin;
            string base = extraer_expresion(expr, index, ini, fin);
            double resultado;
            double sumando1,sumando2;
            sumando1 = str_double(base.substr(0,index));
            sumando2 = str_double(base.substr(index+1, expr.size()));
            resultado = sumando1 / sumando2;
            reescribir(expr, resultado, ini, fin);
        }
};

class potencia : public calculadora {
    public:
        void operar(string& expr) override{
            int index = find_operator(expr);
            int ini, fin;
            string base = extraer_expresion(expr, index, ini, fin);
            double resultado;
            double sumando1,sumando2;
            sumando1 = str_double(base.substr(0,index));
            sumando2 = str_double(base.substr(index+1, expr.size()));
            resultado = power(sumando1, sumando2);
            reescribir(expr, resultado, ini, fin);
        }
};
int main() {
    string expr;
    cin>>expr;
    calculadora *operacion;
    while (tiene_operador(expr)) {
        if (expr[find_operator(expr)] == '+') {
            operacion = new suma;
            operacion->operar(expr);
            delete operacion;
        }
        else if (expr[find_operator(expr)] == '-') {
            operacion = new resta;
            operacion->operar(expr);
            delete operacion;
        }
        else if (expr[find_operator(expr)] == '*') {
            operacion = new multiplicacion;
            operacion->operar(expr);
            delete operacion;
        }
        else if (expr[find_operator(expr)] == '/') {
            operacion = new division;
            operacion->operar(expr);
            delete operacion;
        }
        else if (expr[find_operator(expr)] == '^') {
            operacion = new potencia;
            operacion->operar(expr);
            delete operacion;
        }
        
    }
    cout<<endl<<expr;
}
