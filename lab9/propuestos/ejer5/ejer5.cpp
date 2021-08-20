#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
using namespace std;
// DEFINICIONES ...
struct Persona{
    char nombre[50];
    char direccion[50];
    char tlf[20];
    char email[40];
    short int dia;
    short int mes;
    short int anio;
};


//mostrar todos los datos de una persona(pregunte al usuario por name)
void display(Persona p){
    cout << "Nombre : "<<p.nombre << endl
    << "Direccion : "<< p.direccion << endl
    << "Telefono : "<<p.tlf << endl
    << "Email : "<< p.email << endl
    << "Fecha de nacimiento : "  
    << p.anio <<" / "<< p.mes 
    << " / "<< p.dia << endl;
}
//si el file existe!
bool exist(char fileName[]) {
    FILE *fp = fopen(fileName, "r");
    if (fp) {
        fclose(fp);
        return true;
    }
    return errno != ENOENT;
}
// max capacidad de la agenada 100;
const short int capacidad = 100;

void escribirDatos(string filename, Persona agenda[capacidad]){
    fstream file;
    file.open(filename, ios::out | ios::binary);
    if(file.is_open()){
        file.write(reinterpret_cast<char*>(agenda), capacidad*sizeof(Persona));
        file.close();
    }else{
        cout << "No puedo a abrir el "<<filename << "file";
    }
}

void printData(Persona agenda[capacidad], int foro){
    cout << "Cantidad actual de personas : "<<foro << " personas"<<endl;
    for(int i = 0; i < foro; i++){
        display(agenda[i]);
        cout << "------------------"<<endl;
    }
}
auto leerDatos(string filename, Persona agenda[capacidad]){
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if(file.is_open()){
        file.read(reinterpret_cast<char*>(agenda), capacidad*sizeof(Persona));
        file.close();
    }else{
        cout << "No puedo a abrir el "<<filename << "file";
    }

    return agenda;
}


void saveAgenda(Persona &ptr, string nom,string dir, string tlf, string mail,int anio,int mes, int dia){
    sprintf(ptr.nombre,"%s", nom.c_str());
    sprintf(ptr.direccion,"%s",dir.c_str());
    sprintf(ptr.tlf,"%s",tlf.c_str());
    sprintf(ptr.email,"%s",mail.c_str());
    ptr.anio = anio;
    ptr.mes = mes;
    ptr.dia = dia;
}
//visualizar los nombres de las fichas existentes
void inputPersona(Persona& person){
    cout << "Añadir una nueva persona: "<<endl;
    string name, dir, tlf, email;
    int dia, mes, anio;    
    cin.ignore();
    
    cout << "Nombre : ";
    getline(cin, name);
    cout << "Direccion : ";
    getline(cin, dir);
    cout << "Telefono : ";
    getline(cin, tlf);
    cout << "Email : ";
    getline(cin, email);
    cout << "Ingrese Fecha de Nacimiento por espacios( Año Mes Dia ) : ";    
    cin >> anio >> mes >> dia;

    saveAgenda(person, name,dir,tlf,email, anio, mes, dia);

    cin.ignore();

}

//añadir un dato nuevo
void addPersona(Persona&ptr, int& cantActual){
    if(cantActual >= 100){
        cout << "Tu agenda esta llena, no podemos agregar mas contactos";
        return;
    }
    //se da por entedido que se agregara una persona
    inputPersona(ptr);
    ++cantActual;
}
void displayMenu(){
    int size = 4;
    string menu[size]= {
        "opcion 1) añadir un dato nuevo",
        "opcion 2) visualizar los nombres de las fichas existentes",
        "opcion 3) mostrar todos los datos de una persona ",
        "opcion 4) Salir",
    };
    for(string* ptr = menu; ptr <= &menu[size-1]; ptr ++){
        cout << *ptr << endl;
    }
    cout << "Ingrese opcion: ";
}
void buscarData(string name, Persona agenda[capacidad], int foro){
    int flag  = 0;
    for(int i =0; i < foro; i++){
        if(agenda[i].nombre == name){
            cout << "Datos de las persona buscada : " << endl;
            display(agenda[i]);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "No encontramos el nombre de esa persona en la agenda"<<endl;
    }

}
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

void updateForo(string filename,int foro){
    fstream file;
    file.open(filename, ios::out | ios::binary);
    if(file.is_open()){
        file.write((char*)&foro, sizeof(foro));
    }else{
        cout << "ERROR\n";
    }
}
int retrieveForo(string filename){
    fstream file;
    int foro;
    file.open(filename, ios::in | ios::binary);
    if(file.is_open()){
        file.read((char*)&foro, sizeof(foro));
        file.close();
    }else{
        cout << "ERROR\n";
    }
    return foro;

}
void display(Persona* ptr, int foro){
    cout << "AGENDA : Tienes "<<foro << " contactos en la agenda"<<endl;
    for(int i =0; i < foro; i++ ){
        cout << endl;
        display(*(ptr+i));
    }    
    cout <<"--------------------------"<<endl;
    
}
void wrapperAgenda(){

    int foro = 0;
    int op;
    string fileForo = "foro.dat";
    string filename = "records.dat";
    char f[]= "records.dat";
    struct Persona agenda[capacidad];
    Persona* ptr;
    do{
        cout << endl;
        displayMenu();
        cin >> op;
        switch(op){
            case 1:
            {
                //añadir nuevo en la agenda
                addPersona(agenda[foro],foro);
                escribirDatos(filename,agenda);
                updateForo(fileForo, foro);
            }
                break;
            case 2:
            {
                if(!exist(f)){
                    cout << endl;
                    cout << "La agenda esta vacia no hay nada que mostrarte"<<endl;
                }else{
                    foro = retrieveForo(fileForo);                
                    //mostrar toda la agenda
                    ptr = retrieve(filename, agenda);
                    display(ptr,foro);
                }
            }
                break;
            case 3:
            {   
                //mostrar una persona
                string name;
                cout << "Ingrese el nombre de la persona: ";
                cin >> name;
                buscarData(name, agenda, foro);
            }
                break;
            case 4:
                cout << "El programa finalizo exitosamente, tenga un buen dia!"<<endl;
                break;
            default:
                cout << "OPcion no disponible, mire el menu porfavor"<<endl;
                break;
        }

    }while(op != 4);

}



int main(){
    wrapperAgenda();
}
