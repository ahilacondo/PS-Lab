#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;

struct Persona {
    string nombre;
    // Almacena la fecha de nacimiento
    int dia;
    int mes;
    int año;
};

Persona generarPersona(int);
void mostrarPersona(Persona);

int main() {
    srand(time(NULL));
    int n;
    cout << "- Ingrese el número de personas que desea generar: ";
    cin >> n;
    Persona p[n]; // Arreglo de Estructuras Persona
    int ncumple[12] = {0}; // Almacena el número de cumpleaños en cada mes

    while (n) {
        p[n - 1] = generarPersona(n); // Genera una persona con índice n
        ncumple[p[n - 1].mes - 1]++; // Suma la cantidad según su mes de nacimiento
        mostrarPersona(p[n - 1]); // Muestra los datos de la persona generada
        n--;
    }

    int mes; // Almacena el valor del mes que se desea verificar
    while (true) {
        cout << "- Ingrese el mes que desea verificar: ";
        cin >> mes;
        if (mes == 0) { // Si es cero, se termina la ejecución
            break;
        }
        if (mes < 0 || mes > 12) { // Valida que se ingrese un mes entre 1 y 12
            cout << "---> Mes inválido" << endl;
            continue;
        }
        cout << "---> " << ncumple[mes - 1] << " personas cumplen en el mes " << mes << endl;
        getch();
    }
    cout << "PROCESO FINALIZADO";
    return 0;
}

Persona generarPersona(int n) {
    // Genera una nueva persona en base al índice n
    Persona p;
    p.nombre = "Pers" + to_string(n);
    // Genera valores aleatorios para su fecha de nacimiento
    p.dia = 1 + rand() % 28; // Día aleatorio entre 1 y 28
    p.mes = 1 + rand() % 12; // Mes aleatorio entre 1 y 12
    p.año = 1960 + rand() % (2012 - 1960 + 1); // Año aleatorio entre 1960 y 2012
    return p;
}

void mostrarPersona(Persona p) {
    // Muestra los datos de la persona almacenados
    cout << "---> " << p.nombre << " - ";
    if (p.dia < 10) { // Verifica el formato de dos dígitos al día
        cout << "0" << p.dia << " / ";
    } else {
        cout << p.dia << " / ";
    }
    if (p.mes < 10) { // Verifica el formato de dos dígitos al mes
        cout << "0" << p.mes << " / " << p.año << endl;
    } else {
        cout << p.mes << " / " << p.año << endl;
    }
}
