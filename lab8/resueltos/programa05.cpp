/*
Crear un programa en C++ que pudiera leer cualquier archivo
 indicado por el usuario y lo mostrara por pantalla, en caso 
de no existir dicho archivo mostrar 
el mensaje "Fichero inexistente o faltan permisos pars abrirlo" 
*/
#include <fstream>
#include <iostream>

using namespace std;
/*
 Crear un archivo en C++ que permita leer
 las limas del archivo ,'prueba.txt" creado
 en el ejercicio anterior utilizando la funcion ifstream 
*/ 
int main(){
    ifstream file;

    file.open("test.txt");
    string line;
    file >> line;
    cout << "Se ha leido : "<< endl;
    cout << line << endl;

    file.close();

    return 0;
}