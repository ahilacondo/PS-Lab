#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

int f1, f2, c1, c2;

void productMatrix(int** m1, int** m2) {
    int result;
    cout << "El resultado del producto entre ambas matrices es:\n";
    for (int i=0; i<f1; i++) {
        for (int j=0; j<c2; j++) {
            result = 0;
            for (int k=0; k<f2; k++) {
                result += *(*(m1 + i) + k) * *(*(m2 + k) + j);
            }
            cout << "\t" << result;
        }
        cout << "\n";
    }
}

bool esPosible() {
    if (c1 == f2)
        return true;
    return false;
}

int** randomGeneration(int f, int c) {
    int** matrix = new int*[f];
    for (int i=0; i<f; i++) {
        *(matrix + i) = new int[c];
    }
    for (int i=0; i<f; i++) {
        for (int j=0; j<c; j++) {
            *(*(matrix + i) + j) = rand()%50;
        }
    }
    return matrix;
}

void delMatrix(int** m1, int** m2) {
    for (int i=0; i<f1; i++) {
        delete [] *(m1 + i);
    }
    for (int i=0; i<f2; i++) {
        delete [] *(m2 + i);
    }
    delete [] m1;
    delete [] m2;
}

void showMatrix(int** matrix, int f, int c) {
    for (int i=0; i<f; i++) {
        for (int j=0; j<c; j++) {
            cout << "\t" << *(*(matrix + i) + j);
        }
        cout << "\n";
    }
}

int main() {
    cout << " -- Multiplicacion de matrices (generadas aleatoriamente) -- \n" << endl;
    cout << "Datos de la 1ra matriz\n";
    cout << " -> Filas: "; cin >> f1;
    cout << " -> Columnas: "; cin >> c1;
    cout << "Datos de la 2da matriz\n";
    cout << " -> Filas: "; cin >> f2;
    cout << " -> Columnas: "; cin >> c2;
    
    srand(time(0));
    int** m1 = randomGeneration(f1, c1);
    srand(time(0)+1);
    int** m2 = randomGeneration(f2, c2);
    
    cout << "Matriz 1:\n";
    showMatrix(m1, f1, c1);
    cout << "Matriz 2:\n";
    showMatrix(m2, f2, c2);
    
    if (esPosible())
        productMatrix(m1, m2);
    else
        cout << "La multiplicacion no es posible";
    
    delMatrix(m1, m2);
    return 0;
}
