/*
Crear un programa en C++ donde
 la variable puntero ptr reciba 
 un arreglo y se comporte como 
 un arreglo al ser recorrido 
 sin ser declarado como arreglo 

*/

#include <iostream>

using namespace std;
int main(){
    int arr[] = {1,2,3,4};
    int* ptr = arr;
    for(;ptr <= &arr[sizeof(arr)/sizeof(arr[0])-1]; ptr++){
        cout << *ptr << endl;
    }
}
