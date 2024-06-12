#include <iostream>
#include <fstream>
using namespace std;

// Clase derivada de "exception" para manejar excepciones
// de copia de ficheros.
class CopiaEx: public exception {
public:
    CopiaEx(int mot) : exception(), motivo(mot) {}
    const char* what() const throw();
private:
    int motivo;
};

const char* CopiaEx::what() const throw() {
    switch(motivo) {
        case 1:
            return "Fichero de origen no existe";
        case 2:
            return "No es posible abrir el fichero de salida";
        default:
            return "Error inesperado";
    }
}

void CopiaFichero(const char* Origen, const char* Destino);

int main() {
    const char Desde[] = "excepcion.cpp"; // Nombre del archivo de origen
    const char Hacia[] = "excepcion.cpy"; // Nombre del archivo de destino

    try {
        CopiaFichero(Desde, Hacia);
        cout << "El archivo se copió correctamente." << endl;
    }
    catch(const CopiaEx &ex) {
        cout << "Excepción capturada: " << ex.what() << endl;
    }

    return 0;
}

void CopiaFichero(const char* Origen, const char* Destino) {
    unsigned char buffer[1024];
    int leido = 0;

    ifstream fe(Origen, ios::in | ios::binary);
    if (!fe.is_open()) {
        throw CopiaEx(1); // Lanzar excepción si el archivo de origen no se puede abrir
    }

    ofstream fs(Destino, ios::out | ios::binary);
    if (!fs.is_open()) {
        fe.close();
        throw CopiaEx(2); // Lanzar excepción si el archivo de destino no se puede abrir
    }

    while (!fe.eof()) {
        fe.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
        leido = fe.gcount();
        if (leido > 0) {
            fs.write(reinterpret_cast<char*>(buffer), leido);
        }
    }

    fe.close();
    fs.close();
}
