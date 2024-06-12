#include <iostream>
using namespace std;

void reconocer(void *dato, int tamanoDato) {
    if (tamanoDato == sizeof(char)) {
        cout << "Valor tipo char\n";
    } else if (tamanoDato == sizeof(int)) {
        cout << "Valor tipo int\n";
    }
}

void ejecutarReconocer() {
    char letra = 'x';
    int numero = 10;
    
    reconocer(&letra, sizeof(letra));
    //reconocer el tipo
    reconocer(&numero, sizeof(numero));
}

int main() {
    ejecutarReconocer();
    return 0;
}

