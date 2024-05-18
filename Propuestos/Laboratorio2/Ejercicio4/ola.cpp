


#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

system("Color 02"); //color pantalla

char op;
do {
   
    
    cout << "Calculadora CON SWITCH" << endl;
    cout << "-------------------" << endl;
    cout << "Seleccione una operacion: " << endl;
    cout << "1 - Suma" << endl;
    cout << "2 - Resta" << endl;
    cout << "3 - Multiplicacion" << endl;
    cout << "4 - Division" << endl;
    cout << "0 - Salir \n\n" << endl;
    cin >> op;
   
    switch (op) {
        case '1': {
            system("cls"); //Limpiar pantalla
            int n;
            cout << "Cuantos numeros desea sumar? ";
            cin >> n;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int num;
                cout << "Ingrese el numero " << i + 1 << ": ";
                cin >> num;
                sum += num;
            }
            cout << "La suma es: " << sum << endl;
            break;
        }
        case '2': {
            system("cls"); //Limpiar pantalla
            int num1, num2;
            cout << "Ingrese el primer numero: ";
            cin >> num1;
            cout << "Ingrese el segundo numero: ";
            cin >> num2;
            cout << "La resta es: " << num1 - num2 << endl;
            break;
        }
        case '3': {
            system("cls"); //Limpiar pantalla
            int num1, num2;
            cout << "Ingrese el primer numero: ";
            cin >> num1;
            cout << "Ingrese el segundo numero: ";
            cin >> num2;
            if (num1 == 0 || num2 == 0) {
                cout << "No se puede multiplicar por cero" << endl;
            } else {
                cout << "La multiplicacion es: " << num1 * num2 << endl;
            }
            break;
        }
        case '4': {
            system("cls"); //Limpiar pantalla
            int divisor, dividendo;
            cout << "Ingrese el divisor: ";
            cin >> divisor;
            cout << "Ingrese el dividendo: ";
            cin >> dividendo;
            if (dividendo == 0) {
                cout << "No se puede dividir por cero" << endl;
            } else {
                cout << "La division es: " << divisor / dividendo << endl;
            }
            break;
        }
        case '0': {
            system("cls"); //Limpiar pantalla
            cout << "Saliendo de la calculadora" << endl;
            break;
        }
        default: {
            system("cls"); //Limpiar pantalla
            cout << "Opcion no valida. Seleccione una opcion valida." << endl;
            break;
        }
    }
    cout << endl;
} while (op != '0');
return 0;
}
