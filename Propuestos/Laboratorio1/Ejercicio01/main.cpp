#include <iostream>
#include "persona.cpp"
using namespace std;

int main(){
    persona persona;

    persona.adquirirNombre();
    persona.decirNombre();
    persona.hablar();
    persona.contar();
    persona.dormir();

    return 0;
}