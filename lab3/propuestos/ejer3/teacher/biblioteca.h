#include <bits/stdc++.h>

class Atleta{
    private:
        char* nombre;
        int numero;
        char* nacionalidad;
        double tiempo;
    public:
    double getTiempo();
    int getNumero();
    void setTiempo(double time);
    void setNumero(int num);
    char* getNombre();
    char* getNacionalidad();
    void setNombre(char* name);
    void setNacionalidad(char* nacion);
    void mostrarDatos(void);


};

/*
{
        return tiempo;
    }

{
        return numero;
    }


{
        tiempo = time;
    }
{
        numero = num;
    }
{
        return nombre;
    }
{
        return nacionalidad;
    }

*/