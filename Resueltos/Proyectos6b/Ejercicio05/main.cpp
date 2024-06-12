#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char meses[][20] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", 
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    char buffer[20];
    ofstream archivoSalida("meses.dat", ios::out | ios::binary);
    
    cout << "Creando archivo con los nombres de los meses:" << endl;
    for(int i = 0; i < 12; i++) {
        archivoSalida.write(meses[i], 20);
    }
    archivoSalida.close();

    ifstream archivoEntrada("meses.dat", ios::in | ios::binary);
    
    cout << "\nLeyendo archivo de forma secuencial:" << endl;
    while(archivoEntrada.read(buffer, 20)) {
        cout << buffer << endl;
    }
    archivoEntrada.clear();

    cout << "\nLeyendo archivo de forma aleatoria:" << endl;
    for(int i = 11; i >= 0; i--) {
        archivoEntrada.seekg(20 * i, ios::beg);
        archivoEntrada.read(buffer, 20);
        cout << buffer << endl;
    }

    archivoEntrada.seekg(0, ios::end);
    int fileSize = archivoEntrada.tellg();
    cout << "\nNúmero de registros: " << fileSize / 20 << endl;

    archivoEntrada.close();
    return 0;
}
