//pruebaAtleta.cpp
#include "Atleta.h"
#include "carrera.h"
#include "./solved1/carrera1.h"
#include "./solved2/carrera2.h"
#include <iostream>
using std::cout;
int main(void){
    Atleta a1("Juan Perez",1, "Argentina", 10.1);
    Atleta a2("John Ford",2,"USA", 9.1);
    if(a1.getTiempo() < a2.getTiempo())
        cout<<"El atleta "<<a1.getNombre()<<" es el mas rapido\n";
    else
        cout<<"El atleta "<<a2.getNombre()<<" es el mas rapido\n";

    Carrera c1(100, "John Ford");

    cout<<"El ganador de la carrera es: "<<c1.getGanador()<<"\n";
 
    Atleta *p=new Atleta("Juan Castro", 3, "Mexico", 7.3);

    Carrera1 c2(200,p);
    
    Atleta *q=c2.getGanador();
    
    q->mostrarDatos();
    Carrera2 c3(300,3);
    
    c3.agregarAtleta(&a1);
    c3.agregarAtleta(&a2);
    c3.agregarAtleta(p);
    
    Atleta *r=c3.getGanador();
    
    r->mostrarDatos();
    
    delete p;
    return 0;
}