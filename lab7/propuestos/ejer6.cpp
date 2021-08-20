#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip>
#include <tuple>
using namespace std;
//implementacion de estrucuta
struct Persona{
    string nombre;
    string apellido;
    signed int edad;
};
//optener datos de una Persona
void getData(Persona* persona){
    int size = 3;
    string str[]={
        "Ingrese el nombre: ",
        "Ingrese el apellido: ",
        "Ingrese el edad: ",
    };
    cout << str[0];
    cin >> persona -> nombre;
    cout << str[1];
    cin >> persona -> apellido;
    cout << str[2];
    cin >> persona -> edad;
}
//display en consola
void display(Persona *p){
    cout << "Datos de la persona: "<<endl;
    cout << p->nombre<<", "<<p->apellido<<", "<<p->edad<<endl;
}

int main(){
    Persona p;
    getData(&p);
    display(&p);
}