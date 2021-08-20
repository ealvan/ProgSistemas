#include <iostream>
#include "biblioteca.h"
#include "metodos.cpp"
using namespace std;

int main(){
    Tanque t1;
    t1.agregar(100.0);
    while(t1.getContenido() >= 1.0){
        t1.sacaMitad();
    }
    cout << "El contenido es menor a 1 unidad." <<endl;
    cout << t1.getContenido() << endl;
    return 0;
}
