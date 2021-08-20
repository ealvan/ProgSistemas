/*
En unclad° 
Escribir un programa en C++ que permita lo siguiente:
 Declarar una variable como referencia 
 poniendo el & en la declaracion, convirtiendola 
 en un nombre alternativo para la variable existente 
*/
#include <iostream>

using namespace std;
 
int main(){
    int a = 12;
    int&alias_a =  a;
    alias_a = 21;
    cout << "el valor de a es: "<< a<<endl;
    
    cout << "el valor de alias_a es: "<< alias_a<<endl;
    return 0;
}
