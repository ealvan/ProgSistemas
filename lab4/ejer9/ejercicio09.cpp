/*
Ejercicios 
• Crear un programa en C++ que permita crear un limite
 inferior para una funcion rand°, este limite debe
  ser dado para los valores que van del 10 para 
  adelante y del 65000 para adelante 
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    
    int valor =0;
    cout << "Definiendo limite inferior: "<<endl;
    valor = 10 +rand();
    cout << "10 + rand():  "<<valor<<endl;
    valor = 65000 +rand();
    cout << "rand() + 65000 : " << valor <<endl;
    return 0;


    // int a = rand()%(6500-10) + 10;

    // cout << "a = "<< a<<endl;
}