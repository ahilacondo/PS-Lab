#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Atleta {
public:
    string nombre;
    int numero;
    string nacionalidad;
    int tiempo;

    Atleta(string nom, int num, string nac, int tie) {
        nombre = nom;
        numero = num;
        nacionalidad = nac;
        tiempo = tie;
    }
};

class Carrera {
public:
    int distancia;
    vector<Atleta> competidores;

    Carrera(int dis, vector<Atleta>& comp) : distancia(dis), competidores(comp) {}

    Atleta getWinner() {
        Atleta winner = competidores[0];
        for (size_t i = 1; i < competidores.size(); ++i) {
            if (competidores[i].tiempo < winner.tiempo) {
                winner = competidores[i];
            }
        }
        return winner;
    }
};

int main() {
    Atleta at1("Mario", 23, "Peruano", 4);
    Atleta at2("Pedro", 25, "Colombiano", 6);
    Atleta at3("Juan", 27, "Mexicano", 5);
    vector<Atleta> competidores = {at1, at2, at3};

    Carrera carrera(100, competidores);
    Atleta ganador = carrera.getWinner();
    
    cout << "El ganador de la carrera es: " << ganador.nombre << endl;

    return 0;
}

