/*Utilizando Threads, modifique las funciones de multiplicaci ́on y suma de matrices para realizar el proceso
en el menor tiempo posible de forma paralela. Describa el proceso planteado. Probar con una matriz de
1000 × 1000.*/
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

void sumar(long** m1,long** m2,long** res,long size, int core,int step) {
    for (long i=core*step; i<((core+1)*step < size ? (core+1)*step : size ); i++) {
        for (long j=0; j<size; j++) {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

long** suma_mat(long** mat1, long** mat2, long x, long y) {
    vector<thread> hilos;
    int cores=thread::hardware_concurrency();
    /* int cores=8; */
    int steps=x/cores +1;
    if (steps == 0) {
        cores = x;
        steps = 1;
    }
    cout<<"nucleos: "<<cores; 
    cout<<", pasos por nucleo: "<<steps<<endl;
    long** mat_res;

    gen_vector(mat_res, x,y);

    for (int core=0; core<cores; core++) {
        hilos.push_back(thread(sumar, mat1, mat2, mat_res, x, core, steps));
    }

    for (auto& thr : hilos) {
        thr.join();
    }
    return mat_res;
}

void operar(long** m1, long** m2, long** res, long core,  long step,long size) 
{
    for (long i=core*step; i<((core+1)*step < size ? (core+1)*step : size ) ; i++) {  
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
    /* int cores =8; */
    int steps=(x/cores)+1;
    if (steps == 0) {
        cores = x;
        steps = 1;
    }
    cout<<"nucleos: "<<cores<<' '; 
    cout<<", pasos por nucleo: "<<steps<<endl;
    long** mat_res;
    gen_vector(mat_res, x,y);

    
    for (long core=0; core<cores; core++) {  
        hilos.push_back(thread(operar, mat1, mat2, mat_res, core, steps, x));
    }

    for (auto& hilo : hilos) {
        hilo.join();
    }
    return mat_res;
}

int main() {
    long sq_size=10;
    long** mat1, **mat2;
    gen_random(mat1, sq_size,sq_size); gen_random(mat2,sq_size,sq_size);
    printm(mat1, sq_size, sq_size); printm(mat2, sq_size, sq_size);

    {//Suma
        auto start = std::chrono::high_resolution_clock::now();
        long** product=suma_mat(mat1, mat2, sq_size,sq_size);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
        cout << "Suma en " << duration.count() << " ms" << endl;
        printm(product, sq_size, sq_size);
    }

    {//Multiplicacion
        auto start = std::chrono::high_resolution_clock::now();
        long** product=multiplicaci(mat1, mat2, sq_size,sq_size);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
        cout << "Multiplicacion en " << duration.count() << " ms" << endl;
        printm(product, sq_size, sq_size);
    }
}
