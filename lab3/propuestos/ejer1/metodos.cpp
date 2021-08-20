#include <iostream>
#include "biblioteca.h"
//estamos en un metodo .cpp
using namespace std;

//implementamos los metodos
//uno por uno
void Persona::dormir(){
    cout << "Estoy durmiendo" << endl;            
}
//luego
void Persona::hablar(){
    cout << "Estoy hablando" << endl;            
}
//vemos que la forma de decir que este
//metodo pertenece a una clase en especifico 
//es esta.
//"NOMBRECLASE::nombreMetodo(){...}"
void Persona::contar(){
    cout << "Estoy contando, 1 2 3, ..." << endl;            
}
//luego veremos como
void Persona::adquirirNombre(){
    cout << "Hola soy una persona " << endl;            
}
//se usan en el archivo
//principal.cpp
void Persona::decirNombre(){
    cout << "Estoy diciendo mi nombre" << endl;            
}