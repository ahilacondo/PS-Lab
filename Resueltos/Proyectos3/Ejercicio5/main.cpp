#include <iostream>
using namespace std;

int main() {
    int x = 10;
    // ref es una referencia hacia x
    int& ref = x;
    // valor de x es ahora cambiado a 20
    ref = 20;
    cout << "x = " << x << endl;
    // valor de x es ahora cambiado a 30
    x = 30;
    cout << "ref = " << ref << endl;
    return 0;
}
