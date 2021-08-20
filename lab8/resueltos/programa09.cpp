#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char datos[0];
    string nombre;
    char datos[40];
    int compresion;

    cout << "Comprobador de imagenes BMP: ";
    cout << "Dime el nombre del fichero: ";
    getline(cin, nombre);

    ifstream fichero(nombre.c_str(), ifstream::binary);

    if(fichero.fail()){
        cout << "Not find file"<<endl;
    }else{
        fichero.seekg(30,fichero.beg);
        fichero.read(datos,1);
        fichero.close();

        compresion = datos[0];
        if(compresion == 0){
            cout << "sin comrpesion";
        }else{
            cout << "BMP comprimido";
        }
    }
    return 0;
}