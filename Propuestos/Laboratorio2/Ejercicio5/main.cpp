#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

void encontrarPares();
void mostrarNrosPerfectos();
bool esNumeroPerfecto(int);
void invertirNumero();

int main(){
    int opc = 1;
    while(opc != 0){
        // Opciones del menu
        cout << "\t --- MENU DE OPCIONES ---" << endl;
        cout << "0: Finalizar ejecución" << endl;
        cout << "1: Identificar números (10 números) pares e impares" << endl;
        cout << "2: Mostrar 100 primeros números perfectos" << endl;
        cout << "3: Invertir número entero de cuatro cifras" << endl;
        cout << "- Ingrese la función de desea utilizar: ";
        cin >> opc;
        cout << endl;
        
        switch (opc){ // Verifica la opcion seleccionada
            case 0:
                break;
            case 1:
                encontrarPares();
                break;
            case 2:
                mostrarNrosPerfectos();
                break;
            case 3:
                invertirNumero();
                break;
            default: // En caso se ingrese un valor incorrecto
                cout << "---> ¡Ingrese una opción válida!" << endl;
                getch();
                cout << endl;
                break;
        }
    } // El bucle se rompe solo cuando se ingresa 0
    
    cout << "---> ¡Ejecución finalizada!";
    return 0;
}

void encontrarPares(){
    cout << "\t --- ENCONTRAR PARES E IMPARES ---" << endl;
    int num; // Arreglo de 10 enteros
    string pares = "", impares = "";
    
    // Ingresando los elementos del arreglo
    for(int i = 0; i < 10; i++){
        cout << "- Ingrese el " << i + 1 << "° número: ";
        cin >> num;
        
        // Clasificacion entre par e impar
        if(num % 2 == 0){
            pares += to_string(num) + " ";
        } else{
            impares += to_string(num) + " ";
        }
    }
    
    cout << "RESULTADO: " << endl;
    cout << "---> Los números pares son: " << pares << endl;
    cout << "---> Los números impares son: " << impares << endl;
    getch();
    cout << endl;
}

void mostrarNrosPerfectos(){
    cout << "\t --- MOSTRAR LOS 100 PRIMEROS NUMEROS PERFECTOS ---" << endl;
    // Ingresando los elementos del arreglo
    int contador = 0, num = 2;
    while(contador < 100){
        // Verifica si es perfecto
        if(esNumeroPerfecto(num)){
            cout << "---> " << num << endl;
            contador++;
        }
        num++;
    }
    getch();
    cout << endl;
}

bool esNumeroPerfecto(int num){
    int suma = 1, maxDivisor = sqrt(num), divisor = 2;
    
    // Mientras que el divisor sea menor o igual que el maximo divisor posible
    // El máximo divisor seria la raíz cuadrada del número
    while(divisor <= maxDivisor){
        if(num % divisor == 0){
            // Cada que se encuentra un divisor se encuentra su respectivo
            // divisor con el que se obtiene dicho número
            suma += divisor + num/divisor;
        }
        divisor++;
    }
    
    // En caso dicho divisor máximo sea entero, se le resta la duplicidad
    if(divisor == maxDivisor){
        suma -= maxDivisor;
    }
    
    return num == suma;
}

void invertirNumero(){
    cout << "\t --- INVERTIR NUMERO DE 4 CIFRAS ---" << endl;
    int num = 0;
    
    // Ingreso del número
    while(true){
        cout << "- Ingrese un número entero de 4 cifras: ";
        cin >> num;
        
        if(1000 <= num && num <= 9999){
            // Verifica que el numero tenga cuatro cifras
            break;
        }
        
        cout << "---> ¡Solo aceptan números de 4 cifras!"<< endl;
        getch();
    }
    
    int ninv, u, d, c, m;
    // Se extraen los dígitos del número
    u = num % 10; // Unidades
    d = (num % 100 - u) / 10; // Decenas
    m = num / 1000; // Unidades de millar
    c = num / 100 -
    10 * m; // Centenas
    
    // Se invierten los dígitos
    ninv = 1000 * u + 100 * d + 10 * c + m;
    cout << "---> El número invertido es: " << ninv << endl;
    getch();
    cout << endl;
}

