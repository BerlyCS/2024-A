#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

template <typename T>
class coord {
    public:
    T x,y;
    coord<T>* next;
    coord<T>() {next=nullptr;}
    coord<T>(T x, T y) : x(x), y(y) {}
};

template <typename T>
class list {
    private:
        coord<T>* head;
        coord<T>* last;
        coord<T>* ptr;

    public:
        list<T>() {
            head = nullptr;
            last= nullptr;
            ptr=nullptr;
        }

        list<T>(T x, T y) {
            head = new coord<T>(x,y);
            ptr = head;
            last = head;
        }

        void insertar(T x, T y) {
            if (head != nullptr) {
                last->next = new coord<T>(x,y);
                last = last->next;
            } 
            else {
                head = new coord<T>(x,y);
                last = head;
            }
        }

        void insert_ord(T x, T y) {
            if (head == nullptr) {
                head = new coord<T>(x,y);
                last = head;
                ptr = head;
                return;
            }
            else if (last != nullptr && last->y < y) {
                last->next = new coord<T>(x,y);
                last = last->next;
                return;
            }
            else if (y < head->y) {
                coord<T>* tmp = new coord<T>(x,y);
                tmp->next = head;
                head = tmp;
                return;
            }
            ptr = head;
            while (ptr->next != nullptr) {
                if (y < ptr->next->y) {
                    break;
                }
                else {
                    ptr = ptr->next;
                }
            } 
            coord<T>* tmp = new coord<T>(x,y);
            coord<T>* next = ptr->next;
            ptr->next = tmp;
            tmp->next = next;
            
        }

        void remove(int index) {
            int i = 0;

            ptr = head;
            coord<T>* prev, next;
            while (ptr != nullptr && i++ < index) {
                prev = ptr;
                ptr = ptr->next;
            }

            next = ptr->next;
            delete ptr;
            prev->next = next;
        }

        coord<T>* buscar(T val) {
            ptr = head;
            while (ptr != nullptr) {
                if (ptr->x == val || ptr->y ) {
                    return ptr;
                }
                ptr = ptr->next;
            }
            return nullptr;
        } 

        T getFirstY() {
            return head->y;
        }
        T getLastY() {
            return last->y;
        }
};

list<double> leer() {
    list<double> coleccion;
    ifstream file("DataGen.txt");
    string x,y;
    int i=0;
    auto start = std::chrono::high_resolution_clock::now();

    while (file>>x && file>>y) {
        x.pop_back();
        coleccion.insert_ord(stod(x), stod(y));
        if (i++ % 10000 == 0) cout<<i<<' '<<flush;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
    cout << " por " << duration.count() << " ms" << endl;
    cout << " por " << duration.count()/1000 << " segundos" << endl;
    cout<<"Primer Y: "<<coleccion.getFirstY()<<endl;
    cout<<"Ultimo Y: "<<coleccion.getLastY()<<endl;
    return coleccion;
}

int main() {
    /* list<double> test = leer(); */
    list<double> a;
    a.insert_ord(1., 6.);
    a.insert_ord(1., 4.);
    a.insert_ord(1., 3.);
    a.insert_ord(1., 2.);
    a.insert_ord(1., 1.);
    a.insert_ord(1., 5.);
}
