#include <iostream>
using namespace std;

int main() {
    try {
        throw 3.14; // Lanzar una excepción de tipo double
    }
    catch (double d) {
        cout << "Capturado un double con valor: " << d << endl;
    }
    catch (char ch) {
        cout << "Capturado un char con valor: " << ch << endl;
    }
    catch (int num) {
        cout << "Capturado un int con valor: " << num << endl;
    }

    return 0;
}
