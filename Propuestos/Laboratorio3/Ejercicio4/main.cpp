#include <iostream>
#include <string>

using namespace std;

class Resident {
private:
    string nombre;
public:
    Resident(const string& nombre) : nombre(nombre) {}
    string obtenerNombre() const {
        return nombre;
    }
};

class Apartamento {
private:
    Resident* residente;
public:
    Apartamento() : residente(nullptr) {}
    void asignarResidente(Resident* nuevoResidente) {
        residente = nuevoResidente;
    }
    bool estaOcupado() const {
        return residente != nullptr;
    }
    Resident* obtenerResidente() const {
        return residente;
    }
};

class Piso {
private:
    Apartamento apartamentos[6];
public:
    Apartamento* obtenerApartamento(int indice) {
        if (indice >= 0 && indice < 6) {
            return &apartamentos[indice];
        }
        return nullptr;
    }
    int obtenerCantidadResidentes() const {
        int cantidad = 0;
        for (const auto& apt : apartamentos) {
            if (apt.estaOcupado()) {
                cantidad++;
            }
        }
        return cantidad;
    }
};

class Edificio {
private:
    Piso pisos[20];
public:
    Piso* obtenerPiso(int indice) {
        if (indice >= 0 && indice < 20) {
            return &pisos[indice];
        }
        return nullptr;
    }
};

class ComplejoResidencial {
private:
    Edificio edificios[7];
public:
    Edificio* obtenerEdificio(int indice) {
        if (indice >= 0 && indice < 7) {
            return &edificios[indice];
        }
        return nullptr;
    }
    Apartamento* obtenerApartamento(int indiceEdificio, int indicePiso, int indiceApartamento) {
        Edificio* edificioPtr = obtenerEdificio(indiceEdificio);
        if (edificioPtr != nullptr) {
            Piso* pisoPtr = edificioPtr->obtenerPiso(indicePiso);
            if (pisoPtr != nullptr) {
                return pisoPtr->obtenerApartamento(indiceApartamento);
            }
        }
        return nullptr;
    }
};

int mostrarMenu() {
    int opcion;
    cout << "------- MENÚ ---------" << endl;
    cout << "1. Asignar residente a un apartamento" << endl;
    cout << "2. Mostrar cantidad de residentes por edificio" << endl;
    cout << "3. Mostrar cantidad de residentes por piso de un edificio" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    cin.ignore(); // Limpiar el buffer de entrada
    return opcion;
}

void asignarResidente(ComplejoResidencial& complejo) {
    int e, p, a, edificio, piso, apartamento;
    string nombre;
    cout << "Ingrese el número de edificio (1-7): ";
    cin >> e;
    cin.ignore(); // Limpiar el buffer de entrada
    edificio = e - 1;
    cout << "Ingrese el número de piso (1-20): ";
    cin >> p;
    cin.ignore(); // Limpiar el buffer de entrada
    piso = p - 1;
    cout << "Ingrese el número de apartamento (1-6): ";
    cin >> a;
    cin.ignore(); // Limpiar el buffer de entrada
    apartamento = a - 1;
    cout << "Ingrese el nombre del residente: ";
    getline(cin, nombre); // Usar getline para leer toda la línea incluyendo espacios
    Resident* residente = new Resident(nombre);
    Apartamento* apartamentoPtr = complejo.obtenerApartamento(edificio, piso, apartamento);
    if (apartamentoPtr != nullptr) {
        apartamentoPtr->asignarResidente(residente);
        cout << "Residente asignado correctamente." << endl;
    } else {
        cout << "Apartamento inválido." << endl;
    }
}

void mostrarCantidadResidentesPorEdificio(ComplejoResidencial& complejo) {
    for (int e = 0; e < 7; e++) {
        Edificio* edificioPtr = complejo.obtenerEdificio(e);
        if (edificioPtr != nullptr) {
            int totalResidentes = 0;
            for (int p = 0; p < 20; p++) {
                Piso* pisoPtr = edificioPtr->obtenerPiso(p);
                if (pisoPtr != nullptr) {
                    totalResidentes += pisoPtr->obtenerCantidadResidentes();
                }
            }
            cout << "Total de residentes en el edificio " << e + 1 << ": " << totalResidentes << endl;
        }
    }
}

void mostrarCantidadResidentesPorPisoEnEdificio(ComplejoResidencial& complejo) {
    int e, edificio;
    cout << "Ingrese el número de edificio (1-7): ";
    cin >> e;
    cin.ignore(); // Limpiar el buffer de entrada
    edificio = e - 1;

    Edificio* edificioPtr = complejo.obtenerEdificio(edificio);
    if (edificioPtr != nullptr) {
        for (int p = 0; p < 20; p++) {
            Piso* pisoPtr = edificioPtr->obtenerPiso(p);
            if (pisoPtr != nullptr) {
                int residentesEnPiso = pisoPtr->obtenerCantidadResidentes();
                cout << "Total de residentes en el piso " << p + 1 << " del edificio " << e << ": " << residentesEnPiso << endl;
            }
        }
    } else {
        cout << "Edificio inválido." << endl;
    }
}

int main() {
    ComplejoResidencial complejo;
    int opcion;

    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                asignarResidente(complejo);
                break;
            case 2:
                mostrarCantidadResidentesPorEdificio(complejo);
                break;
            case 3:
                mostrarCantidadResidentesPorPisoEnEdificio(complejo);
                break;
            case 4:
                cout << "Programa terminado." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 4);

    return 0;
}



