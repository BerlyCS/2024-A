#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {
    
    DynamicArray p;
    p.push_back(5);
    cout<<p.get(0)<<endl;
}
