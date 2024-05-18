#include <iostream>
using namespace std;

double Suma(double x, double y); // Declaración de la función Suma
double Producto(double x, double y); // Declaración de la función Producto
void mostrarMenu(double &a, double &b, int &c); // Declaración de la función mostrarMenu

int main(void) {
    double a, b;
    int c;
    mostrarMenu(a, b, c);
    
    switch (c) {
        case 1:
            cout << "El resultado de la suma es: " << Suma(a, b) << endl;
            break;
        case 2:
            cout << "El resultado del producto es: " << Producto(a, b) << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
    }
    
    return 0;
}

double Suma(double x, double y) { // Definición de la función Suma
    double z = x + y;
    return z;
}

double Producto(double x, double y) { // Definición de la función Producto
    double z = x * y;
    return z;
}

void mostrarMenu(double &a, double &b, int &c) { // Definición de la función mostrarMenu
    cout << "Escribe un número:" << endl;
    cin >> a;
    cout << "Escribe otro número:" << endl;
    cin >> b;
    cout << "¿Qué operación desea hacer?" << endl;
    cout << " 1. Suma" << endl;
    cout << " 2. Producto" << endl;
    cin >> c;
}
