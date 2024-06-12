#include <iostream>
using namespace std;

struct Registro {
    int valor = 7; // Inicializa 'valor' con 7
};

// Función principal del programa
int main() {
    Registro reg; // Crea una instancia de la estructura Registro
    cout << reg.valor << endl; // Muestra el valor de 'valor'
    return 0;
}
