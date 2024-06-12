#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Persona {
    char nombre[16];
    char direccion[64];
    char telefono[10];
    char email[32];
    short dia, mes, anio;
};

void agregarPersona(Persona&);
void mostrarPersonas(int, Persona&);
void buscarPersona(int, Persona&);

int main() {
    ifstream archivo("prueba.dat", ios::binary);

    if (archivo.is_open()) {
        archivo.seekg(0, ios::end);
        int cantidadPersonas = archivo.tellg() / sizeof(Persona);
        archivo.close();

        int opcion = 0;
        Persona persona;
        do {
            cout << endl;
            cout << "------Menu de Agenda------" << endl;
            cout << "1. Agregar nueva persona" << endl;
            cout << "2. Mostrar lista de personas" << endl;
            cout << "3. Buscar persona por nombre" << endl;
            cout << "4. Salir" << endl;
            cout << "Elija una opción: ";
            cin >> opcion;
            cout << endl;

            if (opcion == 1 && cantidadPersonas <= 100) {
                agregarPersona(persona);
                cantidadPersonas++;
            } else if (opcion == 2) {
                mostrarPersonas(cantidadPersonas, persona);
            } else if (opcion == 3) {
                buscarPersona(cantidadPersonas, persona);
            }
        } while (opcion != 4);
    } else {
        cout << "Archivo no encontrado" << endl;
        ofstream nuevoArchivo("prueba.dat", ios::out | ios::binary);
        nuevoArchivo.close();
    }

    return 0;
}

void agregarPersona(Persona& persona) {
    ofstream archivo("prueba.dat", ios::binary | ios::app);

    cout << "Registro de nueva persona" << endl;
    cout << "Ingrese nombre: ";
    cin >> persona.nombre;
    cout << "Ingrese dirección: ";
    cin.ignore();
    cin.getline(persona.direccion, 64);
    cout << "Ingrese teléfono: ";
    cin.getline(persona.telefono, 10);
    cout << "Ingrese correo electrónico: ";
    cin >> persona.email;
    cout << "Ingrese fecha de nacimiento (día mes año): ";
    cin >> persona.dia >> persona.mes >> persona.anio;

    archivo.write(reinterpret_cast<char*>(&persona), sizeof(Persona));
    archivo.close();
}

void mostrarPersonas(int cantidadPersonas, Persona& persona) {
    ifstream archivo("prueba.dat", ios::in | ios::binary);

    cout << "--------Lista de Personas en la Agenda------" << endl;
    for (int i = 0; i < cantidadPersonas; ++i) {
        archivo.read(reinterpret_cast<char*>(&persona), sizeof(Persona));
        cout << i + 1 << ". " << persona.nombre << endl;
    }

    archivo.close();
}

void buscarPersona(int cantidadPersonas, Persona& persona) {
    ifstream archivo("prueba.dat", ios::in | ios::binary);
    string nombreBuscado;

    cout << "Ingrese el nombre de la persona: ";
    cin >> nombreBuscado;

    bool encontrado = false;
    for (int i = 0; i < cantidadPersonas; ++i) {
        archivo.read(reinterpret_cast<char*>(&persona), sizeof(Persona));
        if (strcmp(persona.nombre, nombreBuscado.c_str()) == 0) {
            cout << "-----Ficha de " << persona.nombre << " -----" << endl;
            cout << "Dirección: " << persona.direccion << endl;
            cout << "Teléfono: " << persona.telefono << endl;
            cout << "Email: " << persona.email << endl;
            cout << "Fecha de Nacimiento: " << persona.dia << "/" << persona.mes << "/" << persona.anio << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Ficha no encontrada" << endl;
    }

    archivo.close();
}
