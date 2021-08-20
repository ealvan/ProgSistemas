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
Utilizando un programa en G++, 
crear un archivo que escriba las frases: 
"Esto es una linea",
 en otra linea escribir: 
"Esto es otra" y
 finalmente escribir: " y
 esto es continuacion de la anterior"
 en un archivo Ilamado "prueba.txt" 
*/ 
int main(){
    ofstream file;
    file << "Esto es una linea "<<endl;
    file << "Esto es otra"<<endl;
    file << "Esto es ña continuacion de la linea"<<endl;
    file.close();

    return 0;
}