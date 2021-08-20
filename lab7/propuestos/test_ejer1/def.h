#include <map>
#include <iostream>

using namespace std;
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
//Estructura de Meses
struct Fecha{
    int anio;
    int mes;
    int dia;
    void display(string A){
        cout << "Fecha "<<A<<": "<<anio<<" / "<<mes<<" / "<<dia<<endl;
    }
};
class def{
    public:
       /*Declaracion de funciones */
        bool esBisiesto(int A);
        int transformer(int A,char M, int D);
        void restarDates(Fecha A, Fecha B);  
};