#include <iostream>

using namespace std;

/*
Crear un programa en C++ para mostrar 
a una variable, con el valor de 20,
 la direcci6n en memoria que esta variable ocupa 
*/
void alumnos();
int main(){
    alumnos();
    return 0;
}
void alumnos(){
    int var = 20;
    int *ptr;
    ptr = &var;
    cout << "Valor de var : "<< var<<endl;
    cout << "Valor de ptr : "<< ptr<<endl;
    cout << "Valor de *ptr : "<< *ptr <<endl;

}