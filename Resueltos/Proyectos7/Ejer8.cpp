#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { cout << "Demo: Constructor invocado" << endl; }
    ~Demo() { cout << "Demo: Destructor invocado" << endl; }
};

int main() {
    try {
        Demo d1; // Crear una instancia de la clase Demo
        throw 99; // Lanzar una excepción de tipo int
    } catch (int ex) {
        cout << "Excepción capturada con valor: " << ex << endl;
    }
    // El destructor de Demo se llama automáticamente al salir del bloque try
    return 0;
}
