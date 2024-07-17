#include <iostream>
using namespace std;
int main() {
    bool a = []() {
        return -1;
    };
    cout<<&cout<<' '<<a;
}
