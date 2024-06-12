#include <iostream>
using namespace std;

int main() {
    try {
        // Primer bloque try anidado
        try {
            // Segundo bloque try anidado
            try {
                throw 99.99; // Lanzar una excepción de tipo double
            }
            catch (char ch) {
                // Este bloque no se ejecutará porque la excepción no es de tipo char
            }
            catch (bool b) {
                // Este bloque no se ejecutará porque la excepción no es de tipo bool
            }
        }
        catch (int num) {
            // Este bloque no se ejecutará porque la excepción no es de tipo int
        }
    }
    catch (double d) {
        // Este bloque captura la excepción de tipo double
        cout << "Excepción capturada: el valor de d es " << d << endl;
    }

    return 0;
}
