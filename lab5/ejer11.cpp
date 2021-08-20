/*
Crear un programa en c++ 
que muestre que un arreglo 
no necesariamente es lo 
mismo que un puntero y 
representa su diferencia 
*/


#include <iostream>

using namespace std;

int main(){
    int arr[] = {10,12,21,212,2121};
    int* ptr = arr;

    cout << sizeof(arr)<< endl;
    cout << sizeof(ptr)<< endl;
}