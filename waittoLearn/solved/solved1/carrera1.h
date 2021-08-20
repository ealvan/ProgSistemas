//Carrera1.h
#pragma once
#include "Atleta.h"
class Carrera1
{
private:
int distancia;
Atleta *ganador;
public:
Carrera1(int d, Atleta *g);
int getDistancia(void)const;
Atleta * getGanador(void) const;
~Carrera1(void);
};