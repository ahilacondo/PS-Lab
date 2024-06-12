#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

double realizarDivision(double dividendo, double divisor) {
    if (divisor == 0) {
        throw runtime_error("Error: ¡No se puede dividir entre cero!");
    }
    return dividendo / divisor;
}

int main() {
    double dividendo, divisor;

    cout << "Ingrese el dividendo: ";
    cin >> dividendo;

    cout << "Ingrese el divisor: ";
    cin >> divisor;

    try {
        double resultado = realizarDivision(dividendo, divisor);
        cout << "El resultado de la división es: " << resultado << endl;
    } catch (const runtime_error& error) {
        cout << error.what() << endl;
    }

    return 0;
}
