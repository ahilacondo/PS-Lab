#include <iostream>
using namespace std;

int main()
{
    struct
    {
        string nombre;
        char inicial;
        int edad;
        float nota;
    } 
    persona;
    persona.nombre = "Juan";
    persona.inicial = 'J';
    persona.edad = 20;
    persona.nota = 7.5;
    cout << "La edad de " << persona.nombre << " es " << persona.edad << endl;

    return 0;
}
