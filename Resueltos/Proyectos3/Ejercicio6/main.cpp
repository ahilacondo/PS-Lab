#include <iostream>
using namespace std;

void swap(int& primero, int& segundo) {
    int temporal = primero;
    primero = segundo;
    segundo = temporal;
}

int main() {
    int a = 2, b = 3;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
