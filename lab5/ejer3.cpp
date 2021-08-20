/*
En unciado 
Escribir un programa en C++ que permita lo siguiente:
 Pasar por argumento la direcciem de una variable
  y utilizarla dentro de la fund& para obtener 
  el cuadrado de este valor, mostrando la 
  direcci6n de esta variable y el valor
   resultado de esta funci6n 
*/
#include <iostream>

using namespace std;

int cuadrado(int);
int main(){
    int n = 12;
    cout << "El valor de n es : " << n<<endl;
    cuadrado(&n);
    cout << "Cuadrado de n2: "<< n << endl;
    cout << "Cambio visto en n"<< n << endl;

    return 0;
}
void cuadrado(int* m){
    cout << "La direcciom de m em cuadrado() es: " << m << endl;
    *m  *=   *m;
    // cout << "Valor de ptr : "<< &n<<endl;
     
    // n *=n;
    // return n;
}