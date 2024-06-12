#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

void calcularRaiz(double a, double b, double c) {
    if (a == 0) {
        throw invalid_argument("El coeficiente 'a' no puede ser cero");
    }
    
    double discriminante = b*b - 4*a*c;
    
    if (discriminante < 0) {
        throw domain_error("La ecuación no tiene raíces reales");
    }
    
    cout << "Soluciones:" << endl;
    double raiz1 = (-b + sqrt(discriminante)) / (2 * a);
    
    if (discriminante == 0) {
        cout << "Raíz única: " << raiz1 << endl;
    } else {
        double raiz2 = (-b - sqrt(discriminante)) / (2 * a);
        cout << "Raíz 1: " << raiz1 << endl;
        cout << "Raíz 2: " << raiz2 << endl;
    }
}

int main() {
    double a, b, c;
    
    cout << "Ingrese el coeficiente cuadrático (a) de la ecuación: ";
    cin >> a;
    cout << "Ingrese el coeficiente lineal (b) de la ecuación: ";
    cin >> b;
    cout << "Ingrese el término independiente (c) de la ecuación: ";
    cin >> c;
    
    try {
        calcularRaiz(a, b, c);
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const domain_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
