#include <iostream>
#include <utility>

using namespace std;

class test {
public:
    int *a;

    test(int *a) : a(a) {}

    test(test&& other) noexcept : a(std::move(other.a)) {
        other.a = nullptr; // dejar al objeto movido en un estado válido
    }

    test& operator=(test&& other) noexcept {
        if (this != &other) { // proteger contra la auto-asignación
            delete a; // liberar el recurso actual
            a = std::move(other.a); // mover el recurso
            other.a = nullptr; // dejar al objeto movido en un estado válido
        }
        return *this; // retornar el objeto actual
    }

    ~test() {
        delete a;
    }
};

int main() {
    test t1(new int(9));
    cout << "t1.a: " << t1.a << endl; // debería mostrar "t1.a: 0x0, t2.a: [dirección no nula]"
    test t2 = std::move(t1); // usar constructor de movimiento

    cout << "t1.a: " << t1.a << ", t2.a: " << t2.a << endl; // debería mostrar "t1.a: 0x0, t2.a: [dirección no nula]"

    return 0;
}

