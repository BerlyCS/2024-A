/*1. Implementar las funciones de multiplicaci ́on y suma de matrices, mida el tiempo de ejecuci ́on (std::chrono::high
resolution clock) de cada una de las operaciones con una matriz de 1000 × 1000*/

#include <chrono>
#include <cstdlib>
#include <iostream>
using namespace std;

void printm(long** mat, long x ,long y) {
    for (long i=0; i<y; i++) {
        for (long j=0; j<x; j++) {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void gen_random(long**& mat, long x, long y) {
    srand(5);
    mat = new long*[y];
    for (long i=0; i<y; i++) {
        mat[i] = new long[x];
        for (long j=0; j<x; j++) {
            mat[i][j] = rand();
        }
    }
}

void gen_vector(long **& mat, long x ,long y) {
    mat = new long*[y];
    for (long i=0; i<y; i++) {
        mat[i] = new long[x]();
    }
}

long** suma_mat(long** mat1, long** mat2, long x, long y) {
    long** mat_res;
    gen_vector(mat_res, x,y);

    for (long i=0; i<x; i++) {
        for (long j=0; j<y; j++) {
            mat_res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat_res;
}

long** multiplicaci(long** mat1, long** mat2, long x, long y) {
    long** mat_res;
    gen_vector(mat_res, x,y);

    for (long i=0; i<x; i++) {
        for (long j=0; j<y; j++) {
            for (long k=0;k<x; k++) {
                mat_res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mat_res;
}

int main() {
    long sq_size=1000;
    long** mat1, **mat2;
    gen_random(mat1, sq_size,sq_size); gen_random(mat2,sq_size,sq_size);

    {//Suma
        auto start = std::chrono::high_resolution_clock::now();
        long** product=suma_mat(mat1, mat2, sq_size,sq_size);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
        cout << "Suma en " << duration.count() << " ms" << endl;
    }

    {//Multiplicacion
        auto start = std::chrono::high_resolution_clock::now();
        long** product=multiplicaci(mat1, mat2, sq_size,sq_size);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
        cout << "Multiplicacion en " << duration.count() << " ms" << endl;
    }
}
