#include <bits/stdc++.h>
using namespace std;

void declararPuntero() {
    // declaramos un arreglo
    int val[3] = { 5, 10, 20 };
    
    // declaramos una variable puntero
    int *ptr;
    
    // Asignamos la dirección del valor de val[0] a ptr
    // podemos usar ptr = &val[0]; (ambos son lo mismo)
    ptr = val;
    
    cout << "Elementos del arreglo son: ";
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << "\n";
}

int main() {
    declararPuntero();
    return 0;
}
