#include <iostream>

using namespace std;
struct Fecha{
    int anio,mes,dia;
};
struct Persona {
        char nombre[15];
        int edad,peso;
        Fecha fecha;       
}persona = {"Cindy",20,45,2,12,1997};

struct Empleado{
    Persona persona;
    int salario;
}trabajador = {"Steven",19,60,22, 1998,1000};


int main(){
    cout << "  Persona: "<<persona.nombre;
    cout << "  Edad: "<<persona.edad;
    cout << "  Peso: "<<persona.peso;
    cout << "  Dia  Nacimiento: "<<persona.fecha.dia;
    cout << "  Mes de Nacimiento: "<<persona.fecha.mes;
    cout << "  Año de nacimiento: "<<persona.fecha.anio;
}