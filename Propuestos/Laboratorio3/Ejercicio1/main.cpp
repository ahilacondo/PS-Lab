#include <iostream>
#include <string>
using namespace std;

void genPascal(string*, int);
void mostrar(string*, int);
void imprimirEspacios(int);

int main() {
    cout << "Ingrese el número de filas que desea mostrar: ";
    int size;
    cin >> size;
    string *arreglo = new string[size];
    genPascal(arreglo, size);
    mostrar(arreglo, size);
    delete[] arreglo;
    return 0;
}

void genPascal(string *arreglo, int size) {
    for (int i = 0; i < size; i++) {
        int c = 1;
        string fila = "";
        for (int j = 0; j <= i; j++) {
            fila += to_string(c) + " ";
            c = c * (i - j) / (j + 1);
        }
        arreglo[i] = fila;
    }
}

void mostrar(string *arreglo, int size) {
    int max_length = arreglo[size - 1].length();
    for (int i = 0; i < size; i++) {
        int num_spaces = (max_length - arreglo[i].length()) / 2;
        imprimirEspacios(num_spaces);
        cout << arreglo[i];
        imprimirEspacios(num_spaces);
        cout << endl;
    }
}

void imprimirEspacios(int num) {
    for (int i = 0; i < num; i++) {
        cout << " ";
    }
}

