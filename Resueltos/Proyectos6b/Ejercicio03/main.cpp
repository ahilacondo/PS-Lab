#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nombre;
    string linea;

    cout << "Ingrese el nombre del archivo: ";
    getline(cin, nombre);

    ifstream fichero(nombre.c_str());

    if (!fichero.is_open()) {
        cerr << "¡El archivo no existe!" << endl;
        return 1;
    }

    if (getline(fichero, linea)) {
        if (linea.empty()) {
            cout << "El archivo está vacío" << endl;
        } else {
            cout << "El archivo tiene contenido" << endl;
        }
    } else {
        cout << "El archivo está vacío" << endl;
    }

    fichero.close();
    return 0;
}
