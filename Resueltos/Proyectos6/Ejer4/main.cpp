#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fichero("prueba.txt");
    if (fichero.is_open()) {
        fichero << "Esto es una línea" << endl;
        fichero << "Esto es otra";
        fichero << " y esto es continuación de la anterior" << endl;
        fichero.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura" << endl;
    }
    return 0;
}
