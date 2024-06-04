/*
2. Utilizando el patron desarrolle la estructura de clase de un servicio de mensajerıa instantanea de un profesor
a sus alumnos. Los alumnos deben de crearse con su nombre y se deben de registrar en el Chat. Todos los
mensajes deben ser enviados con el nombre del profesor. De forma automatica los alumnos deben de tener
ya la informacion recibida indicando quien lo envio, el mensaje y su nombre de acuerdo a la informaci´on
enviada. Ademas, los alumnos tendr´an una funcion que muestre el historial de mensajes recibidos. En la
Fig.1 se muestra un ejemplo de como debe ser la funcion main con el patron y el resultado esperado (Fig.2)*/
#include <iostream>

using namespace std;

class pre_observador {
    public:
        virtual void actualizar(string mensaje) = 0;
};

class pre_usuario {
    public:
        virtual void conectar(pre_observador) = 0;
        virtual void desconectar(pre_observador) = 0;
};

class usuario {
    private:
        string nombre;

    public:
        usuario(string nombre) {
            this->nombre = nombre;
        }
        usuario(usuario& tmp) {
            this->nombre = tmp.nombre;
        }
        void conectar(pre_observador& observer);
        void desconectar(pre_observador& observer);
        void notificar();
        void printinfo() const;
};

void usuario::printinfo() const{
    cout<<this->nombre<<endl;
}

class observador : public pre_observador {
    public:
        observador(usuario&);
        void actualizar(string mensaje);
};

class chat {
    private:
        usuario** list;
        int count;
    public:
        chat() {
            count = 0;
            list = new usuario*[count];
        }
        void registrar(usuario& alumno);
        void enviar(string);
        void lista() const;
};

void chat::enviar(string mensaje) {

}

void chat::lista() const {
    for (int i=0;i<count;i++) {
        list[i]->printinfo();
    }
}
void chat::registrar(usuario& alumno) {
    usuario** tmp = new usuario*[count];
    for (int i=0; i<count;i++) {
        tmp[i] = list[i];
    }
    tmp[count] = new usuario(alumno);;
    count++;
    delete list;
    list = tmp;
}

int main() {
    chat sistema;

    usuario juan("juan");
    usuario jose("jose");

    sistema.registrar(juan);
    sistema.registrar(jose);

    sistema.lista();

    
}
