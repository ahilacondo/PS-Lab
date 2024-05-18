#include "atleta.h"
#include <iostream>

int main() {
    Atleta at1("Juan", 12, "Peruano", 4);
    Atleta at2("Maxs", 21, "Boliviano", 6);
    
    Atleta::getFastestAthlete(at1, at2);

    return 0;
}
