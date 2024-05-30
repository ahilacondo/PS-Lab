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

void ClientesEnEstadoMoroso(const Cliente*, int);
void ClientesEnEstadoPagadoFacturaSuperiorCantidad(const Cliente*, int, float);
int generarNumeroAleatorio(int, int);
string generarEstadoAleatorio();

int main() {
    srand(time(0));
    int numClientes = generarNumeroAleatorio(3, 8);
    Cliente* clientes = new Cliente[numClientes];

    // Generar automáticamente los clientes
    for (int i = 0; i < numClientes; i++) {
        clientes[i].nombre = "Cliente " + to_string(i + 1);
        clientes[i].pedido.unidadesSolicitadas = generarNumeroAleatorio(10, 20);
        clientes[i].pedido.precioUnidad = generarNumeroAleatorio(1, 10);
        clientes[i].pedido.precioTotal = clientes[i].pedido.unidadesSolicitadas * clientes[i].pedido.precioUnidad;
        clientes[i].estado = generarEstadoAleatorio();
    }

    cout << "Facturación de clientes:" << endl;
    ClientesEnEstadoMoroso(clientes, numClientes);

    int cantidad = generarNumeroAleatorio(50, 100);
    ClientesEnEstadoPagadoFacturaSuperiorCantidad(clientes, numClientes, cantidad);

    delete[] clientes; // Liberar la memoria asignada
    return 0;
}

// FUNCIONES DE LISTADO, EJERCICIO 3
void ClientesEnEstadoMoroso(const Cliente* clientes, int numClientes) {
    cout << "Clientes en estado moroso:" << endl;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].estado == "Moroso") {
            cout << clientes[i].nombre << endl;
        }
    }
    cout << endl;
}

void ClientesEnEstadoPagadoFacturaSuperiorCantidad(const Cliente* clientes, int numClientes, float cantidad) {
    cout << "Clientes en estado pagado con factura mayor a $" << cantidad << ":" << endl;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].estado == "Pagado" && clientes[i].pedido.precioTotal > cantidad) {
            cout << clientes[i].nombre << endl;
            cout << "Factura total: " << clientes[i].pedido.precioTotal << endl << endl;
        }
    }
    cout << endl;
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
