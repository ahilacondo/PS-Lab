using namespace std;

class Tanque{
    private:
        double contenido;
    public:
        static const int capacidad = 5000.0;
        Tanque();
        double getContenido() const;
        void agregar(double cantidad);
        void sacar(double cantidad);
        void sacarMitad(); // nuevo metodo
};