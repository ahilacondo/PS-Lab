#include <iostream>
using namespace std;

struct Punto{
    int x, y;
};
int main()
{
    struct Punto p1 = {2, 16};
    //p2 es un puntero a la estructura p1
    struct Punto* p2 = &p1;
    //Accesando a los atributos usando la estructura puntero
    cout << p2 -> x << " " << p2 -> y << endl;
    return 0;
}