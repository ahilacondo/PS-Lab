#include <iostream>
#include <cmath> // Para abs()
using namespace std;

struct Fecha {
    int day;
    int month;
    int year;
};

void mostrarFecha(Fecha fecha) {
    cout << fecha.day << "/" << fecha.month << "/" << fecha.year << endl;
}

int restaFechas(Fecha fecha1, Fecha fecha2) {
    int dias = 0;
    if (fecha1.year == fecha2.year) {
        if (fecha1.month == fecha2.month) {
            dias = fecha2.day - fecha1.day;
        } else {
            dias = (fecha2.month - fecha1.month) * 30;
            dias += fecha2.day - fecha1.day;
        }
    } else {
        dias = (fecha2.year - fecha1.year) * 365;
        dias += (fecha2.month - fecha1.month) * 30;
        dias += fecha2.day - fecha1.day;
    }
    return abs(dias);
}

int main() {
    Fecha fecha1 = {28, 05, 2024};
    mostrarFecha(fecha1);
    Fecha fecha2 = {30, 05, 2024};
    mostrarFecha(fecha2);
    cout << "Diferencia de dias: " << restaFechas(fecha1, fecha2) << endl;
    return 0;
}
