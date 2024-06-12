#include <iostream>
#include <string>
using namespace std;

struct datosPersona {
    string nombre;
    string direccion;
    string telefono;
    int edad;
};

int mostrarMenu() {
    int opcion;
    cout << "------- MENU ---------" << endl;
    cout << "1. Mostrar la lista de todos los nombres" << endl;
    cout << "2. Mostrar las personas de una cierta edad" << endl;
    cout << "3. Mostrar las personas cuya inicial sea la que el usuario indique" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    return opcion;
}

int main() {
    datosPersona persona[50];
    int contador = 0;
    string nombre;

    // Pidiendo los datos de las personas
    cout << "Ingrese los datos de las personas. Deje el nombre en blanco para terminar." << endl;
    while (contador < 50) {
        cout << "Ingrese el nombre de la persona (deje en blanco para salir): ";
        getline(cin, nombre);
        if (nombre.empty()) {
            break;
        }
        persona[contador].nombre = nombre;
        cout << "Ingrese la dirección: ";
        getline(cin, persona[contador].direccion);
        cout << "Ingrese el teléfono: ";
        getline(cin, persona[contador].telefono);
        cout << "Ingrese la edad: ";
        cin >> persona[contador].edad;
        cin.ignore(); // Ignorar el carácter de nueva línea después de la lectura de la edad
        contador++;
    }

    int opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                // Mostrar la lista de todos los nombres
                cout << "Lista de los nombres de las personas que se introdujeron: \n";
                for (int i = 0; i < contador; i++) {
                    cout << "\t" << persona[i].nombre << "\n";
                }
                break;
            case 2: {
                // Mostrar las personas de una cierta edad
                int edadBuscar;
                cout << "Ingrese la edad a buscar: ";
                cin >> edadBuscar;
                for (int i = 0; i < contador; i++) {
                    if (persona[i].edad == edadBuscar) {
                        cout << persona[i].nombre << " tiene " << persona[i].edad << " años\n";
                    }
                }
                break;
            }
            case 3: {
                // Mostrar las personas cuya inicial sea la que el usuario indique
                char inicial;
                cout << "Ingrese la inicial: ";
                cin >> inicial;
                inicial = tolower(inicial);
                for (int i = 0; i < contador; i++) {
                    char iniBusc = tolower(persona[i].nombre[0]);
                    if (iniBusc == inicial) {
                        cout << "- " << persona[i].nombre << endl;
                    }
                }
                break;
            }
            case 4:
                // Salir del programa
                cout << "Fin del programa" << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 4);

    return 0;
}

