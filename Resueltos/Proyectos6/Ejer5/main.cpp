#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fichero("prueba.txt");
    string linea;

    if (fichero.is_open()) {
        cout << "Se ha leido: " << endl;
        while (getline(fichero, linea)) {
            cout << linea << endl;
        }
        fichero.close();
    } else {
        cout << "No se pudo abrir el archivo para lectura" << endl;
    }

    return 0;
}
