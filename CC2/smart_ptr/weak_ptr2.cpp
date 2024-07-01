// std__memory__weak_ptr_expired.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

using namespace std;

int main()
{
    weak_ptr<int> wp;

    {
        shared_ptr<int> sp(new int(10));
        wp = sp;
        cout << "wp.expired() == " << boolalpha
            << wp.expired() << endl;
        cout << "*wp.lock() == " << *wp.lock() << endl;
    }

    // check expired after sp is destroyed
    cout << "wp.expired() == " << boolalpha
        << wp.expired() << endl;
    cout << "(bool)wp.lock() == " << boolalpha
        << (bool)wp.lock() << endl;

    return (0);
}
