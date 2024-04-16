#include <iostream>
using namespace std;

int main() {
    int x=5;
    int *p=&x;
    cout<<sizeof(x)<<endl;
    cout<<sizeof(p)<<endl;
}
