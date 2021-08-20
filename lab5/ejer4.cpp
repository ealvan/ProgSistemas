/*
Enunciado 
Escribir un programa en C++ qde permita
realizar lo siguiente: Pasar como valor
de entrada en una funcidn la referencia
de una variable para que devuelva el
cuadrado de dicho valor usando 
esa misma variable 
*/

#include <iostream>

using namespace std;
void cuadrado(int &m){
    cout << "La direcciom de m em cuadrado() es: " << &m << endl;
    m  *=  m;
    // cout << "Valor de ptr : "<< &n<<endl;
     
    // n *=n;
    // return n;
}
int main(){
    int n = 12;
    
    cout << "La direccion en n es : " << &n  <<endl;
    
    cout << "El valor de n es : " << n<<endl;
    cuadrado(n);
    cout << "Cuadrado de n2: "<< n << endl;
    cout << "Cambio visto en n:"<< n << endl;

    return 0;
}
