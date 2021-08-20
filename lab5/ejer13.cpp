
/*
crear unprograma
que muestre el primer 
elemento de una rreglo
a traves de un puntero
*/
#include <iostream>
using namespace std;

int main(){
    int arr[] ={10, 20, 30};
    int* p = arr;
    cout << "El rpimer puntero es : "<< (*p )<< endl;
    cout << "Valor del arreglo : "<< arr << endl;

}