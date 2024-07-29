#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <memory> // Para std::unique_ptr

using namespace std;

template <typename T>
class coord {
public:
    T x, y;
    unique_ptr<coord<T>> next;
    coord() : next(nullptr) {}
    coord(T x, T y) : x(x), y(y), next(nullptr) {}
};

template <typename T>
class list {
private:
    unique_ptr<coord<T>> head;
    coord<T>* last;
    coord<T>* ptr;

public:
    list() : head(nullptr), last(nullptr), ptr(nullptr) {}

    list(T x, T y) {
        head = make_unique<coord<T>>(x, y);
        ptr = head.get();
        last = head.get();
    }

    void insertar(T x, T y) {
        if (head != nullptr) {
            last->next = make_unique<coord<T>>(x, y);
            last = last->next.get();
        } else {
            head = make_unique<coord<T>>(x, y);
            last = head.get();
        }
    }

    void insert_ord(T x, T y) {
        if (head == nullptr) {
            head = make_unique<coord<T>>(x, y);
            last = head.get();
            ptr = head.get();
            return;
        } else if (last != nullptr && last->y < y) {
            last->next = make_unique<coord<T>>(x, y);
            last = last->next.get();
            return;
        } else if (y < head->y) {
            auto tmp = make_unique<coord<T>>(x, y);
            tmp->next = move(head);
            head = move(tmp);
            return;
        }
        ptr = head.get();
        while (ptr->next != nullptr) {
            if (y < ptr->next->y) {
                break;
            } else {
                ptr = ptr->next.get();
            }
        }
        auto tmp = make_unique<coord<T>>(x, y);
        tmp->next = move(ptr->next);
        ptr->next = move(tmp);
    }

    void remove(int index) {
        if (head == nullptr) {
            return;
        }

        if (index == 0) {
            head = move(head->next);
            return;
        }

        coord<T>* prev = nullptr;
        ptr = head.get();
        int i = 0;
        while (ptr != nullptr && i < index) {
            prev = ptr;
            ptr = ptr->next.get();
            i++;
        }

        if (ptr == nullptr) {
            return;
        }

        if (prev != nullptr) {
            prev->next = move(ptr->next);
        }
    }

    coord<T>* buscar(T val) {
        ptr = head.get();
        while (ptr != nullptr) {
            if (ptr->x == val || ptr->y == val) {
                return ptr;
            }
            ptr = ptr->next.get();
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
        ptr = head.get();
        while (ptr != nullptr) {
            cout << ptr->x << ',' << ptr->y << ' ';
            ptr = ptr->next.get();
        }
        cout << endl;
    }

    void write_sorted() {
        ofstream out("DataSorted.txt");

        ptr = head.get();
        while (ptr != nullptr) {
            out << ptr->x << ' ' << ptr->y << endl;
            ptr = ptr->next.get();
        }
        out.close();
    }
};

void leer() {
    list<double> coleccion;
    ifstream file("DataGen.txt");
    string x, y;
    /* int i = 0; */
    auto start = chrono::high_resolution_clock::now();

    while (file >> x && file >> y) {
        x.pop_back();
        coleccion.insert_ord(stod(x), stod(y));
        /* if (i++ % 10000 == 0) cout << i << ' ' << flush; */
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << " por " << duration.count() << " ms" << endl;
    cout << " por " << duration.count() / 1000 << " segundos" << endl;
    cout << "Primer Y: " << coleccion.getFirstY() << endl;
    cout << "Ultimo Y: " << coleccion.getLastY() << endl;
    cout << "Escribiendo...\n";
    coleccion.write_sorted();
}

int main() {
    cout << "Leyendo archivo...\n";
    leer();

}
