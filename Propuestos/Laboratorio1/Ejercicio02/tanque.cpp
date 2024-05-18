#include "tanque.h"

Tanque::Tanque() : contenido(0){}

double Tanque::getContenido() const{
    return contenido;
}

void Tanque::agregar(double cantidad){
    if(cantidad > 0){
        if (contenido + cantidad <= capacidad){
            contenido += cantidad;
        }
    }
}

void Tanque::sacar(double cantidad){
    if(cantidad > 0){
        if (contenido - cantidad < 0){
            contenido -= cantidad;
        }
    }
}

void Tanque::sacarMitad(){
    if (contenido > 0) {
        contenido /= 2;
    }
}