/*Utilizando Threads, modifique las funciones de multiplicaci ́on y suma de matrices para realizar el proceso
en el menor tiempo posible de forma paralela. Describa el proceso planteado. Probar con una matriz de
1000 × 1000.*/
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

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
            mat[i][j] = rand()%10+1;
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

inline void operar(long** m1, long** m2, long** res, long core,  long step,long size) 
{
    for (long i=core*step; i<(core+1)*step; i++) {  
        for (long j=0; j<size; j++) {
            for (long k=0;k<size; k++) {

                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

long** multiplicaci(long** mat1, long** mat2, long x, long y) {
    vector<thread> hilos;
    int cores=thread::hardware_concurrency();
    int steps=x/cores;
    long** mat_res;
    gen_vector(mat_res, x,y);

    for (long i=0; i<cores; i++) {  
        /* cout<<hilos.size()<<' '<<flush; */
        hilos.push_back(thread(operar, mat1, mat2, mat_res, i, steps, x));
    }

    for (auto& hilo : hilos) {
        hilo.join();
    }
    return mat_res;
}

int main() {
    long sq_size=1000;
    long** mat1, **mat2;
    gen_random(mat1, sq_size,sq_size); gen_random(mat2,sq_size,sq_size);

    /* printm(mat1, sq_size, sq_size); printm(mat2, sq_size, sq_size); */

    auto start = std::chrono::high_resolution_clock::now();
    long** product=multiplicaci(mat1, mat2, sq_size,sq_size);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
    cout << " por " << duration.count() << " ms" << endl;

    /* printm(product, sq_size, sq_size); */
}
