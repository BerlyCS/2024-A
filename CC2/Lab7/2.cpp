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
            int min = num < den ? num : den;
            while (min != 1) {
                if (den%min == 0 && num%min==0) {
                    den = den/min;
                    num = num/min;
                }
                min--;
            }
        }
        fraccion(int a, int b):num(a),den(b) {
            simplificar();
        }
        fraccion() {}
        void print() {
            cout << num << '/' << den << '\n';
        }
        fraccion operator+(fraccion sumando) {
            fraccion result;
            result.num = num*sumando.den + den*sumando.num;
            result.den = den * sumando.den;
            result.simplificar();
            return result;
        }
};
int main() {
    fraccion test(2,4);
    test.print();
    fraccion a(2,4),b(5,4);
    (a+b).print();
}
