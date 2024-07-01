#include <iostream>
#include <utility>
using namespace std;

class dot {
    private:
        int x;
    public:
        dot (int x) :x(x) {}
        int get() {return x;}
        dot (dot&& tmp) {
            x = tmp.x;
            tmp.x = 0;
        }
};

void try_(int* p) {
    cout<<"Copia: "<<p<<" en "<<&p<<endl;
}
void try_hard(int*& p) {
    
    cout<<"Referencia lvalue: "<<p<<" en "<<&p<<endl;
}
void try_harder(int*&& p) {
    cout<<"Referencia rvalue: "<<p<<" en "<<&p<<endl;
}
int main() {
    int* p = new int(5);
    cout<<"direccion original: "<<p<<" en "<<&p<<endl;
    try_(p);
    try_hard(p);
    try_harder(std::move(p));
    cout<<"original: "<<*p<<endl;
}


