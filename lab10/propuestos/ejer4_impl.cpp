#include "ejer4_def.h"

//implementando what()
const char* Error::what() const throw() {
    switch(razon) {
        case 1:
            return "No_raices_reales";
        case 2:
            return "primer_coeficiente_cero";
        default:
            return "Error inesperado";
    }
    
}
void solverEcuacionCuadratica(double arr[3], double& sol1, double& sol2){
    //ax^2 + bx + c
    //arr[a,b,c] en arr[3]
    double a = arr[0];
    double b = arr[1];
    double c =  arr[2];
    if(a == 0){
        throw Error(2);
    }
    double determinante =  pow(b,2)-4*a*c;
    if(determinante < 0){
        //si es negativo no tiene soluciones reales
        throw Error(1);
    }
    sol1 = (-b + sqrt(determinante))/2*a;
    sol2 = (-b - sqrt(determinante))/2*a;
}