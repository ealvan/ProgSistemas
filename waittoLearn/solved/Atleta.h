//archivo Atleta.h
#include <iostream>
#pragma once

class Atleta
{
    private:
        char* nombre;
        int numero;
        char* nacionalidad;
        double tiempo;
    public:
        Atleta(char* n=NULL, int nro=0, char* p=NULL, double t=0.0);//para array
        char* getNombre(void) const;
        int getNumero(void) const;
        char* getNacionalidad(void) const;
        double getTiempo(void) const;
        void setNombre(char* n);
        void setNumero(int n);
        void setNacionalidad(char* n);
        void setTiempo(double t);
        void mostrarDatos(void) const;
        ~Atleta(void);
};