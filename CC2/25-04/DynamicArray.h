#include <iostream>

using namespace std;

class DynamicArray {
    private:
        int size;
        int* data;
    public:
        DynamicArray();
        DynamicArray(int arr[], int size);
        DynamicArray (DynamicArray &b);
        ~DynamicArray();
        int getsize() const;
        int get(int i) const;
        void push_back(int val);
        void insert(int index, int val);
        void remove (int index);
        void print();
};
