#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int** definirMatriz(int*);
void transponerMatriz(int**, int);
void analizarSimetria(int**, int);
void analizarTriangular(int**, int);
void mostrarMatriz(int**, int);

int main() {
    int opc = 1;
    int dim, **matriz; //dim: Dimension
    matriz = definirMatriz(&dim); //&dim para que cambie el valor de dim
    mostrarMatriz(matriz, dim);
    cout << "---> ¡Matriz Generada!" << endl;
    while (opc != 0) {
        getch();
        //Opciones del menu
        cout << endl << "\t --- MENU DE OPCIONES ---" << endl;
        cout << "0: Finalizar ejecución" << endl;
        cout << "1: Transponer la matriz" << endl;
        cout << "2: Indicar si es simetrica o antisimetrica" << endl;
        cout << "3: Indicar si es triangular superior o inferior" << endl;
        cout << "- Ingrese la función de desea utilizar: ";
        cin >> opc;
        cout << endl;
        switch (opc) { //Verifica la opcion seleccionada
            case 0:
                cout << "---> ¡Ejecución finalizada!";
                break;
            case 1:
                transponerMatriz(matriz, dim);
                mostrarMatriz(matriz, dim);
                cout << "---> ¡Matriz Transpuesta!" << endl;
                break;
            case 2:
                analizarSimetria(matriz, dim);
                break;
            case 3:
                analizarTriangular(matriz, dim);
                break;
            default: //En caso se ingrese un valor incorrecto
                cout << "---> ¡Ingrese una opción válida!" << endl;
                break;
        }
    }
    //El bucle se rompe solo cuando se ingresa 0
    return 0;
}

int** definirMatriz(int* dim) {
    // Define la matriz, y la dimension
    cout << "Definiendo la matriz " << endl;
    cout << "- Ingrese la dimension de la matriz: ";
    cin >> *dim;
    cout << "- Desea generar valores aleatorios (y:yes): ";
    string conf;
    cin >> conf;
    int** matriz = new int*[*dim];
    if (conf == "y") { // Da la opcion de generar una matriz con valores aleatorios
        cout << "---> Generando valores aleatorios" << endl;
        srand(time(0));
        for (int i = 0; i < *dim; i++) {
            *(matriz + i) = new int[*dim];
            for (int j = 0; j < *dim; j++) {
                *(*(matriz + i) + j) = rand() % 100;
            }
        }
    } else { // Opcion para ingresar los valores manualmente
        cout << "---> Ingresando valores manualmente" << endl;
        for (int f = 0; f < *dim; f++) {
            matriz[f] = new int[*dim];
            for (int c = 0; c < *dim; c++) {
                cout << "- Ingrese el elemento (" << f + 1 << ", " << c + 1 << "): ";
                cin >> matriz[f][c];
            }
        }
    }
    return matriz;
}

void transponerMatriz(int** matriz, int dim) {
    int num;
    for (int f = 0; f < dim; f++) {
        for (int c = 0; c < f; c++) {
            // Intercambia los valores de posicion
            // Solo hasta la diagonal para evitar el cruce
            num = *(*(matriz + f) + c);
            *(*(matriz + f) + c) = *(*(matriz + c) + f);
            *(*(matriz + c) + f) = num;
        }
    }
}

void analizarSimetria(int** matriz, int dim) {
    bool esSimtr = true, esAntiSimtr = true;
    for (int f = 0; f < dim; f++) {
        for (int c = 0; c < f; c++) {
            if (esSimtr) { // Verifica si aun tiene la posibilidad de ser simetrica
                esSimtr = *(*(matriz + f) + c) == *(*(matriz + c) + f);
            }
            if (esAntiSimtr) {
                // Si es que ya no puede ser simetrica, aun puede ser antisimetrica
                esAntiSimtr = *(*(matriz + f) + c) == -*(*(matriz + c) + f);
            }
            if (!esAntiSimtr && !esSimtr) {
                // Si no es ninguna de las dos.
                cout << "---> No es simétrica ni antisimétrica" << endl;
                return;
            }
        }
    }
    // Da el resultado final, son excluyentes
    if (esSimtr) {
        cout << "---> Es simétrica" << endl;
    } else {
        cout << "---> Es antisimétrica" << endl;
    }
}

void analizarTriangular(int** matriz, int dim) {
    bool esTriSup = true, esTriInf = true;
    for (int f = 0; f < dim; f++) {
        for (int c = 0; c < f; c++) {
            if (esTriSup) { // Verifica si aun puede ser triangular superior
                esTriSup = *(*(matriz + f) + c) == 0;
            }
            if (esTriInf) { // Verifica si aun puede ser triangular inferior
                esTriInf = *(*(matriz + c) + f) == 0;
            }
            if (!esTriSup && !esTriInf) {
                // Si no es ninguna
                cout << "---> No es triangular inferior ni superior" << endl;
                return;
            }
        }
    }
    // Da el resultado final, no son excluyentes
    if (esTriSup) {
        cout << "---> Es triangular superior" << endl;
    }
    if (esTriInf) {
        cout << "---> Es triangular inferior" << endl;
    }
}

void mostrarMatriz(int** matriz, int dim) {
    for (int f = 0; f < dim; f++) {
        for (int c = 0; c < dim; c++) {
            cout << *(*(matriz + f) + c) << "\t";
        }
        cout << endl;
    }
}