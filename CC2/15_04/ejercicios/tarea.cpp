#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void insertar(vector<int> &array, int value, int &min) 
{
    array.push_back(value);
    int size=array.size();
    if (value < min) 
    {
        swap(array[0], array[size-1]);
        min=value;
    }

    for (int i=0;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main() {
    vector<int> array;
    int min=INT_MAX;
    while (true) {
        int value;
        cout<<"Insertar: "; 
        cin>>value;
        insertar(array, value, min);
        cout<<"Array[0]: "<<array[0]<<endl;
    }
}
