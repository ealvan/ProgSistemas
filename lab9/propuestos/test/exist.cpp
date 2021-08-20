#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    fstream f;
    f.open("ejer1_1.dat", ios::in | ios::out);
    f << "Hola ";
    f.seekg(0, ios::end);  
    if (f.tellg() == 0) {    
        cout << "El archivo esta vacio "<<endl;
    }else{
        cout << "El archivo NO esta vacio"<<endl;
    }
    f.close();
}