//Carrera2.h
#pragma once
#include "Atleta.h"
class Carrera2
{
    private:
        int distancia;
        Atleta** competidores;
        int cantAtletas;
        int indice;
    public:
        Carrera2(int d, int cantidad);
        int getDistancia(void) const;
        Atleta *getGanador(void) const;
        int getCantAtletas(void) const;
        void agregarAtleta(Atleta* p);
        ~Carrera2(void);
};