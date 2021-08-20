/*
Crea un programa en C++ que 
permita utilizar un arreglo 
para ser asignado a una 
variable puntero 
*/

#include <iostream>

using namespace std;
int main(){
    int array[3] = {1,2,3};
    int* ptr = array;
    cout << ptr[0]<<endl;
    cout << ptr[1]<<endl;
    cout << ptr[2]<<endl;
    
}