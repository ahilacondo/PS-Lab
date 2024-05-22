#include <bits/stdc++.h>
using namespace std;

void mostrar() {
    int var = 20;
    int *puntero;  
    puntero = &var;  

    cout << "Valor para ptr = " << puntero << "\n";
    cout << "Valor para var = " << var << "\n";
    cout << "Valor para *ptr = " << *puntero << "\n";
}

int main() {
    mostrar();
    return 0;
}
