/*
2. Utilizando el patron desarrolle la estructura de clase de un servicio de mensajerıa instantanea de un profesor
a sus alumnos. Los alumnos deben de crearse con su nombre y se deben de registrar en el Chat. Todos los
mensajes deben ser enviados con el nombre del profesor. De forma automatica los alumnos deben de tener
ya la informacion recibida indicando quien lo envio, el mensaje y su nombre de acuerdo a la informaci´on
enviada. Ademas, los alumnos tendr´an una funcion que muestre el historial de mensajes recibidos. En la
Fig.1 se muestra un ejemplo de como debe ser la funcion main con el patron y el resultado esperado (Fig.2)*/

#include <iostream>
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

        void remove(int index) {
            X* tmp = new X[size - 1];
            for (int i =0; i<size; i++) {
                if (i < index)
                    tmp[i] = data[i];
                else if (i> index)
                    tmp[i-1] = data[i];
            }
        }
        int getsize() const {
            return size;
        }
        X operator[](int i) const {
            return data[i];
        }
};

class Observer {
public:
	virtual void actualizar(string str1, string str2) = 0;
    virtual string get_name() const = 0;
};

class chat {
private:
	string mensaje;
	vect<Observer*> alumnos;
public:
	void registrarAlumno(Observer* observer) {
		alumnos.push_back(observer);
	}

	void eliminarAlumno(string nombre) {
        for (int i =0; i<alumnos.getsize(); i++) {
            if (alumnos[i]->get_name() == nombre) {
                alumnos.remove(i);
                cout<<"Eliminado a "<<nombre<<endl;
                return;
            }
        }
        cout<<"No se encontro a "<<nombre<<endl;
	}

	void notificar(string mensaje, string profesor) {
        for (int i=0; i<alumnos.getsize(); i++)
		    alumnos[i]->actualizar(mensaje, profesor);
	}

	void enviar(string mensaje, string profesor) {
		this->mensaje = mensaje;
		notificar(mensaje,profesor);
	}
};

class alumno : public Observer {
private:
    vect<string> historial;
    string nombre;
public:
    alumno(string nombre) : nombre(nombre) {}

	void actualizar(string mensaje, string profesor) {
		cout<<profesor<<" dice : "<<mensaje<<" a "<<nombre<<endl;
        historial.push_back(mensaje);
        historial.push_back("Enviado por: " + profesor);
	}

    void print_registro() const {
        for (int i=0; i<historial.getsize(); i+=2) {
            cout<<historial[i]<<endl;
        }
    }
    void registro_detallado() const {
        for (int i=0; i<historial.getsize(); i++)
            cout<<historial[i]<<endl;
    }
    string get_name() const {
        return nombre;
    }
};

int main() {
    chat sistema;
    alumno alumno1("Victor"); 
    alumno alumno2("Raul");

	sistema.registrarAlumno(&alumno1);
	sistema.registrarAlumno(&alumno2);
    
    sistema.enviar("Como estan?", "Profesor");
    sistema.enviar("Se hace envio de sus tareas", "Profesor");
    sistema.enviar("y de sus notas", "Profesor");

    cout<<"---------------------------\n";

    cout<<"Registro de "<<alumno1.get_name()<<endl;
    alumno1.print_registro();

    cout<<"---------------------------\n";

    cout<<"Registro de "<<alumno2.get_name()<<endl;
    alumno2.print_registro();

    cout<<"---------------------------\n";

    cout<<"Registro detallado "<<alumno1.get_name()<<endl;
    alumno1.registro_detallado();

    cout<<"---------------------------\n";

    cout<<"Registro detallado "<<alumno2.get_name()<<endl;
    alumno2.registro_detallado();

    cout<<"---------------------------\n";

    sistema.eliminarAlumno("Victor");
    sistema.eliminarAlumno("Raul");

	return 0;
}

