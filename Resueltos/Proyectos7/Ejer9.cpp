#include <iostream>
using namespace std;

int main() {
    int* ptr;
    int size = 50000000; // Usar un tamaño de array grande para ilustrar el uso de memoria dinámica

    try {
        ptr = new int[size]; // Intentar asignar memoria para el array
        ptr[0] = 42; // Asignar un valor al primer elemento
        cout << "Dirección del puntero: " << static_cast<void*>(ptr) << endl;
        delete[] ptr; // Liberar la memoria asignada
    }
    catch (const std::bad_alloc&) { // Capturar excepciones de asignación de memoria
        cout << "Error: No se pudo asignar suficiente memoria" << endl;
    }

    return 0;
}
