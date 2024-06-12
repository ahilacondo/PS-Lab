#include <iostream>
#include <stdexcept>
using namespace std;

void verificarEntero(double valor) {
    if (static_cast<int>(valor) != valor) {
        throw runtime_error("No es un número entero");
    } else {
        cout << "El valor es un número entero";
    }
}

int main() {
    try {
        double numero_decimal = 3.1416;
        verificarEntero(numero_decimal);
    } catch (const runtime_error& e) {
        cout << "Se ha producido una excepción: " << e.what() << endl;
    }
    return 0;
}


