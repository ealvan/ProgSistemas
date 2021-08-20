#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //crea una programa leer toda una linea del archivo cuyo nombre es ingresado
    string filename;
    cout << "Dime el nombre del fichero: ";
    getline(cin, filename);

    ifstream file(filename.c_str());
    string linea;

    getline(file,linea);
    cout << "Se ha leido : "<<endl;
    cout << linea << endl;

    file.close();

    return 0;
    

}