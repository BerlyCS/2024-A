#include <iostream>

using namespace std;

void leak_mem() {
    int *ptr=new int[10000];
}
int main() {
    for (;;)
        leak_mem();

}
