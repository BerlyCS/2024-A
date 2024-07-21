#include <iostream>
using namespace std;

template <int n>
class fibonacci {
public:
    static constexpr unsigned long value = fibonacci<n-1>::value + fibonacci<n-2>::value;
};

template <>
class fibonacci<1> {
public:
    static constexpr long value = 1;
};

template <>
class fibonacci<2> {
public:
    static constexpr long value = 1;
};
int main() {
    cout<<fibonacci<92>::value<<endl;

}
