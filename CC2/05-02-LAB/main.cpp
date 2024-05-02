#include <bits/chrono.h>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void print(vector<vector<vector<int>>> d) {
    for (int i=0;i<1000;i++)
        for (int j=0; j<1000;j++) 
            for (int k=0;k<3;k++) 
                cout << d[i][j][k] << " ";
} 
void print(int*** d) {
    for (int i=0;i<1000;i++)
        for (int j=0; j<1000;j++) 
            for (int k=0;k<3;k++) 
                cout << d[i][j][k] << " ";
} 

vector<vector<vector<int>>> fun1(int x=1000, int y=1000, int z=3) {
    srand(time(NULL));
    vector<vector<vector<int>>> tmp;
    for (int i=0;i<1000;i++){
        vector<vector<int>> plano;
        for (int j=0; j<1000;j++) {
            vector<int> vect;
            for (int k=0;k<3;k++) {
                vect.push_back(rand()%10);
            }
            plano.push_back(vect);
        }
        tmp.push_back(plano);
    }

    return tmp;
} 

vector<vector<vector<int>>> suma_mat(vector<vector<vector<int>>> a,
        vector<vector<vector<int>>> b) {
    vector<vector<vector<int>>> c(1000, vector<vector<int>>(1000, vector<int>(3, 0)));
    for (int i=0;i<1000;i++){
        for (int j=0; j<1000;j++) {
            for (int k=0;k<3;k++) {
                c[i][j][k] = a[i][j][k] + b[i][j][k];
            }
        }
    }
    return c;
} 

int*** fun2() {
    int*** cube;
    cube = new int**[1000];
    for (int i=0;i<1000;i++) {
        cube[i] = new int*[1000];
    }

    for (int i=0;i<1000;i++) {
        for (int j=0; j<1000;j++ ){
            cube[i][j] = new int[3];
            for (int k=0;k<3;k++) {
                cube[i][j][k] = rand()%10;
            }
        }
    }
    return cube;
}

int*** suma_mat(int ***a, int***b) {
    int*** c;
    c = new int**[1000];
    for (int i=0;i<1000;i++) {
        c[i] = new int*[1000];
    }

    for (int i=0;i<1000;i++) {
        for (int j=0; j<1000;j++ ){
            c[i][j] = new int[3];
            for (int k=0;k<3;k++) {
                c[i][j][k] = 0;
            }
        }
    }

    for (int i=0;i<1000;i++) {
        for (int j=0; j<1000;j++ ){
            for (int k=0;k<3;k++) {
                c[i][j][k] = a[i][j][k] + b[i][j][k];
            }
        }
    }
    return c;
}

void delete_cube(int *** cube) {
    for (int i=0;i<1000;i++) {
        for (int j=0; j<1000;j++ ){
            delete[] cube[i][j];
        }
    }
    for (int i=0;i<1000;i++) {
        delete[] cube[i];
    }

    delete[] cube;

}

int main() {
    int resp = -1;
    auto start = std::chrono::high_resolution_clock::now();
/* vector<vector<vector<int>>> vect(5, vector<vector<int>>(6, vector<int>(5, 0))) */ 
    vector<vector<vector<int>>> test1 = fun1();
    /* print(test1); */
    vector<vector<vector<int>>> test2 = fun1();
    /* print(test2); */
    vector<vector<vector<int>>> suma = suma_mat(test1, test2);
    /* print(suma); */
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout<< resp << " for " << duration.count() << " ms" << endl;

    /* int*** a = fun2(); */
    /* int*** b = fun2(); */
    /* int *** c = suma_mat(a,b); */
    /* print(c); */

}
