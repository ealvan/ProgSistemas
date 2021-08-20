#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Dato{
        string nombre;
        string apellidos;
        int edad;
        float salario;
};

int main(){
    Dato datos;
    datos.nombre = "nombre!";
    datos.apellidos = "Apellido!";
    datos.edad = 32;
    datos.salario = 1232.32;
    ofstream filew;
    filew.open("datos.dat");
    if(!filew){
        cout << "NO se pudeo abrir "<<endl;
    }
    filew.write((char*)&datos, sizeof(datos));

    
    ifstream arch("datos.dat");
    if(!arch){
        cout << "No se puede abrir el archivo"<<endl;
        return 0;
    }
    Dato eldato;
    while(arch){
        arch.read((char*)&eldato, sizeof(eldato));
    }

    cout << "La ultima lectura produjo :"<<arch.gcount()<<" carfacteres"<<endl;
    cout << "Pero no logro leer "<<sizeof(datos)<<endl;
    cout << eldato.nombre << endl;
    cout << eldato.apellidos << endl;
    cout << eldato.edad << endl;
    cout << eldato.salario << endl;
    
}