#include <iostream>
#include <cstdlib>
/*
• Crear un programa en C++ que permita crear 
un limite superior para una funcion rand°,
 este limite debe ser dado para valores 
 del 0 al 1, 
 del 0 al 9, 
 del 0 al 1499 y
  del 0 al 65535 

*/
using namespace std;

int main(){

    int a = 0;
    a = (rand()%2);
    cout <<"rand() % 2 = "<<  a<< endl;
    a = (rand()%10);
    cout <<"rand() % 10 = "<< a << endl;
    a = (rand()%65536);
    cout <<"rand() % 65536 = "<< a << endl;

    cout << "RAND MAX para este equipo tiene un valor de: "<<RAND_MAX<< endl;
    return 0;
}