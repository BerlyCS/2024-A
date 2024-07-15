#include <iostream>
using namespace std;

template <class T, unsigned int n>
class buscar {
private:
    const T (&array)[n];
public:
    buscar(const T (&arr)[n]) : array(arr) {}

    bool find(const T num) const {
        for (int i=0; i<n; ++i) {
            if (array[i] == num) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    constexpr int a[]={1,2,3,4,5};
    buscar<int,5> finder(a);

    int num=3, num2=6;
    if (finder.find(num)) {
        cout<<num<<" existe\n";
    } 
    else {cout<<num<<" no se encontro\n";}
    if (finder.find(num2)) {
        cout<<num2<<" existe\n";
    } 
    else {cout<<num2<<" no se encontro\n";}

    return 0;
}
