#include <iostream>
#include <ostream>
using namespace std;

void place_queen(char** table, int SIZE, int row) {
    for (int i=0; i<SIZE; i++) {
        if (table[row][i] != 'x') {
            table[row][i] = 'q';
        }
    }
}

void print(char** table, int size) {
    for (int i{0}; i<size; i++) {
        for (int j{0};j<size;j++) {
            cout<<table[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int main() {
    const short SIZE{ 8 };
    char table[SIZE][SIZE];
    for (char* i: table) {
        for (auto j : i)
    }

    for (int i=0; i<SIZE; i++) {
        
    }
}
