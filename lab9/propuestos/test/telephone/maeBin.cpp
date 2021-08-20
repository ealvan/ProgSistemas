#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct Persona{
    char nombre[40];
    char direccion[40];
    char tlf[9];
    char email[40];
    int dia;
    int mes;
    int anio;
};

int main(){
    Persona p;
    strcpy(p.nombre, "MOMBRE");
    strcpy(p.direccion, "DIRECCION");
    strcpy(p.tlf, "1telefono1");
    strcpy(p.email, "dealvin32@gmail.com");
    p.dia = 22;
    p.mes = 12;
    p.anio = 2001;
    cout << "Info de la persona "<<endl;
    cout << p.nombre << endl;
    cout << p.direccion << endl;
    cout << p.email << endl;
    cout << p.tlf << endl;
    cout <<endl<<"----------------------"<<endl;

    ofstream out;
    out.open("thedata.dat", ios::out | ios::binary );
    out.write(p.nombre, sizeof(p.nombre));
    out.write(p.direccion, sizeof(p.direccion));
    out.write(p.tlf, sizeof(p.tlf));
    out.write(p.email, sizeof(p.email));
    out.close();

    ifstream in;
    Persona p2;
    in.open("thedata.dat", ios::in | ios::binary);
    in.read((char*)&p2.nombre, sizeof(p2.nombre));
    in.read((char*)&p2.direccion, sizeof(p2.direccion));
    in.read((char*)&p2.tlf, sizeof(p2.tlf));
    in.close();
    cout << endl << "info recuperada ..."<<endl;
    cout << p2.nombre << endl;
    cout << p2.direccion << endl;
    cout << p2.tlf << endl;
    cout << p2.email << endl;
    
    
}



// ofstream out;
    // out.open("makebin.dat", ios::out | ios::binary);
    // //make struture implements
    // Persona p;
    // p.nombre = "Jose Pepe, el guarillo";
    // p.direccion = "Avenida siempre viva";
    // strcpy(p.tlf, "12332123");
    // p.anio = 2001;
    // p.mes = 12;
    // p.dia = 31;

    // out.write(reinterpret_cast<char *>(&p), sizeof(Persona));
    // out.close();

    // Persona o;
    // ifstream in;
    // in.open("makebin.dat", ios::in | ios::binary);
    // in.read(reinterpret_cast<char*>(&o), sizeof(Persona));
    
    // in.close();

    // cout << o.nombre << endl;
    // cout << o.direccion << endl;
    // cout << o.email << endl;
    // cout << o.tlf << endl;







