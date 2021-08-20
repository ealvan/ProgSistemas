#include <fstream>
#include <iostream>

using namespace std;
//write texto in file
int main(){

    ofstream file;
    file.open("ficheroTexto.txt");
    bool a = file.is_open();
    if(!file.is_open()){
        cout << "No se pudo abrir "<<endl;
    }else{
        file << "Texto para el fichero";
        cout << "Created file text succesfully"<<endl;
    }
    file.close();

}
    
    