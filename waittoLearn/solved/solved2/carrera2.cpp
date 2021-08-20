//Carrera2.cpp
#include "carrera2.h"
Carrera2::Carrera2(int d, int cantidad){
    distancia=d;
    cantAtletas=cantidad;
    competidores=new Atleta* [cantidad];
    indice=0;
}

int Carrera2::getDistancia(void) const{

    return distancia;
}
int Carrera2::getCantAtletas(void) const{

    return cantAtletas;
}
Atleta* Carrera2::getGanador(void) const{

    double t=competidores[0]->getTiempo();//Uso de ->
    double taux;
    int iaux;
    for(int i=1;i<cantAtletas;i++){
        taux=competidores[i]->getTiempo();
        
        if(taux<t){
            t=taux;
            iaux=i;
        }
    }
    return competidores[iaux];
}
void Carrera2::agregarAtleta(Atleta* p){
    if(indice<cantAtletas){
        competidores[indice]=p;
        indice++;
    }
}
Carrera2::~Carrera2(void){
    delete[] competidores;
}
