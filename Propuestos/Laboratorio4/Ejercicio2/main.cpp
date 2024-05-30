#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Pedido {
    int unidadesSolicitadas;
    float precioUnidad;
    float precioTotal;
};

struct Cliente {
    string nombre;
    Pedido pedido;
    string estado;
};

int generarNumeroAleatorio(int min, int max);
string generarEstadoAleatorio();

int main() {
    srand(time(0));
    int numClientes = generarNumeroAleatorio(3, 6);
    Cliente* clientes = new Cliente[numClientes];

    // Generar automáticamente los clientes
    for (int i = 0; i < numClientes; i++) {
        clientes[i].nombre = "Cliente " + to_string(i + 1);
        clientes[i].pedido.unidadesSolicitadas = generarNumeroAleatorio(10, 20);
        clientes[i].pedido.precioUnidad = generarNumeroAleatorio(1, 10);
        clientes[i].pedido.precioTotal =
            clientes[i].pedido.unidadesSolicitadas * clientes[i].pedido.precioUnidad;
        clientes[i].estado = generarEstadoAleatorio();
    }

    // Imprimir la información de los clientes
    cout << "Facturación de clientes:" << endl;
    for (int i = 0; i < numClientes; i++) {
        cout << "Cliente " << i + 1 << ":" << endl;
        cout << "Nombre: " << clientes[i].nombre << endl;
        cout << "Unidades solicitadas: " << clientes[i].pedido.unidadesSolicitadas << endl;
        cout << "Precio por unidad: $" << clientes[i].pedido.precioUnidad << endl;
        cout << "Precio total: $" << clientes[i].pedido.precioTotal << endl;
        cout << "Estado: " << clientes[i].estado << endl;
        cout << endl;
    }

    delete[] clientes; // Liberar la memoria asignada
    return 0;
}

int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

string generarEstadoAleatorio() {
    int aleatorio = generarNumeroAleatorio(1, 3);
    if (aleatorio == 1)
        return "Moroso";
    else if (aleatorio == 2)
        return "Atrasado";
    else
        return "Pagado";
}
