#include <iostream>
#include "biblioteca.cpp"
using namespace std;

int main(){

    int clave1[] = {3,2,1};
    int clave2[] = {4,5,6};
    
    Candado c1 = Candado(clave1);
    Candado c2 = Candado(clave2);

    c1.alterarDigito(0,3);
    if(c2.puedeAbrir()){
        cout << "El candado c2 SI puede abrirse" << endl; 
    }else{
        cout << "El candado c2 NO puede abrirse" << endl; 
    }

    if(c1.mismaCombinacionActual(c2)){
        cout << "El candado c1 y c2 SI tienen la misma combinacion actual" << endl;
    }else{
        cout << "El candado c1 y c2 NO tienen la misma combinacion actual" << endl;
    }
    return 0;
}