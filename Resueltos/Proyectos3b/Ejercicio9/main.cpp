#include <iostream>
using namespace std;

int main() {
    int *numeroDinamico = new int(10);

    cout << "Valor del entero dinámico: " << *numeroDinamico << endl;

    delete numeroDinamico;

    return 0;
}
