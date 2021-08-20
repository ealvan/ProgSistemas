#include <iostream>
#include "biblioteca.cpp"
using namespace std;

int main(){
    Atleta t1 = Atleta("Usaimbol",12,"Madagascar", 10.21);
    Atleta t2 = Atleta("Pepito",15,"Colombia", 10.54);
    Atleta t3 = Atleta("Juan El veloz", 56, "Peru", 14.32);

    Carrera race = Carrera(3,300.00);
    race.addAtleta(&t1);
    race.addAtleta(&t2);
    race.addAtleta(&t3);

    cout << "El ganador de la carrera es : " << endl;
    race.getGanador();

}