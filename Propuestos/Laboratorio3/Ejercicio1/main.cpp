#include <iostream>
#include <vector>
using namespace std;

// Función para calcular el coeficiente binomial
int calcularCoeficiente(int fila, int columna, vector<vector<int>>& coeficientes) {
    // Si el coeficiente ya está calculado, lo retornamos
    if (coeficientes[fila][columna] != -1) {
        return coeficientes[fila][columna];
    }

    // Si estamos en los bordes, el coeficiente es 1
    if (columna == 0 || columna == fila) {
        coeficientes[fila][columna] = 1;
    } else {
        // Calculamos el coeficiente sumando los coeficientes de las filas anteriores
        coeficientes[fila][columna] = calcularCoeficiente(fila - 1, columna - 1, coeficientes) +
                                       calcularCoeficiente(fila - 1, columna, coeficientes);
    }

    // Retornamos el coeficiente calculado
    return coeficientes[fila][columna];
}

// Función para imprimir el Triángulo de Pascal
void imprimirTrianguloPascal(int n) {
    // Matriz para almacenar los coeficientes calculados
    vector<vector<int>> coeficientes(n, vector<int>(n, -1));

    for (int fila = 0; fila < n; fila++) {
        // Imprimimos espacios en blanco para dar forma de triángulo
        for (int espacio = 0; espacio < n - fila - 1; espacio++) {
            cout << " ";
        }
        
        // Imprimimos los coeficientes para cada fila
        for (int columna = 0; columna <= fila; columna++) {
            int coeficiente = calcularCoeficiente(fila, columna, coeficientes);
            cout << coeficiente << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el número de filas del Triángulo de Pascal: ";
    cin >> n;
    imprimirTrianguloPascal(n);
    return 0;
}

