//para el imprimir en pantalla
#include <iostream>
//imprtamos para usar el floor()
#include <cmath>
using namespace std;

class Sala{
    private:
        //datos de cada sala
        string nombre;
        double ancho;
        double largo;
        bool equipado;
    public:
        //constructor
        Sala(string n, double a, double l, bool eq){
            nombre = n;
            ancho = a;
            largo = l;
            equipado = eq;
        }
        //la capacidad Maxima de personas
        int obtenerCapacidad(){
            const double personaOcupa = 1.5;
            double area = ancho*largo;
            //hacemos que baje hacia abajo el double
            //para que sea capacidad maxima
            int capacidad = floor(area/personaOcupa);
            return capacidad;
        }
        //costo mensual de la sala
        int alquilerMensual(){
            int alquiler;
            double area = ancho*largo;
            if(equipado){
                alquiler = 45;//si es equipada
            }else{
                alquiler = 32;//si no lo es
            }
            alquiler *= area;
            return alquiler;
        }
        void displayDatos(){
            cout << "Info de la " << nombre << ": "<<endl;
            cout << "Area de la sala: " << floor(ancho*largo)<<"m2"<<endl;
            cout << "Alquiler mensual: " << alquilerMensual() <<" soles"<< endl;
            cout << "Aforo maximo: " << obtenerCapacidad() << endl;
        }
};