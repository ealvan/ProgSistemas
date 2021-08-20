#include <iostream>
using namespace std;
//• Crear un programa en c++
//  que permita el ingreso por teclado la edad
//  y que muestre en pantalla dicha edad 
int main(){
    int edad;
    cout << "ingrese su edad: ";
    cin >>edad;
    if(cin.fail()){
        cout << "Solo aceptamos numeros decimales"<<endl;
        return 1;

    }
    cout << "tu edad es "<< edad<<endl;

    return 0;
}