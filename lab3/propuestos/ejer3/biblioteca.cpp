#include <iostream>
#include <string>
using namespace std;
class Atleta{
    private:
        string nombre;
        int numero;
        string nacionalidad;
        double tiempo;
    public:
        Atleta(string n, int num, string nacio, double time){
            nombre = n;
            numero = num;
            nacionalidad = nacio;
            tiempo = time;                
        }
        //getters and setters
        string getName(){
            return nombre;
        }
        void setName(string n){
            nombre = n;
        }
        int getNumber(){
            return numero;
        }
        void setNumber(int n){
            numero = n;
        }
        string getNacionality(){
            return nacionalidad;
        }
        void setNacionality(string n){
            nacionalidad = n;
        }
        double getTime(){
            return tiempo;
        }
        void setTime(double t){
            tiempo = t;
        }
        void displayAtleta(){
            cout << "Informacion del Atleta : "<< nombre << endl;
            cout << "   Numero ° : " << numero << endl;
            cout << "   Nacionalidad : "<< nacionalidad <<endl;
            cout << "   Tiempo : "<< tiempo << endl;
        }
};

class Carrera{
    private:
        double distancia;
        int cantidadAtletas;
        Atleta** competidores;
    public:
        Carrera(int nroAtletas, double dist){
            competidores = new Atleta*[nroAtletas];
            cantidadAtletas = nroAtletas;
            distancia = dist;
        }
        double getDistancia(){
            return distancia;
        }
        int getNroAtleta(){
            return cantidadAtletas;
        }
        void addAtleta(Atleta* a){
            static int indice =0;
            if(indice < cantidadAtletas){
                competidores[indice] = a;
                indice++;
            }
        }
        void getGanador(){
            double menorTime = competidores[0]->getTime();
            double actualTime;
            int indexAtleta;
            for(int i = 1; i < cantidadAtletas; i++){
                actualTime = competidores[i]->getTime();
                if(actualTime < menorTime){
                    actualTime = menorTime;
                    indexAtleta = i;
                }
            }
            Atleta *winner = competidores[indexAtleta];
            winner -> displayAtleta();
        }
};