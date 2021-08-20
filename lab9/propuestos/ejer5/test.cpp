#include <iostream>
#include <fstream>
using namespace std;
// DEFINIOCIONES ...
struct Persona{
    string nombre;
    string direccion;
    char tlf[9];
    char email[256];
    short int dia;
    short int mes;
    short int anio;
    void getData(){
        cout << "Añadir una nueva persona: "<<endl;
        cout << "Nombre : ";
        getline(cin, nombre);
        cout << "Direccion : ";
        getline(cin, direccion);
        cout << "Telefono : ";
        cin >> tlf;
        
        cout << "Email : ";
        cin >> email;
        cout << "Ingrese Fecha de Nacimiento por espacios( Año Mes Dia ) : ";    
        cin >> anio >> mes >> dia;
    }
    void display(){
        cout << "Nombre : "<<nombre << endl
        << "Direccion : "<< direccion << endl
        << "Telefono : "<<tlf << endl
        << "Email : "<< email << endl
        << "Fecha de nacimiento : "  
        << anio <<" / "<< mes 
        << " / "<< dia << endl;
    }
};

int main(){
//     Persona agenda[100]={
//         {"A","av_1",'d','d', 12,12,12},
//         {"A","av_1",'d','d', 12,12,12},
//         {"A","av_1",'d','d', 12,12,12},
//         {"A","av_1",'d','d', 12,12,12},
//    };

    Persona p={"asa","asa","asa",'a',12,12,12};

    ofstream file;
    file.open("data.dat");
    if(file.is_open()){
        file.write((char*)&p, sizeof(file));   
        file.close();
    }
    ifstream infile;
    infile.open("data.dat");
    Persona outp;
    if(infile.is_open()){
        infile.read((char*)&outp, sizeof(outp));
        outp.display();
        infile.close();
    }











}
