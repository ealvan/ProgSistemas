#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip>
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
        << "Estado : "<<estado<<endl<<endl;
    }
};

class def{
    public:
    /*Declaracion de funciones */
    void generate(int n);
    void display(int n, struct Cliente c[]);
    double fRand(double fMin, double fMax);
    string genName();
};