#include <iostream>
#include <vector>

using namespace std;

vector<int> ret_ref() {
    cout<<"Original: ";
    vector<int> a = {1};
    cout<<&a[0]<<endl;
    return a;
}

int main() {

}
