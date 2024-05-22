    #include <iostream>
using namespace std;

int main() {
    int a = 5; // una simple variable
    int &S = a;  // referencia a 'a'
    int &S0 = S; // referencia a 'S' (que es 'a')
    int &S1 = S0; // referencia a 'S0' (que es 'a')

    cout << "a = " << a << "\t"
         << "S = " << S << "\t"
         << "S0 = " << S0 << "\t"
         << "S1 = " << S1 << "\n";

    // Todas las referencias no son diferentes en sus valores
    // Ellas hacen referencia a la misma variable 'a'
    
    return 0;
}
