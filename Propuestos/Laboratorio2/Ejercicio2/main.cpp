#include <iostream>
using namespace std;

double AreaCuadrilateros(double lado_a, double lado_b) {
    if (lado_a <= 0 || lado_b <= 0) return 0.0;
    return lado_a * lado_b;
}

double AreaTriangulos(double base, double altura) {
    if (base <= 0 || altura <= 0) return 0.0;
    return (base * altura) / 2;
}

int main() {
    double a, b;
    int figura;
    
    cout << "Qué figura desea analizar?\n1. Cuadrado\n2. Rectángulo\n3. Triángulo\n";
    cin >> figura;
    
    switch (figura) {
        case 1:
            cout << "Introduzca el lado: ";
            cin >> a;
            if (AreaCuadrilateros(a, a) == 0) {
                cout << "Ojo, el área es negativa\n";
            } else {
                cout << "El área del cuadrado es: " << AreaCuadrilateros(a, a) << endl;
            }
            break;
        case 2:
            cout << "Introduzca los lados a y b: ";
            cin >> a >> b;
            if (AreaCuadrilateros(a, b) == 0) {
                cout << "Ojo, el área es negativa\n";
            } else {
                cout << "El área del rectángulo es: " << AreaCuadrilateros(a, b) << endl;
            }
            break;
        case 3:
            cout << "Introduzca la base y la altura: ";
            cin >> a >> b;
            if (AreaTriangulos(a, b) == 0) {
                cout << "Ojo, el área es negativa\n";
            } else {
                cout << "El área del triángulo es: " << AreaTriangulos(a, b) << endl;
            }
            break;
        default:
            cout << "Figura equivocada\n";
            break;
    }
    
    return 0;
}
