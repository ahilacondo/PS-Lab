#include <iostream>
using namespace std;

// Función que puede lanzar excepciones
void checkValues(int *pointer, int value) {
    if (pointer == nullptr) {
        throw pointer; // Lanzar una excepción si el puntero es nulo
    }
    if (value == 0) {
        throw value; // Lanzar una excepción si el valor es cero
    }
    // Aquí se podría añadir alguna otra funcionalidad
}

int main() {
    try {
        checkValues(nullptr, 0); // Llamar a la función con argumentos que lanzarán excepciones
    } catch (...) {
        cout << "Excepción capturada en el bloque try-catch" << endl;
    }
    return 0;
}

