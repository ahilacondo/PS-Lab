#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main () {
    struct Tdato {
        int b;
        char s[100];
    };

    int x = 12, n = 8, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    double f = 15.62;
    char nombre[] = "Ejercicios ficheros binarios";
    Tdato p;
    p.b = 18;
    strcpy(p.s, "cadena de texto");

    ifstream f1;
    ofstream f2;

    f1.open("entrada.dat", ios::binary);
    f2.open("salida.dat", ios::binary);

    f2.write(reinterpret_cast<char*>(&x), sizeof(x)); // Instrucción a
    f2.write(reinterpret_cast<char*>(&f), sizeof(f)); // Instrucción b
    for (int i = 0; i < 5; i++) { // Instrucción c
        f2.write(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
    }
    for (int i = 0; i < 10; i++) { // Instrucción d
        f2.write(reinterpret_cast<char*>(&nombre[i]), sizeof(nombre[i]));
    }
    f2.write(reinterpret_cast<char*>(&p), sizeof(p)); // Instrucción e
    f2.close();

    f1.read(reinterpret_cast<char*>(&x), sizeof(x)); // Instrucción f
    cout << x << endl;

    f1.read(reinterpret_cast<char*>(&f), sizeof(f)); // Instrucción g
    cout << f << endl;

    for (int i = 0; i < 5; i++) { // Instrucción h
        f1.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
        cout << a[i] << endl;
    }

    for (int i = 0; i < 10; i++) { // Instrucción i
        f1.read(reinterpret_cast<char*>(&nombre[i]), sizeof(nombre[i]));
        cout << nombre[i];
    }
    cout << endl;

    f1.read(reinterpret_cast<char*>(&p), sizeof(p)); // Instrucción j
    f1.close();

    cout << p.b << endl;
    cout << p.s << endl;

    return 0;
}
