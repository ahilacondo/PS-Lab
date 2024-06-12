#include <iostream>
using namespace std;

int* crearArreglo(int tamano) {
    return new int[tamano];
}

int main() {
    int* punteroArreglo = crearArreglo(10);
    
    cout << "Dirección de memoria del arreglo: " << punteroArreglo << endl;
    
    cout << "Valor del primer elemento (no inicializado): " << *punteroArreglo << endl;
    
    delete[] punteroArreglo;

    return 0;
}
