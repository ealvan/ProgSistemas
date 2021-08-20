#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip> //para setprecision()
using namespace std;
//la estrucutra cliente
struct Cliente{
    string nombre;
    int nroUnit;
    double precio;
    string estado;
    void display(){
        cout << "Nombre : "<<nombre<<endl
        << "Numero de unidades : "<<nroUnit<<endl
        << "Precio Unitario : "<<setprecision(4)<<precio <<"$"<< endl
        << "Estado : "<<estado<<endl
        << "Total de Factura: "<< setprecision(4)<<nroUnit*precio<<endl<<endl;
    }
};

class def{
    public:
    //Decalracion de funciones
    string genName();
    double fRand(double fMin, double fMax);
    string genEstado();
    void display(int n, struct Cliente c[]);
    void displayMorosos(int n, Cliente cli[]);
    void displayPagadosN(int n, Cliente cli[],double total);
    void generate(int n);
};
