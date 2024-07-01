#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
using namespace std;

int main() {
    weak_ptr<int> num;
    num.reset();
    shared_ptr<int> nm1 = make_shared<int>(5);
    cout<<nm1.use_count()<<endl;
    nm1.reset();

    int n1,n2;

    unique_ptr<int> num2 = make_unique<int>(n1);
    cout<<&n1<<' '<<num2.get();
    unique_ptr<int> num3 = std::move(num2);
    cout<<' '<<num2.get();
    
}
