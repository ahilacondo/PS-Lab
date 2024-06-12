#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    string filename;
    string line;

    cout << "Ingrese el nombre del archivo: ";
    getline(cin, filename);

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "¡El archivo no existe!" << endl;
        return 1;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
