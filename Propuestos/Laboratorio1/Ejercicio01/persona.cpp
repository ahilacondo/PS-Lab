#include "persona.h"
#include <iostream>
using namespace std;

void persona::dormir(){
    cout << "toy durmiendo zzzzz\n";
}

void persona::hablar(){
    cout << "alo alo alo\n";
}

void persona::contar(){
    cout << "1,2,3,4,5........\n";
}

void persona::adquirirNombre(){
    cout << "ingrese su nombre >> ";
    cin >> nombre;
}

void persona::decirNombre(){
    cout << "Mi nombre es >> " << nombre << endl;
}