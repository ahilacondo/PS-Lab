#include <iostream>
#include <cmath>
using namespace std;

static const int ERROR_DOMINIO = 100;
static const int ERROR_RANGO = 101;

class ErrorMat {
public:
    ErrorMat() : motivo(0) {}
    ErrorMat(int m) : motivo(m) {}
    const char* motivoError() const noexcept;
private:
    int motivo;
};

const char* ErrorMat::motivoError() const noexcept {
    switch (motivo) {
        case ERROR_DOMINIO:
            return "Error de Dominio";
        case ERROR_RANGO:
            return "Error de Rango";
        default:
            return "Error Desconocido"; // En teoría no debería ocurrir este caso
    }
}

double logaritmo(double n) {
    try {
        if (n < 0) 
            throw ErrorMat(ERROR_DOMINIO);
        if (n == 0) 
            throw ErrorMat(ERROR_RANGO);
        return log(n);
    }
    catch (const ErrorMat& e) {
        cout << "Excepción capturada: " << e.motivoError() << endl;
    }
    return 0;
}

int main() {
    double r = 100;
    cout << "log(" << r << ") = " << logaritmo(r) << endl;
    cout << "log(-" << r << ") = " << logaritmo(-r) << endl;

    cin.get();
    return 0;
}
