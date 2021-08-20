/*
• Crear un programa en c++ que permita
 el ingreso de dos numeros y que los 
 sume utilizando las funciones cout y cin,
  ademas muestre el resultado, 
  no utilizar operadores "::" 
*/
#include <iostream>
using namespace std;

int main(){

    int a,b;
    cout << "Ingrese numero 1: ";
    cin >> a;
    cout << "Ingrese numero 2: ";
    cin >> b; 

    cout <<a << " + "<<b <<" = "<< (a+b)<<endl;
    return 0;
}