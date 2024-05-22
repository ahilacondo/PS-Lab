#include <bits/stdc++.h>
using namespace std;

void cuadrado3(int &n) {
    cout << "Dirección de n3 en cuadrado3(): " << &n << "\n";
    n *= n;
}

void datos() {
    int n3 = 8;
    cout << "Dirección de n3 en la función principal: " << &n3 << "\n";
    cuadrado3(n3);
    cout << "Cuadrado de n3: " << n3 << "\n";
    cout << "Cambio reflejado en n3: " << n3 << "\n";
}

int main() {
    datos();
    return 0;
}
