#include <bits/stdc++.h>
using namespace std;

void puntero() {
    // declaramos el arreglo
    int v[3] = {10, 100, 200};
    
    // declaramos una variable puntero
    int *ptr;
    
    // asignamos la dirección de v[0] para ptr
    ptr = v;
    
    for (int i = 0; i < 3; i++) {
        cout << "Valor para ptr = " << ptr << "\n";
        cout << "Valor para *ptr = " << *ptr << "\n";
        // incrementando el puntero a 1
        ptr++;
    }
}

int main() {
    puntero();
    return 0;
}
