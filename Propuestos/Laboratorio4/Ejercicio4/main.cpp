#include <iostream>
using namespace std;

struct EquipoFutbol {
    string nombre;
    int nVictorias, nDerrotas, nEmpates;
    int golesFavor;
    string goleador;
    int nGolesGoleador;
};

struct EquipoBasquet {
    string nombre;
    int nVictorias, nDerrotas, perdidaBalon, reboteRecogido;
    string mejorAnotador;
    int tripletesAnotador;
};

EquipoFutbol ingresarDatosFutbol() {
    EquipoFutbol temp;
    cout << "Ingrese Nombre del Equipo de Futbol: ";
    getline(cin, temp.nombre);
    cout << "Ingrese numero de victorias: ";
    cin >> temp.nVictorias;
    cout << "Ingrese numero de derrotas: ";
    cin >> temp.nDerrotas;
    cout << "Ingrese numero de empates: ";
    cin >> temp.nEmpates;
    cout << "Ingrese numero de goles a favor: ";
    cin >> temp.golesFavor;
    cin.ignore();
    cout << "Ingrese nombre del goleador: ";
    getline(cin, temp.goleador);
    cout << "Ingrese numero de goles del goleador: ";
    cin >> temp.nGolesGoleador;
    cin.ignore();
    return temp;
}

EquipoBasquet ingresarDatosBasquet() {
    EquipoBasquet temp;
    cout << "Ingrese Nombre del Equipo de Basquet: ";
    getline(cin, temp.nombre);
    cout << "Ingrese numero de victorias: ";
    cin >> temp.nVictorias;
    cout << "Ingrese numero de derrotas: ";
    cin >> temp.nDerrotas;
    cout << "Ingrese numero balones perdidos: ";
    cin >> temp.perdidaBalon;
    cout << "Ingrese numero de rebotes recogidos: ";
    cin >> temp.reboteRecogido;
    cin.ignore();
    cout << "Ingrese nombre del mejor anotador de triples: ";
    getline(cin, temp.mejorAnotador);
    cout << "Ingrese numero de triples del mejor anotador: ";
    cin >> temp.tripletesAnotador;
    cin.ignore();
    return temp;
}

int main() {
    EquipoFutbol* listaFutbol = new EquipoFutbol[16];
    EquipoBasquet* listaBasquet = new EquipoBasquet[16];
    int i = 0, j = 0;
    int opcion = 0;
    
    while (opcion != 3) {
        cout << "----Menu Ingreso de Equipos de Arequipa----" << endl;
        cout << "1. Registrar Equipo de Futbol " << endl;
        cout << "2. Registrar Equipo de Basquet " << endl;
        cout << "3. Salir " << endl;
        cout << "Escoja una opcion: ";
        cin >> opcion;
        cin.ignore();
        
        if (opcion == 1) {
            if (i == 16) {
                cout << "No es posible añadir mas equipos de Futbol!!!" << endl;
                continue;
            }
            listaFutbol[i] = ingresarDatosFutbol();
            i++;
        } else if (opcion == 2) {
            if (j == 16) {
                cout << "No es posible añadir mas equipos de Basquet!!!" << endl;
                continue;
            }
            listaBasquet[j] = ingresarDatosBasquet();
            j++;
        }
    }

    delete[] listaFutbol; // Liberar la memoria asignada
    delete[] listaBasquet; // Liberar la memoria asignada

    return 0;
}
