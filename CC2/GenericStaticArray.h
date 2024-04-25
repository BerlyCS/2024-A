/* #ifndef GEN_STATIC_ARRAY_H */

template <typename T>
class GenericStaticArray {
    private:
        int size;
        T* data;
    public:
        GenericStaticArray<T>();

        GenericStaticArray<T>(T& type);
        int get(int index);
        void set(int index, T val);
        int getsize();
};
