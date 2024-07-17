#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <memory>
#include <utility>

using namespace std;

template <typename T>
class coord {
    public:
    T x,y;
    unique_ptr<coord<T>> next;
    coord() {next=nullptr;}
    coord(T x, T y) : x(x), y(y), next(nullptr) {}
};

template <typename T>
class list {
    private:
        unique_ptr<coord<T>> head;
        unique_ptr<coord<T>> last;

    public:
        list() {
            head = nullptr;
            last= nullptr;
        }

        list(T x, T y) {
            head = make_unique(coord<T>(x,y));
            last = head.get();
        }

        void insertar(T x, T y) {
            if (head != nullptr) {
                last->next = make_unique<coord<T>>(coord<T>(x,y));
                last = last->next.get();
            } 
            else {
                head = make_unique<coord<T>>( coord<T>(x,y));
                last = head.get();
            }
        }

        void insert_ord(T x, T y) {
            if (head == nullptr) {
                head = make_unique<coord<T>>(coord<T>(x,y));
                last = last.get();
            }
            else if (last != nullptr && last->y < y) {
                last->next = make_unique<coord<T>>( coord<T>(x,y));
                last = std::move(last->next);
            }
            else if (y < head->y) {
                unique_ptr<coord<T>> tmp = make_unique<coord<T>> (coord<T>(x,y));
                tmp->next = std::move(head);
                head = std::move(tmp);
            }
            unique_ptr<coord<T>> ptr(std::move(head));

            while (ptr->next != nullptr) {
                if (y < ptr->next->y) {
                    break;
                }
                else {
                    ptr = std::move(ptr->next);
                }
            } 
            unique_ptr<coord<T>> tmp = make_unique<coord<T>>(coord<T>(x,y));
            unique_ptr<coord<T>> next =std::move( ptr->next);
            ptr->next = std::move(tmp);
            tmp->next = std::move(next);
        }
 
        void remove(int index) {
            if (head == nullptr) {
                return;
            }

            if (index == 0) {
                unique_ptr<coord<T>> ptr = head->next;
                delete head;
                head = ptr;
                return;
            }

            unique_ptr<coord<T>> ptr = head;
            unique_ptr<coord<T>> prev = nullptr;

            int i = 0;
            while (ptr != nullptr && i < index) {
                prev = ptr;
                ptr = ptr->next;
                i++;
            }

            if (ptr == nullptr) {
                return;
            }

            unique_ptr<coord<T>> next = ptr->next;
            delete ptr;
            if (prev != nullptr) {
                prev->next = next;
            }
        }

        unique_ptr<coord<T>> buscar(T val) {
            unique_ptr<coord<T>> ptr(head);
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
        void print() {
            unique_ptr<coord<T>> ptr(move(head));

            while (ptr != nullptr) {
                cout<<ptr->x<<','<<ptr->y<<' ';
                ptr = ptr->next;
            }
            cout<<endl;
        }
        void write_sorted() {
            ofstream out("DataSorted.txt");

            unique_ptr<coord<T>> ptr;
            while (ptr != nullptr) {
                out<<ptr->x<<' '<<ptr->y<<endl;
                ptr = std::move(ptr->next);
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
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start); 
    cout << " por " << duration.count() << " ms" << endl;
    cout << " por " << duration.count()/1000 << " segundos" << endl;
    cout<<"Primer Y: "<<coleccion.getFirstY()<<endl;
    cout<<"Ultimo Y: "<<coleccion.getLastY()<<endl;
    cout<<"Escribiendo...\n";
    coleccion.write_sorted();
}

int main() {
    cout<<"Leyendo archivo...\n";
    leer(); 
}
