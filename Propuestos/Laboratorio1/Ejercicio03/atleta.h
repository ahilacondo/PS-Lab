#include <string>
#include <bits/stdc++.h>
using namespace std;

class Atleta {
    public:
        std::string nombre;
        int numero;
        std::string nacionalidad;
        int tiempo;

    Atleta(string nom, int num, std::string nac, int tie){
        nombre = nom;
        numero = num;
        nacionalidad = nac;
        tiempo = tie;
    }

    static void getFastestAthlete(Atleta at1, Atleta at2) {
        if (at1.tiempo > at2.tiempo) {
            cout << "El atleta mas rapido es: " << at2.nombre << std::endl;
        } else {
            cout << "El atleta mas rapido es: " << at1.nombre << std::endl;
        }
    }
};