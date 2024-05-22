#include <bits/stdc++.h>
using namespace std;

// pasando por valor
int cuadrado1(int n) {
    cout << "Dirección de n en cuadrado1(): " << &n << "\n";
    n *= n;
    return n;
}

void datos() {
    int n1 = 8;
    cout << "Dirección de n1 en main(): " << &n1 << "\n";
    cout << "Cuadrado de n1: " << cuadrado1(n1) << "\n";
    cout << "Sin cambio en n1: " << n1 << "\n";
}

int main() {
    datos();
    return 0;
}
