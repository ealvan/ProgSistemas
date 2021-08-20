/*
Crear un programa en C++ que 
utiliza la referencia
 tres veces sobre un mismo valor 
*/

#include <iostream>

using namespace std;
int main(){
    int a = 12;
    int &b = a;
    int &c = b;
    c = 12;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
}