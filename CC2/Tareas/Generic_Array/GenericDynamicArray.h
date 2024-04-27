
template<typename T>
class GenericDynamicArray {
    private:
        int size;
        T* data;
    public:
        GenericDynamicArray();
        GenericDynamicArray(GenericDynamicArray<T> &b);
        ~GenericDynamicArray();
        int getsize();
        int get(int index);
        void push_back(T val);
        T pop_back();
        void insert(int index, T val);
        void remove(int index);
        void print();
};
