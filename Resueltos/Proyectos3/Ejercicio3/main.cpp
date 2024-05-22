#include <bits/stdc++.h>
using namespace std;

void cuadrado2(int *n) {
    cout << "Dirección de n2 en cuadrado2(): " << n << "\n";
    *n *= *n;
}

void datos() {
    int n2 = 8;
    cout << "Dirección de n2 en la función principal: " << &n2 << "\n";
    cuadrado2(&n2);
    cout << "Cuadrado de n2: " << n2 << "\n";
    cout << "Cambio visto en n2: " << n2 << "\n";
}

int main() {
    datos();
    return 0;
}
