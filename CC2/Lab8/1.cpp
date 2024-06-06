/*
1. Defina una clase Fecha que permita manejar los dıas, meses y años de una fecha dada. La Fecha base
por defecto debe de iniciar el mes 1, dıa 1 y ano de 1900. Se debe tener un metodo para asignar una nueva
fecha(set). Defina un metodo para saber si la fecha con la que trabaja un objeto es de un año bisiesto. Ademas,
se necesita un metodo que indique cuando una fecha corresponde al ultimo dıa de un mes. Sobrecargue los
operadores ++, +=, −− y −= para permitir sumar o restar la fecha con otra de la misma clase.
Tenga en consideracion que de ser necesario funciones adicionales, debe de implementarlas y evitar usar funciones
ya implementadas en C++. En caso de encontrar una funcion propia del lenguaje que pudo implementar, tendra
5 puntos menos sobre la nota por cada una de las funciones utilizadas
*/
#include <iostream>
#include <ostream>
using namespace std;

class fecha {
    private:
        short dia, mes;
        int año;
        
    public:
        void verificar();
        fecha() { dia = 1; mes = 1; año = 1900; }
        fecha(short d, short m, int a);
        void set(short d, short m, int a);
        int ultimo_dia() const;
        bool es_ultimo_dia() const;
        bool es_bisiesto() const;
        void print() const;

        void operator++(int);
        void operator--(int);
        void operator+=(int);
        void operator-=(int);
        void operator+=(const fecha&);
        void operator-=(const fecha&);
};

fecha::fecha(short d, short m, int a) : dia(d), mes(m), año(a) {
    verificar();
}

void fecha::operator++(int) {
    int ultimo = ultimo_dia();
    if (dia + 1 > ultimo) {
        mes++;
        dia = 1;
        if (mes > 12) {
            año++;
            mes = 1;
        }
    } else {
        dia ++;
    }
}

void fecha::operator--(int) {
    if (dia-1 < 1) {
        mes--;
        if (mes <= 0) {
            año--;
            mes = 12;
        }
        dia = ultimo_dia();
    } 
    else {
        dia --;
    }
}

int fecha::ultimo_dia() const{
    if (mes == 1 || mes == 3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) {
        return 31; 
    }
    else if (mes == 2) {
        if (es_bisiesto()) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}

bool fecha::es_ultimo_dia() const {
    if (dia == ultimo_dia()) {
        return true;
    }
    return false;
}

bool fecha::es_bisiesto() const {
    if (año%4 == 0) {
        if (año%100 == 0 && !(año%400 == 0)) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

void fecha::verificar() {
    if (mes >= 13) {
        mes = 12;
    }

    if ((mes == 1 || mes == 3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && dia>31) {
        dia=31;
    }
    else if (es_bisiesto() && mes==2) {
        dia=29;
    }
    else if (mes == 2 && dia>28) {
        dia=28;
    }
    else if ((mes==4 || mes==6 || mes==9 || mes==11) && dia>30) {
        dia=30;
    }
    else if (dia == 0 && (año!=0 || mes!=0)) {
        dia=1;
    }

}

void fecha::set(short d, short m, int a) {
    dia = d;
    mes = m;
    año = a;
    verificar();
}

void fecha::print() const {
    cout<<dia<<'/'<<mes<<'/'<<año<<endl;
}

void fecha::operator+=(int a) {
    for (int i=0; i<a; i++) {
        (*this)++;
    }
}

void fecha::operator-=(int a) {
    for (int i=0; i<a; i++) {
        (*this)--;
    }
}

void fecha::operator+=(const fecha& b) {
    for (int i=0; i<b.dia; i++) {
        (*this)++;
    }

    mes += b.mes;
    if (mes > 12) {
        año++;
        mes = mes-12;
    }

    año += b.año;
}

void fecha::operator-=(const fecha& b) {
    año -= b.año;

    mes -= b.mes;
    if (mes < 1) {
        mes += 12;
        año--;
    }

    for (int i=0; i<b.dia; i++) {
        (*this)--;
    }
}

int main() {
    fecha a(29,2,2000);
    fecha b(1,1,1600);
    fecha c(1,0,0);
    cout<<"a: ";
    a.print();

    cout<<"b: ";
    b.print();

    cout<<"c: ";
    c.print();

    a += c;
    cout<<"a+=c;  ";

    a.print();
    a -= c;
    cout<<"a-=c;  ";
    a.print();

    cout<<"Es a bisiesto: "<<a.es_bisiesto()<<endl;
    cout<<"Tiene a el ultimo dia: "<<a.es_ultimo_dia()<<endl;

    a.set(30, 2, 2004);
    a.print();

    cout<<"-------\n";
    b.print();
    cout<<"b-- "; 
    b--;
    b.print();

    cout<<"b++ ";
    b++;
    b.print();
}
