#include <iostream>
using namespace std;

// La función 'division' divide dos números enteros y devuelve el resultado como un flotante.
// Puede lanzar una excepción de tipo 'int' si el denominador es cero.
float division(int x, int y) {
    if (y != 0) {
        return x / (y * 1.0);
    } else {
        throw y; // Se lanza una excepción si el denominador es cero.
    }
}

int main() {
    cout << "\t-- DIVISIÓN --\n";
    int opcion;
    do {
        cout << "\nMenú de opciones:\n";
        cout << " 1. Dividir números\n 2. Salir\n -> ";
        cin >> opcion;
        if (opcion == 1) {
            float numerador, denominador;
            cout << "Ingresa el numerador: ";
            cin >> numerador;
            cout << "Ingresa el denominador: ";
            cin >> denominador;
            try {
                float resultado = division(numerador, denominador);
                cout << "El resultado es: " << resultado << endl;
            } catch (...) {
                cout << "No se puede realizar la división entre 0!\n";
            }
        }
    } while (opcion != 2);
    cout << "¡Adiós!";
    return 0;
}

