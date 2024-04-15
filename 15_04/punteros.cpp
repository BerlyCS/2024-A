#include <iostream>
using namespace std;

void sumar(int *arr, int tam) {
    return;
}

bool palindromo(int *ini, int *fin) {
    while (ini<fin) {
        if (*ini != *fin) return false;
        ini++; fin--;
    }
    return true;
}


int main() {
    int arr[]={1,2,3,2,1};
    cout<<palindromo(arr, arr+4);
}
