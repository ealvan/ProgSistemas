//Carrera1.cpp
#include "carrera1.h"
#include <iostream>
Carrera1::Carrera1(int d, Atleta *g)
{
distancia=d;
ganador=g;
}
int Carrera1::getDistancia(void) const
{
return distancia;
}
Atleta * Carrera1::getGanador(void) const
{
return ganador;
}
Carrera1::~Carrera1(void)
{
ganador=NULL;
}