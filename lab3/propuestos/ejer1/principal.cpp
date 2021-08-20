#include <iostream>
//importamos los metodos y la clase
#include "biblioteca.h"
#include "metodos.cpp"

using namespace std;
//hacemos el main
int main(){
    //y usamos cada metodo
    Persona p1;
    p1.adquirirNombre();
    p1.contar();
    p1.hablar();
    p1.dormir();
    p1.decirNombre();
}