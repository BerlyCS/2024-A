#include <iostream>
using namespace std;

constexpr bool primo(unsigned int numero) {
    for (int i=numero-1; i>1; i-- ) {
        if (numero%i == 0) {
            return false;
        }
    }
    return true;
}

template <int num>
struct es_primo {
    inline static constexpr bool value = primo(num); 
};

int main() {
    cout<<es_primo<2>::value<<endl;
    cout<<es_primo<1>::value<<endl;
    cout<<es_primo<15>::value<<endl;
    cout<<es_primo<10>::value<<endl;
    cout<<es_primo<81929>::value<<endl;
    cout<<es_primo<98887>::value<<endl;
}
