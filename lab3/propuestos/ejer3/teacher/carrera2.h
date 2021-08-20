#pragma once
#include "biblioteca.h"
class Carrera2{

    private:
        int distancia;
        Atleta* competidores;
        int cantidadAtletas;
        int indice;
    public:
        Carrera2(int D, int cantidad);
        int getDistancia(void) const;
        Atleta *getGanador()const;
        int getCanidadAtletas();
        void agregarAtleta();

};