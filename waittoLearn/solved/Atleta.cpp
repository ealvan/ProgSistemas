//Atleta.cpp
#include "Atleta.h"
#include <string.h>
#include <iostream>
using std::cout;
Atleta::Atleta(char* n, int nro, char* p, double t)
{
    nombre=new char[strlen(n) + 1];
    strcpy(nombre, n);
    numero=nro;
    nacionalidad=new char[strlen(p)+1];
    strcpy(nacionalidad, p);
    tiempo=t;
}
char* Atleta::getNombre(void) const
{
    return nombre;
}
    int Atleta::getNumero(void) const
{
    return numero;
}
    char* Atleta::getNacionalidad(void) const
{
    return nacionalidad;
}
    double Atleta::getTiempo(void)const
{
    return tiempo;
}
void Atleta::mostrarDatos(void) const
{
    cout<<"Nombre atleta: "<<nombre<<"\nNumero: "<<numero<<"\nNacionalidad:"<<nacionalidad<<"\nTiempo: "<<tiempo<<"\n";
}
void Atleta::setNombre(char *n)
{
    if(nombre==NULL){
        nombre=new char[strlen(n) + 1];
        strcpy(nombre, n);
    }
}
void Atleta::setNumero(int n)
{
    numero=n;
}
void Atleta::setTiempo(double t)
{
    tiempo=t;
}
void Atleta::setNacionalidad(char *p)
{
if(nacionalidad==NULL){
nacionalidad=new char[strlen(p)+1];
strcpy(nacionalidad, p);
}
}
Atleta::~Atleta(void)
{
    delete[] nombre;
    delete[] nacionalidad;
    cout<<"Se invoca al destructor de atleta\n";
}