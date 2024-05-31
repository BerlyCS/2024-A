#include <iostream>
using namespace std;

class DocumentSource {
public:
    virtual void LoadDocument() = 0;
    virtual ~DocumentSource() = default;
};

class FileSource : public DocumentSource {
public:
    virtual void LoadDocument() {
        cout << "Imprimiendo desde archivo" << endl;
    }
};

class WebSource : public DocumentSource {
public:
    virtual void LoadDocument() {
        cout << "Imprimiendo desde internet" << endl;
    }
};

class Printer {
    DocumentSource *printerService = nullptr;
public:
    Printer(DocumentSource *service) : printerService(service) {
        if(printerService == nullptr){
            throw invalid_argument("Servicio no debe ser null");
        }
    }
    void getDocument() {
        cout << "Printer needs a document!" << endl;
        printerService->LoadDocument();
    }
};

int main() {
    DocumentSource *File = new FileSource();
    DocumentSource *Web = new WebSource();

    Printer impresora(File);
    impresora.getDocument();

    Printer fax(Web);
    fax.getDocument();

    delete File;
    delete Web;
    return 0;
}
