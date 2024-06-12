#include <iostream>
using namespace std;

struct Persona {
    string nombre;
    int edad;

    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    Persona p1("Juan", 30);
    Persona p2("Ana", 25);

    p1.mostrar();
    p2.mostrar();

    return 0;
}
