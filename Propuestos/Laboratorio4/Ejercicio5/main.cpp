#include <iostream>
#include <string>

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

void menu() {
    cout << "----Menu Ingreso de Equipos de Arequipa----" << endl;
    cout << "1. Registrar Equipo de Futbol " << endl;
    cout << "2. Registrar Equipo de Basquet " << endl;
    cout << "3. Listado de Mejores Anotadores (Basquet) " << endl;
    cout << "4. Maximo goleador de la liga de futbol " << endl;
    cout << "5. Equipo Ganador de la liga de Futbol " << endl;
    cout << "6. Equipo Ganador de la liga de Basquet " << endl;
    cout << "7. Salir " << endl;
}

void mostrarListaMejoresAnotadores(EquipoBasquet* lista, int j) {
    cout << "\n-----Mejores Anotadores de la liga de Basquet----" << endl;
    for (int k = 0; k < j; k++) {
        cout << k + 1 << ".\t" << lista[k].mejorAnotador << endl;
    }
}

void mostrarMaximoGoleador(EquipoFutbol* lista, int i) {
    string jugador = "No hay jugadores";
    int nGoles = 0;
    for (int k = 0; k < i; k++) {
        if (lista[k].nGolesGoleador > nGoles) {
            nGoles = lista[k].nGolesGoleador;
            jugador = lista[k].goleador;
        }
    }
    cout << "Maximo Goleador de la liga de Futbol: " << jugador << endl;
}

void mostrarCampeonFutbol(EquipoFutbol* lista, int i) {
    string ganadorFutbol = "Faltan Equipos!!!!";
    int puntos = 0;
    for (int k = 0; k < i; k++) {
        int temp = lista[k].nVictorias * 3 + lista[k].nEmpates;
        if (temp > puntos) {
            puntos = temp;
            ganadorFutbol = lista[k].nombre;
        }
    }
    cout << "Campeon de la liga de Futbol: " << ganadorFutbol << endl;
}

void mostrarCampeonBasquet(EquipoBasquet* lista, int j) {
    string ganadorBasquet = "Faltan Equipos!!!!";
    int puntos = 0;
    for (int k = 0; k < j; k++) {
        int temp = lista[k].nVictorias * 3;
        if (temp > puntos) {
            puntos = temp;
            ganadorBasquet = lista[k].nombre;
        }
    }
    cout << "Campeon de la liga de Basquet: " << ganadorBasquet << endl;
}

int main() {
    EquipoFutbol* listaFutbol = new EquipoFutbol[16];
    EquipoBasquet* listaBasquet = new EquipoBasquet[16];
    int i = 0, j = 0;
    int opcion = 0;

    while (opcion != 7) {
        menu();
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
        }
        else if (opcion == 2) {
            if (j == 16) {
                cout << "No es posible añadir mas equipos de Basquet!!!" << endl;
                continue;
            }
            listaBasquet[j] = ingresarDatosBasquet();
            j++;
        }
        else if (opcion == 3) {
            mostrarListaMejoresAnotadores(listaBasquet, j);
        }
        else if (opcion == 4) {
            mostrarMaximoGoleador(listaFutbol, i);
        }
        else if (opcion == 5) {
            mostrarCampeonFutbol(listaFutbol, i);
        }
        else if (opcion == 6) {
            mostrarCampeonBasquet(listaBasquet, j);
        }
    }

    delete[] listaFutbol; // Liberar la memoria asignada
    delete[] listaBasquet; // Liberar la memoria asignada

    return 0;
}


