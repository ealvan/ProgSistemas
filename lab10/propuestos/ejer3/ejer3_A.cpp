/*
Para los siguientes casos, proponer y explicar dos ejemplos en C++
considerando:
    a)	Excepciones provocadas por asignación de 
        memoria insuficiente (generadas por el operador new).
*/
#include <iostream>

using namespace std;

int main(){
    int big = 0;
    cout << "INgrese numero grande: ";
    cin>> big;
    try{
        int* array = new int[big];
        delete[]array;
    }
    catch(bad_alloc& e){
        //Asegurando las excepciones en las asignaciones de memoria
        cout << "Memoria Insuficiente" << endl;
        cout << "ERROR: "<<e.what() << endl;
    }catch(...){
        cout << "Exception Inesperada "<<endl;
    }
}