#include <iostream>
#include <csignal>
 
using namespace std;

bool bandera = 0;
//funcion que hace el anejo de errores
void manejador(int sig){
    bandera = 1;
}

int main(){
    //estableciendo manejador
    signal(SIGABRT, manejador);
    
    raise(SIGABRT);//lanzando señal de ABORT
    if (bandera){
        cout << "Hola"<<endl;
    }else{
        cout << "No se manejo la señal"<<endl;
    }
    return 0;
}