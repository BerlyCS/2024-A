#include <iostream>
#include <utility>

using namespace std;


class MyClass {
public:
    MyClass() {
        cout << "Constructor called\n";
    }

    MyClass(const MyClass&) {
        std::cout << "Copy constructor called\n";
    }

    MyClass(MyClass&&) {
        std::cout << "Move constructor called\n";
    }

    MyClass& operator=(const MyClass&) {
        std::cout << "Copy assignment operator called\n";
        return *this;
    }

    MyClass& operator=(MyClass&&) noexcept {
        std::cout << "Move assignment operator called\n";
        return *this;
    }
};

int main() {
    MyClass a;
    MyClass b = std::move(a); // Move constructor is called
    MyClass c;
    c = std::move(b);         // Move assignment operator is called
}
