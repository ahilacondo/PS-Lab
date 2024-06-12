#include <iostream>
using namespace std;

void process(int *pointer, int number) {
    if (pointer == nullptr) {
        throw pointer;
    }
    if (number == 0) {
        throw number;
    }
    // Alguna operación
}

int main() {
    try {
        process(nullptr, 0);
    } catch(...) {
        cout << "Excepción capturada en el bloque try-catch" << endl;
    }
    return 0;
}
