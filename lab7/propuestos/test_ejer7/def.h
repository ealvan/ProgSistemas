#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip>
#include <tuple>
using namespace std;

//implementacion de estrucutas
struct Fecha{
    int anio;
    int mes;
    int dia;
    void display(string A){
        cout << "Fecha "<<A<<": "<<anio<<" / "<<mes<<" / "<<dia<<endl;
    }
};
struct Persona{
    string nombre;
    Fecha bourne;
};