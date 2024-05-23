#include <iostream>
#include <cmath>
using namespace std;

void calcularValores(int numero, int* ptrCuadrado, double* ptrRaizCuadrada) {
    *ptrCuadrado = numero * numero;
    *ptrRaizCuadrada = sqrt(numero);
}

int main() {
    int valor = 25;
    int* resultadoCuadrado = new int;
    double* resultadoRaizCuadrada = new double;

    calcularValores(valor, resultadoCuadrado, resultadoRaizCuadrada);
    cout << "Cuadrado: " << *resultadoCuadrado << ", Raíz cuadrada: " << *resultadoRaizCuadrada << endl;

    // Liberar memoria
    delete resultadoCuadrado;
    delete resultadoRaizCuadrada;

    return 0;
}
