#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class ComputerException : public exception {
public:
    char message[100];
};

class InputException : public ComputerException {
public:
    InputException() {
        strncpy(message, "Error en la entrada de datos", 99);
    }
};

class ProcessorException : public ComputerException {
public:
    ProcessorException() {
        strncpy(message, "Error en el proceso de datos", 99);
    }
};

class OutputException : public ComputerException {
public:
    OutputException() {
        strncpy(message, "Error en la salida de datos", 99);
    }
};

int main() {
    ifstream entrada;
    try {
        entrada.open("archivo.txt");
        if (!entrada.is_open()) {
            throw InputException();
        }
        cout << "Archivo abierto" << endl;
        
        string linea;
        getline(entrada, linea);
        if (linea.empty()) {
            throw ProcessorException();
        }
        cout << "Contenido del archivo: " << linea << endl;
        
        entrada.close();
        
        ofstream salida;
        salida.open("nuevo.txt");
        if (!salida.is_open()) {
            throw OutputException();
        }
        salida << linea;
        cout << "Archivo de salida creado" << endl;
        
        salida.close();
    }
    catch (InputException& e) {
        cout << "Error: " << e.message << endl;
    }
    catch (ProcessorException& e) {
        cout << "Error: " << e.message << endl;
    }
    catch (OutputException& e) {
        cout << "Error: " << e.message << endl;
    }
    catch (...) {
        cout << "Excepción inesperada" << endl;
    }
    
    return 0;
}
