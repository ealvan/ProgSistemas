
#include "def.h"
//nos dice si es bisiesto
bool esBisiesto(int A){
    if(A % 4 == 0 && A%100 != 0){
        return true;
    }else if( A % 4 == 0 && A%100 == 0 && A%400 == 0){
        return true;
    }
    return false;
}
//tranforma una fecha en dias
int transformer(int A,char M, int D){

    int r = 0;
    //manipulacion de map si es bisiesto
    if(esBisiesto(A)){
        meses['F'] = 29;
    }else{
        meses['F'] = 28;    
    }
    r += A*365;
    r += meses[M];
    r += D;

    return r;
}
//es la funcion general
void restarDates(Fecha A, Fecha B){
    int fa = transformer(A.anio,A.mes,A.dia);
    int fb = transformer(B.anio,B.mes,B.dia);
    int r = fa - fb;
    if(r < 0){
        r*=-1;
    }
    for(int init = A.anio +1; init < B.anio; init++){
        if(esBisiesto(init)){
            r++;
        }
    }

    A.display("A");
    B.display("B");

    cout << "La diferencia de dias es : "<<r<<endl;
}