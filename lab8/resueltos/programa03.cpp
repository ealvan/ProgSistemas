/*
Crear un programa en C++ que pudiera leer cualquier archivo
 indicado por el usuario y lo mostrara por pantalla, en caso 
de no existir dicho archivo mostrar 
el mensaje "Fichero inexistente o faltan permisos pars abrirlo" 
*/
#include <fstream>
#include <iostream>

using namespace std;
//write texto in file
int main(){

    fstream file;
    string name,frase;
    cout << "Write your file input: ";
    getline(cin, name);
    
    file.open(name.c_str());
    if(file.is_open()){
        while(!file.eof()){
            getline(file, frase);
            cout << "Leido : "<< frase << endl; 
        }
        file.close();
    }else{
        cout << "No se puede abrir el archivo ! o faltan permisos para abrirlo"<<endl;
    }
    return 0;
}