#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

class complex {
    private:
        double r;
        double i;
    public:
        friend ostream& operator<<(ostream& cout, complex& num);
        complex(double r, double i) : r(r), i(i){}
};

int main() {

}
