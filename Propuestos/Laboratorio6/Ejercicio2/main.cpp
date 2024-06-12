#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void guardarFrases() {
    ofstream archivo("frases.txt"); // Abrir el archivo en modo de escritura
    string frase;
    while (true) {
        cout << "Ingrese una frase (presione Enter para terminar): ";
        getline(cin, frase);
        // Verificar si el usuario ha presionado solo Enter
        if (frase.empty()) {
            break;
        }
        // Escribir la frase en el archivo
        archivo << frase << endl;
    }
    archivo.close();
    cout << "Las frases se han guardado en el archivo 'frases.txt'." << endl;
}

void mostrarFrases() {
    ifstream archivo("frases.txt"); // Abrir el archivo en modo de lectura
    string contenido;
    string linea;
    while (getline(archivo, linea)) {
        contenido += linea + "\n";
    }
    archivo.close();
    cout << "Contenido del archivo 'frases.txt':" << endl;
    cout << contenido << endl;
}

int main() {
    guardarFrases();
    mostrarFrases();
    return 0;
}
