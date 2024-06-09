#include <iostream>
#include <android/native_window.h>
#include <android/sensor.h>
#include <utility>
using namespace std;
int main() {
    string a = "rvalue";
    cout<<&a<<a.length()<<endl;
    string b = std::move(a);
    cout<<&b<<b.length()<<endl<<&a<<a.length()<<endl;
    a = std::move(b);
    cout<<&b<<b.length()<<endl<<&a<<a.length()<<endl;
}
