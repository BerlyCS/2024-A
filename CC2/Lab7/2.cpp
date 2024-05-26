/*
2. Defina el tipo de dato fraccion, e implemente los operadores suma(+), resta(-), multiplicacion(*) y division(/).
Todas las operaciones deben realizarse como fraccion.
*/
#include <iostream>
using namespace std;

class fraccion {
    private:
        int num, den;
    public:
        void simplificar() {
            int max = num < den ? den : num;
            while (max > 1) {
                if (den%max == 0 && num%max==0) {
                    den = den/max;
                    num = num/max;
                }
                max--;
            }
        }
        fraccion(int a, int b):num(a),den(b) {
            simplificar();
        }
        fraccion() : num(0), den(1) {}
        void print() const{
            cout << num << '/' << den << '\n';
        }
        fraccion operator+(fraccion& sumando) {
            fraccion result;
            result.num = num*sumando.den + den*sumando.num;
            result.den = den * sumando.den;
            result.simplificar();
            return result;
        }
        fraccion operator-(const fraccion& resta) {
            fraccion result;
            result.num = num*resta.den - den*resta.num;
            result.den = den * resta.den;
            result.simplificar();
            return result; 
        }
        fraccion operator*(const fraccion& factor) {
            fraccion result;
            result.num = num * factor.num;
            result.den = den * factor.den;
            result.simplificar();
            return result;
        }
        fraccion operator/(const fraccion& factor) {
            fraccion result;
            result.num = num * factor.den;
            result.den = den * factor.num;
            result.simplificar();
            return result;
        }
        
};
int main() {
    fraccion a(2,4),b(9,1);
    cout<<"a: "; a.print();
    cout<<"b: "; b.print();
    cout<<"Suma: "; (a+b).print();
    cout<<"Resta: ";(a-b).print();
    cout<<"Multiplicacion: ";(a*b).print();
    cout<<"Division: ";(a/b).print();
}
