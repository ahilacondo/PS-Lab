#include <iostream>
#include <map>
#include <random>
using namespace std;

int generateRandomNumber(int, int);
int throwDice();
pair<int, int> throwDices();
int sumDicesResults(pair<int, int>);
void printDicesResults(int, pair<int, int>);

int main() {
    int numeroTirada = 1;
    pair<int, int> dicesResults = throwDices();
    printDicesResults(numeroTirada, dicesResults);
    int sum = sumDicesResults(dicesResults);
    
    if (sum == 7 || sum == 11) {
        cout << "Veredicto: Jugador Gana!\n";
        return 0;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        cout << "Veredicto: La Casa Gana!\n";
        return 0;
    }
    
    int tirada = sum;
    numeroTirada++;
    bool repeat = true;
    
    do {
        dicesResults = throwDices();
        printDicesResults(numeroTirada, dicesResults);
        sum = sumDicesResults(dicesResults);
        
        if (sum == tirada) {
            cout << "Veredicto: Jugador Gana!\n";
            repeat = false;
        } else if (sum == 7) {
            cout << "Veredicto: La Casa Gana!\n";
            repeat = false;
        }
    } while (repeat);
    
    return 0;
}

void printDicesResults(int numeroTirada, pair<int, int> dicesResults) {
    cout << "Tirada #" << numeroTirada << ":\n";
    cout << "Resultado del Dado #1: " << dicesResults.first << "\n";
    cout << "Resultado del Dado #2: " << dicesResults.second << "\n";
    cout << "Suma de Resultados: " << sumDicesResults(dicesResults) << "\n\n";
}

int sumDicesResults(pair<int, int> dicesResults) {
    return dicesResults.first + dicesResults.second;
}

pair<int, int> throwDices() {
    return make_pair(throwDice(), throwDice());
}

int throwDice() {
    const int MINIMUM_DICE_NUMBER = 1;
    const int MAXIMUM_DICE_NUMBER = 6;
    return generateRandomNumber(MINIMUM_DICE_NUMBER, MAXIMUM_DICE_NUMBER);
}

int generateRandomNumber(int minLimit, int maxLimit) {
    return minLimit + (rand() % maxLimit);
}
