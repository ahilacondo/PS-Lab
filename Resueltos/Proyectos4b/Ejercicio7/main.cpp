#include <iostream>
using namespace std;

struct Ejemplo {
    static int contador; // Miembro estático, compartido por todas las instancias
    int id;

    Ejemplo() {
        contador++;
        id = contador;
    }

    void mostrar() {
        cout << "ID: " << id << endl;
    }

    static void mostrarContador() {
        cout << "Contador: " << contador << endl;
    }
};

int Ejemplo::contador = 0;

int main() {
    Ejemplo e1;
    Ejemplo e2;
    Ejemplo e3;

    e1.mostrar(); 
    e2.mostrar(); 
    e3.mostrar(); 

    Ejemplo::mostrarContador(); 

    return 0;
}
