#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nombre;
    char datos[1];
    int compresion;

    cout << "Comprobador de imágenes BMP" << endl;
    cout << "Introduce el nombre del archivo: ";
    getline(cin, nombre);

    ifstream fichero(nombre, ios::binary);

    if (!fichero.is_open()) {
        cerr << "Archivo no encontrado" << endl;
    } else {
        fichero.seekg(30, ios::beg);
        fichero.read(datos, sizeof(datos));
        fichero.close();
        compresion = static_cast<int>(datos[0]);

        if (compresion == 0) {
            cout << "Imagen sin compresión" << endl;
        } else {
            cout << "Imagen BMP comprimida" << endl;
        }
    }

    return 0;
}
