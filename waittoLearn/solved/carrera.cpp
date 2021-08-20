//archivo Carrera.cpp
#include "carrera.h"
#include <string.h>
Carrera::Carrera(int d, char* g){
    distancia=d;
    ganador=new char[strlen(g) + 1];
    strcpy(ganador, g);
}
int Carrera::getDistancia(void) const{
    return distancia;
}
char* Carrera::getGanador(void) const{
    return ganador;
}
Carrera::~Carrera(void){
    delete[] ganador;
}