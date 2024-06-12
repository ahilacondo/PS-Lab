#include <iostream>
using namespace std;

struct Persona {
    char nombre[60];
    char apellido[60];
    int edad;
};

void imprimirDatos(Persona p) {
    cout << p.nombre << ", " << p.apellido << ", " << p.edad << "\n";
}

int main() {
    Persona p;
    cout << "Ingrese el nombre de la persona: ";
    cin >> p.nombre;
    cout << "Ingrese el apellido de la persona: ";
    cin >> p.apellido;
    cout << "Ingrese la edad de la persona: ";
    cin >> p.edad;
    imprimirDatos(p);
    return 0;
}
