#include <iostream>
using namespace std;
//stack 
//en el bloque try, c++
//busca si hay una excepttion que se ha lanzado, si no hay busca en las funciones
//que esten dentro del bloque try, y si sucesiavmente
//hasta encontrar o no unn exception
//el orden en en que son creados los objetos
//se destruyen en ese orden
//luego de lanzar la excepcion, es la pila
void func(){
    throw 12;
}
int main(){

    try{
        func();
    }catch(int e){
        cout << e << endl;
    }
}