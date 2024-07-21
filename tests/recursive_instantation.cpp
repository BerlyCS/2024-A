#include <iostream>
using namespace std;

class test {
    test *ptr;

public:
    static int count;
    test() { 
        ptr = new test;
        cout<<count<<' '; 
        count++; 
    }
};

int test::count = 0;

int main() {
    test xddd;
}
