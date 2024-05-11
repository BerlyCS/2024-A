#include <iostream>
using namespace std;

class point {
  public:
    int s;
    point() : s(10) {}
    virtual void doing() =0;
};

point operator*(const point& a, const point& b) {
  point tmp;
  tmp.s = a.s + b.s;
  return tmp;
}

class Dummy {
  public:
    bool isitme (Dummy& param);
};

bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
}

int main() {
  point x, y;
  point c = x*y;
  cout << c.s;
  Dummy a;
  Dummy* b = &a;
  if ( b->isitme(a) )
    cout << "yes, &a is b\n";
}
