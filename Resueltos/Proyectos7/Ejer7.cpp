#include <iostream>
using namespace std;

int main() {
    try {
        // Bloque try interno
        try {
            throw 42; // Lanzar una excepción de tipo int
        } catch (int value) {
            cout << "Excepción parcialmente manejada: " << value << endl;
            throw; // Relanzar la excepción capturada
        }
    } catch (int value) {
        cout << "Excepción completamente manejada: " << value << endl;
    }
    return 0;
}
