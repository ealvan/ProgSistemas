#include <iostream>
#include <cstdlib>

using namespace std;
/*
• Crear un programa en C++ que permita crear
 un limite inferior y un limite superior 
 mpstrandolos a partir
 de una resta en la implementacion 
 del programa para valores entre
  10 y 26 y 
  25 y 100 
*/
int main(){
    int valor =0;
    cout << "rand() definiendo limite inferir y especificando el limite superior"<<endl;
    valor = 10 + rand() % (26-10);
    cout << "10 + rand() % (26-10) =  "<< valor<<endl;
    valor = 25 +rand()%(100-25);
    cout << "25 +rand()%(100-25) =  "<< valor<<endl;
    return 0;
}