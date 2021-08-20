#include <iostream>
#include <fstream>

using namespace std;
struct Persona{
    char nombre[50];
    char direccion[50];
    char tlf[20];
    char email[40];
    short int dia;
    short int mes;
    short int anio;
};

Persona* retrieve(string filename, Persona agenda[100]){
    fstream file;
    file.open(filename, ios::in | ios::binary);
    
    if(file.is_open()){
        file.read(reinterpret_cast<char*>(agenda), 100*sizeof(Persona));
        file.close();
    }else{
        cout << "ERROR\n";
    }
    return agenda;
}
void display(Persona* ptr, int foro){
    for(int i =0; i < foro; i++ ){
        cout << (ptr+i)->nombre << endl;
        cout << (ptr+i)->direccion << endl;
        cout << (ptr+i)->tlf << endl;
        cout << (ptr+i)->email << endl;
    }    
}
int main(){
    fstream file;
    const int size = 100;
    Persona agenda[size];
    int foro = 3;
    Persona* ptr = retrieve("records.dat", agenda );
    display(ptr, foro);
}