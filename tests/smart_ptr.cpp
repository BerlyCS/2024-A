#include <iostream>
#include <memory>
#include <ostream>
using namespace std;

class dot {
    int x;
        public:
    dot(int x) : x(x) {}
        int get() {return x;}
};
int main() {

    {
        int value = 8;
        /* cout<<&value<<endl; */
        unique_ptr<int> val_ptr = make_unique<int>(value);
        /* cout<<val_ptr.get()<<' '<<*val_ptr<<endl; */

        //Sigue teniendo la misma direccion
        /* cout << value << ' '<< &value<<endl; */

        //Se puede asignar a un raw pointer xdd
        int* val3 = val_ptr.get();
        /* cout<<val3<<' '<<*val3<<endl; */


        unique_ptr<int> val2(val_ptr.release()); 
        /* cout<<val_ptr.get()<<endl;  //val_ptr es 0 */
        /* cout<<val3<<' '<<*val3<<endl; //val3 sigue disponible? */
        /* cout<<val2.get()<<' '<<*val2<<endl; //ahora este es el dueño */

        val2.reset();
        //Val2 ahora es 0
        /* cout<<val2.get()<<endl; */
        //Ahora val3 que apuntaba a val_ptr es indefinido
        //un dangling pointer
        /* cout<<val3<<' '<<*val3<<endl; */
        //raw pointers no verifican si ya se borro
    }
    
    int *ptr1{new int(8)};
    {
        unique_ptr<int> ptr2(ptr1);
        cout<<ptr1<< ' '<<ptr2.get()<<endl;

        //omitir esta linea
        /* delete ptr1; */


        cout<<ptr2.get()<<endl;

    } //ptr2 usa delete 
    cout<<*ptr1<<endl; //Puntero colgante

    {
        shared_ptr<dot> shptrC(new dot(2));
        shared_ptr<dot> shptrA = make_shared<dot>(dot(2));
        shared_ptr<dot> shptr1(new dot(2));
        shared_ptr<dot> shptr2 = shptr1;
        cout<<shptr2.use_count()<<endl;
    }

}
