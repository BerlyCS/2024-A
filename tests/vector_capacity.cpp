
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a(100,1);
    cout<<a.size()<<endl;
    cout<<a.capacity()<<endl;
    a.push_back(5);
    cout<<a.size()<<endl;
    cout<<a.capacity()<<endl;
}
