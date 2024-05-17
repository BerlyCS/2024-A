/*
1. Cree una clase Base denominada class Superior, que contenga un m ́etodo publico print, que muestre el
nombre de la clase. Añada una clase derivada (class Inferior )de la clase Superior con un m ́etodo publico que
sobrescriba el m ́etodo publico print y que muestre el nombre de la clase derivada. Verifique si es posible crear
un objeto de la clase Inferior y acceder al m ́etodo superior. Interprete los resultados y describa si fue posible
o no.
*/

#include <iostream>
using namespace std;
class super {
    public:
        void print() {
            cout<<"super"<<'\n';
        }
};

class infer : public super {
    public:
        void print() {
            cout<<"infer"<<'\n';
        }
};

int main() {
    infer obj;
    obj.print();
    static_cast<super>(obj).print();
    super(obj).print();

    super sup1;
    infer *inf1 = static_cast<infer*>(&sup1);
    inf1->print();
    /* dynamic_cast<jioririlljedljieorfohifae>() */
}

