#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <memory>

using namespace std;

template <typename T>
class coord {
    public:
    T x,y;
    shared_ptr<coord<T>> next;
    coord() {next=nullptr;}
    coord(T x, T y) : x(x), y(y), next(nullptr) {}
};

template <typename T>
class list {
    private:
        shared_ptr<coord<T>> head;
        shared_ptr<coord<T>> last;
        shared_ptr<coord<T>> ptr;

    public:
        list() {
            head = nullptr;
            last= nullptr;
            ptr= nullptr;
        }

        list(T x, T y) {
            head = make_unique( coord<T>(x,y));
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
                head = make_unique<coord<T>>( coord<T>(x,y) );
                last = head;
                ptr = head;
                return;
            }
            else if (last != nullptr && last->y < y) {
                last->next = make_shared<coord<T>>( coord<T>(x,y));
                last = last->next;
                return;
            }
            else if (y < head->y) {
                shared_ptr<coord<T>> tmp = make_shared<coord<T>>(coord<T>(x,y));
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
            shared_ptr<coord<T>> tmp = make_shared<coord<T>>(coord<T>(x,y));
            shared_ptr<coord<T>> next = ptr->next;
            ptr->next = tmp;
            tmp->next = next;
        }

 
        void remove(int index) {
            if (head == nullptr) {
                return;
            }

            if (index == 0) {
                shared_ptr<coord<T>> ptr = head->next;
                head = ptr;
                return;
            }

            shared_ptr<coord<T>> ptr = head;
            shared_ptr<coord<T>> prev = nullptr;

            int i = 0;
            while (ptr != nullptr && i < index) {
                prev = ptr;
                ptr = ptr->next;
                i++;
            }

            if (ptr == nullptr) {
                return;
            }

            shared_ptr<coord<T>> next = ptr->next;
            if (prev != nullptr) {
                prev->next = next;
            }
        }

        shared_ptr<coord<T>> buscar(T val) {
            ptr = head;
            while (ptr != nullptr) {
                if (ptr->x == val || ptr->y == val ) {
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

        void write_sorted() {
            ofstream out("DataSorted.txt");

            ptr = head;
            while (ptr != nullptr) {
                out<<ptr->x<<' '<<ptr->y<<endl;
                ptr = ptr->next;
            }
            out.close();
        }
};

void leer() {
    list<double> coleccion;
    ifstream file("DataGen.txt");
    string x,y;
    /* int i=0; */
    auto start = std::chrono::high_resolution_clock::now();

    while (file>>x && file>>y) {
        x.pop_back();
        coleccion.insert_ord(stod(x), stod(y));
        /* if (i++ % 10000 == 0) cout<<i<<' '<<flush; */
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start); 
    cout << " por " << duration.count() << " microseconds" << endl;
    cout<<"Primer Y: "<<coleccion.getFirstY()<<endl;
    cout<<"Ultimo Y: "<<coleccion.getLastY()<<endl;
    /* cout<<"Escribiendo...\n"; */
    /* coleccion.write_sorted(); */
}

int main() {
    cout<<"Leyendo archivo...\n";
    leer();
}
