#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include "atleta.h"
#include "carrera.h"
using namespace std;

Atleta getFastestAthlete (Atleta at1, Atleta at2) {
    if (at1.tiempo > at2.tiempo) {
        return at2;
    } else {
        return at1;
    }
}

int main() {
    Atleta at1("Mario", 23, "Peruano", 4);
    Atleta at2("Pedro", 25, "Colombiano", 6);
    
    Atleta atletaRapido = getFastestAthlete(at1, at2);
    cout << "El atleta mas rapido es: " << atletaRapido.nombre << endl;
    
    Carrera carr1(45, atletaRapido);
    cout << carr1.ganador->nombre << endl;
    getch();
    return 0;
}
