#include <iostream>
using namespace std;

// Función declarada para que el main conozca su existencia
void Programa();

int main() {
    try {
        // Llamada a la función que contiene el código con posibles excepciones
        Programa();
    }
    catch(int x) {
        // Captura la excepción relanzada desde la función Programa()
        cout << "Excepción relanzada capturada." << endl;
        cout << "Error: " << x << endl;
    }
    catch(...) {
        // Captura cualquier otra excepción no manejada explícitamente
        cout << "Excepción inesperada." << endl;
    }

    cin.get();
    return 0;
}

void Programa() {
    try {
        // Aquí ocurren las operaciones que pueden lanzar excepciones
        throw 10; // Lanza una excepción de tipo int
    }
    catch(int x) {
        // Captura la excepción y la relanza para que sea manejada en el main()
        throw; // Relanza la excepción hacia el bloque try-catch del main()
    }
}
