/*
En unciado 
Crear un programa en C++ y leer una 
linea de un fichero usando 
ifstream y usando la funci6n getline 

*/
#include <fstream>
#include <iostream>

using namespace std;
//write texto in file
int main(){

    ifstream file;
    string frase;
    file.open("ficheroTexto.txt");
    getline(file, frase);
    file.close();
    cout << "Frase leida : "<<frase <<endl;
}
    