#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip>
#include <tuple>
using namespace std;
//implementacion de estrucutas
struct Persona{
    string nombre;
    string direccion;
    string tel;
    int edad;
    void display(){
        cout <<
        "Nombre: "<<nombre<<endl<<
        " Direccion: "<< direccion<<endl<<
        " Telefono: "<<tel<<endl<<
        " Edad: "<<edad<<endl;
    }
};