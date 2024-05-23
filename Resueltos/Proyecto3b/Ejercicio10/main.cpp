#include <iostream>
using namespace std;

int main() {
    int *valorEntero = new int;

    cout << "Ingrese un valor entero: ";
    cin >> *valorEntero;

    cout << "El valor ingresado es: " << *valorEntero << endl;

    delete (valorEntero);

    return 0;
}
