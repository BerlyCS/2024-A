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
        virtual void print() {
            cout<<"superior"<<'\n';
        }
};

class infer : public super {
    public:
        void print() override{
            cout<<"inferior"<<'\n';
        }
};

int main() {
    infer inf0;
    super(inf0).print();

    super sup1;
    infer* inf1 = static_cast<infer*>(&sup1);
    inf1->print();

    /* super *sup2 = new super; */
    /* infer *inf2 = dynamic_cast<infer*>(sup2); */
    /* inf2->print(); */

    inf0.super::print();//superior
}

