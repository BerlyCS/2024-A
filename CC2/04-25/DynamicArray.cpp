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

int DynamicArray::get(int i) const {
    return data[i];
}

int DynamicArray::getsize() const {
    return this->size;
}

DynamicArray::DynamicArray() {
    size=0;
    data = new int[size];
}

DynamicArray::DynamicArray(int arr[], int size) {
    this->size=size;
    data = new int[size];

    for (int i=0;i<size;i++) {
        data[i]=arr[i];
    }
}

DynamicArray::DynamicArray(DynamicArray &b) {
    this->size = b.getsize();
    data = new int[size];

    for (int i=0; i<size; i++) {
        data[i] = b.get(i);
    }
}

DynamicArray::~DynamicArray() {
    delete [] data;
}

void DynamicArray::push_back(int val) {
    int* tmp= new int[size +1];

    for (int i=0; i<size; i++) {
        tmp[i] = data[i];
    }
    tmp[size] = val;

    delete data;
    data = tmp;
}

void DynamicArray::insert(int index, int val) {
    int* tmp= new int[size +1];
    bool inserted=false;
    for (int i=0; i<size; i++) {
        if (i<index)
            tmp[i] = tmp[i];
        else if (i==index) {
            tmp[i] = val;
        }
        else {
            tmp[i+1]=data[i];
        }

    }
    delete data;
    data = tmp;
}

void DynamicArray::print() {
    for(int i=0;i<size;i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}


