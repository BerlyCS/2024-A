/*3. Dado un vector con un conjunto de intervalos representados por un par de valores enteros (xi, xy), se solicita
unir los intervalos que se superponen. Por ejemplo, si se tiene los siguientes intervalos almacenados en un
vector [(12,20),(15,32),(45,89)], el resultado que se debe obtener es la uni ́on de intervalos resultantes: [(12,32),
(45,89)] . Todos almacenados en un vector de intervalos.*/
#include <iostream>
#include <vector>
using namespace std;

 vector<vector<int>> fun3(vector<vector<int>> test) {
    vector<vector<int>> tmp;
    tmp.push_back(test[0]);
    for (int i=0; i<test.size()-1; i++) {
        if ( !(test[i][1] > test[i+1][0]) ){
            tmp.push_back(test[i+1]);
        }
    }
    return tmp;
}


int main() {
    vector<vector<int>> test = {{12,20},{15,32},{45,89}};
    vector<vector<int>> result = fun3(test);

    for (int i=0; i<result.size();i++) {
        for (int j=0;j<2;j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<"  ";
    }

}
