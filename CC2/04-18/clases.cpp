#include <cmath>
#include <iostream>
using namespace std;
class point {
        int x,y;
    public:
        friend class vector;
        point(int _x, int _y) : x(_x), y(_y) {}
        /* point(point &p1) : x(p1.getX()), y(p1.getY()) {} */

        int getX() const { return x; }
        int getY() const { return y; }
        void setX(int x) { this->x=x; }
        void setY(int y) { this->y=y; }

};

class vector {
        /* point test; */
        point *P, *Q;
        long double length;
    public:
        vector(int _x1, int _y1, int _x2, int _y2) {
            P = new point(_x1,_y1);
            Q = new point(_x2,_y2);
            length = sqrt((_x2-_x1)*(_x2-_x1)+(_y2-_y1)*(_y2-_y1));
        }
        ~vector() {
            delete P;
            delete Q;
        }

        void print_info() const {
            cout<<"Vector = ("<<Q->getX() - P->getX() <<", "<<Q->getY() - P->getY()<<")\n";
            cout<<"Length: "<<length<<"\n";
        }
};

int main() {
    vector v1(3,3,5,0);
    v1.print_info();

    int x1,y2,x2,y1;
    cout<<"x1: ";
    cin>>x1;
    cout<<"y1: ";
    cin>>y1;
    cout<<"x2: ";
    cin>>x2;
    cout<<"y2: ";
    cin>>y2;
    vector v2(x1,y1,x2,y2);
    v2.print_info();
}
