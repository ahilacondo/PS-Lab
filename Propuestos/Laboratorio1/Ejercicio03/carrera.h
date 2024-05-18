#include "atleta.h"

class Carrera {
public:
    int distancia;
    Atleta *ganador;

    Carrera(int dis, Atleta& gan){
        distancia = dis;
        ganador = &gan;
    }
};