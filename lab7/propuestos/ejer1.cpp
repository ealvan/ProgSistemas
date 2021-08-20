#include <map>
#include <iostream>

using namespace std;

//Estructura de Meses
struct Fecha{
    int anio;
    int mes;
    int dia;
    void display(string A){
        cout << "Fecha "<<A<<": "<<anio<<" / "<<mes<<" / "<<dia<<endl;
    }
};
//el mapa de meses
map<char,int> meses = {
    {'E',31},//1
    {'F',28},//2 29 si es bisiesto
    {'R',31},//3
    {'A',30},//4
    {'M',31},//5 
    {'J',30},//6
    {'L',31},//7
    {'A',31},//8
    {'S',30},//9
    {'O',31},//10
    {'N',30},//11
    {'D',31},//12 meses
};
/*Declaracion de funciones */
bool esBisiesto(int A);
int transformer(int A,char M, int D);
void restarDates(Fecha A, Fecha B);

int main(){
    Fecha f1 = {2000,12,12};
    Fecha f2 = {2021,12,12};

    restarDates(f1, f2);
}


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