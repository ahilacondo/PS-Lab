#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream archivo("prueba.txt");
    string linea;
    cout << "Se ha leído: " << endl;
    int contador = 0;

    while (getline(archivo, linea)) {
        cout << linea << endl;
        contador++;
        if (contador == 25) {
            cin.ignore();
            contador = 0;
        }
    }

    archivo.close();
    return 0;
}
