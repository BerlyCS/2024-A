#include <iostream>
#include <string>
using namespace std;

template <typename X>
class vect {
    private:
        X *data;
        unsigned int size;
    public:
        vect<X>() {
            size = 0;
            data = new X[size];
        }
        void push_back(X val) {
            X* tmp = new X[size+1];
            for (int i=0; i<size; i++) 
                tmp[i] = data[i];

            tmp[size] = val;
            delete[  ] data;
            data = tmp;
            size++;
        }
        void print() const {
            for (int i=0; i<size; i++) {
                cout<< data[i] << ' ';
            }
            cout<< endl;
        }

		X* begin() {
			return data;
		}
		X* end() {
			return data+size;
		}
};

class Observer {
public:
	virtual void actualizar(string mensaje) = 0;
};

class usuario {
private:
	vect<string> registro;
	string mensaje;
	vect<Observer*> observers;

public:
	void registerObserver(Observer* observer) {
		observers.push_back(observer);
	}

	void removeObserver(Observer* observer) {
		/* observers.pop(); */
	}

	void notifyObservers() {
		for (Observer* observer = *observers.begin(); observer != *observers.end(); observer++) {
			observer->actualizar(mensaje);
		}
	}

	void enviar(string mensaje) {
		this->mensaje = mensaje;
		notifyObservers();
	}
};

// Concrete Observer
class chat : public Observer {
public:
	void actualizar(string mensaje) {
		cout<<mensaje;
	}
};

int main() {
	usuario Raul;

	chat observer1;
	chat observer2;

	Raul.registerObserver(&observer1);
	Raul.registerObserver(&observer2);

	Raul.enviar("Hola");

	return 0;
}

