/*2. Se tiene un vector con una cantidad > 1000 elementos enteros aleatorios. Se pide implementar una funci ́on
que elimine todos los elementos duplicados y retorne elementos  ́unicos.*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

vector<int> gen_random(int size) {
    srand(time(NULL));
    vector<int> tmp(size); 
    
    for(int i=0;i<size;i++)
         tmp[i] = rand()%100;
    return tmp;
}
//eliminar elementos duplicados
vector<int> fun2(vector<int> vect) {
    cout<<"o"<<' ';
    
    vector<int> fun2;
    fun2.push_back(vect[0]);

    for (int i=1; i<vect.size(); i++) {
        bool exist = false;

        for (int k = 0; k<fun2.size(); k++) {
            if (fun2[k] == vect[i]) {
                exist = true;
                break;
            }
        }
        if (!exist) {
            fun2.push_back(vect[i]);
        }
    }

    return fun2;
}

int main() {
    vector<int> test = gen_random(1000);
    vector<int> result = fun2(test); 
cout<<result.size()<<endl;
    for (int i: result) {
        cout<< i<<" ";
    }
}
