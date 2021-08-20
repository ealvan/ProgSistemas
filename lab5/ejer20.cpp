#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //crear un programa que
    //use new para el valor ingresado por teclado
    //luego borrarlo
    int *a = new (int);
    cin >> *a;
    cout << endl << "El valor ingresado es : " << *a << endl;
    delete(a);

}