#include <iostream>
using namespace std;

void inputMatriz();

void silla(int **a, int fil, int col) {
    int x = -1;
    int y = -1;
    for (int i = 0; i < fil; i++) {
        int min = 1e9;
        int colu;
        int fila = i;
        for (int j = 0; j < col; j++) {
            if (min > a[i][j]) {
                min = a[i][j];
                colu = j;
            }
        }
        int flag = 1;
        for (int k = 0; k < fil; k++) {
            if (a[k][colu] > min) {
                flag = 0;
            }
        }
        if (flag == 1) {
            x = fila;
            y = colu;
            cout << "Punto de Silla en: matriz[" << x << "][" << y << "] = " << a[x][y] << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    int fil = 2;
    int col = 2;
    int **a = new int *[fil];
    for (int i = 0; i < fil; i++) {
        a[i] = new int[col];
    }
    //predefinida
    a[0][0] = 5;
    a[0][1] = 4;
    a[1][0] = 0;
    a[1][1] = 0;
    silla(a, 2, 2);

    int opcion = 0;
    cout << "Menu" << endl;
    cout << "1. Introducir Matriz (imprime punto de silla al final)" << endl;
    cout << "2. Salir" << endl;
    cout << "Ingrese una Opción: ";
    while (opcion != 2) {
        cin >> opcion;
        switch (opcion) {
            case 1:
                inputMatriz();
                break;
            default:
                break;
        }
        if (opcion == 1) {
            cout << "Ingrese una nueva Opción: ";
        }
    }
    return 0;
}

void inputMatriz() {
    int fila, columna;
    cout << "Ingrese la fila y columna de su matriz: ";
    cin >> fila >> columna;
    int **a = new int *[fila];
    for (int i = 0; i < fila; i++) {
        a[i] = new int[columna];
    }
    cout << "Ingrese los valores separados por un espacio\n" << endl;
    for (size_t i = 0; i < fila; i++) {
        for (size_t j = 0; j < columna; j++) {
            cin >> a[i][j];
        }
    }
    silla(a, fila, columna);
}
