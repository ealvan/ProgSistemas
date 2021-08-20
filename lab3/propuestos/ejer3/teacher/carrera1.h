#pragma once

#include "biblioteca.h"

class Carrera1{
    int distancia;
    Atleta* ganador;
    public:
        Carrera1();
        int getDistancia(void) const;
        Atleta * getGanador(void) const;
        ~Carrera1(void);
};