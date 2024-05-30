#include <iostream>
using namespace std;

struct Punto {
    int x, y;
};
int main()
{
    struct Punto array[20];
    //Accesando a los atributos del arreglo
    array[0].x = -1;
    array[0].y = -2;
    cout << array[0].x << " " << array[0].y << endl;
    return 0;
}
