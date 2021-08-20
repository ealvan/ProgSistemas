/*
Escribir un programa en C++ que
 permits realizar lo siguiente:
  Crear una funcion que reciba
   una referenda a una variable,
    la funci6n intercambiara 
    los valores de dos variables
     haciendo que el valor de 
     cada una al finalizar la 
     funci6n sea de la otra variable 
*/

#include <iostream>

using namespace std;

void swap(int& a, int&b){
    int aux = a;
    a = b;
    b = aux;
}

int main(){
    int a = 12;
    int b = 13;
    cout << "a : "<<a<<endl;
    cout << "b : "<<b<<endl;
    swap(a,b);

    cout << "a : "<<a<<endl;
    cout << "b : "<<b<<endl;
    
    return 0;
}