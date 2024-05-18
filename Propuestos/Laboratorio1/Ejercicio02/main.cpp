#include "tanque.cpp"
#include <iostream>
using namespace std;

int main(){
    Tanque t;

    t.agregar(100);

    cout << "El contenido del tanque es " << t.getContenido() << endl;
    
    while(t.getContenido() >= 1.0){
        t.sacarMitad();
        cout << "El contenido del tanque despues de sacar la mitad es " << t.getContenido() << endl;
    }

    return 0;
}