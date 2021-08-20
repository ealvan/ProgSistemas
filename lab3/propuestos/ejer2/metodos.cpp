#include "biblioteca.h"
#include <iostream>
using namespace std;
double Tanque::getContenido() const{
    return contenido;
}
void Tanque::agregar(double cantidad){
    //no puedes agregar mas de la capacidad
    if(contenido + cantidad <= 5000){
        contenido = contenido + cantidad;            
    }else{
        cout << "No se permite AGREGAR esta cantidad: " <<cantidad<<endl;
    }
}
void Tanque::sacar(double cantidad){
    if(cantidad <= contenido){
        contenido = contenido - cantidad;
    }else{
        cout << "No se permite SACAR esta cantidad: " <<cantidad<<endl;
    }
}
Tanque::Tanque(void){
    contenido = 0;//es el inicio de todo tanque, cuando se crea
}

//sacaMItad

void Tanque::sacaMitad(){
    if(contenido > 0){
        contenido = contenido/2;
    }else{
        cout<< "El tanque esta vacio"<<endl;
    }
}


/*
{
            
        }
        {
if(cantidad <= contenido){
    contenido = contenido - cantidad;
}
        }


*/
