#include <iostream>
#include <fstream>
using namespace std;

int main () {
    fstream ficheroEntrada;
    string nombre;
    string frase;

    cout << "Dime el nombre del fichero: ";
    getline(cin, nombre);

    ficheroEntrada.open(nombre.c_str(), ios::in);
    if (ficheroEntrada.is_open()) {
        while (getline(ficheroEntrada, frase)) {
            cout << "Leido: " << frase << endl;
        }
        ficheroEntrada.close();
    } else {
        cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
    }

    return 0;
}
