#include <iostream>
using namespace std;

struct Calificaciones {
    int numero;

    // Método para asignar un valor a 'numero'
    void Asignar(int valor) {
        numero = valor;
    }

    // Método para mostrar el valor de 'numero'
    void Mostrar() {
        cout << "numero = " << numero << endl;
    }
};

// Función principal del programa
int main() {
    Calificaciones calif1;
    calif1.Asignar(9); // Inicializa 'numero' con 9
    calif1.Mostrar();  // Muestra el valor de 'numero'
}
