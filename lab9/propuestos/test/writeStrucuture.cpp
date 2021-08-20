#include <iostream>
#include <fstream>

using namespace std;
struct Persona{
    string nombre;
    short int dia;
};
void writeData(ofstream & out, Persona* one){
    unsigned size = one->nombre.size();
    out.write((char*)&size, sizeof(size));
    out.write(one->nombre.data(), size);
    out.write((char*)&one->dia, sizeof(one->dia));
}
void readData(ifstream & in, Persona* one){
    size_t nameSize =0;
    in >> nameSize;
    one->nombre.resize(nameSize);
    in.read(&one->nombre[0], nameSize);
    in >> one->dia;
}
int main(){
    Persona p = {"nombre", 12};
    ofstream file;
    file.open("struct.dat", ios::out | ios::binary);
    if(!file){
        cerr << "Error de files"<<endl;
        return 0;
    }
    writeData(file, &p);
    file.close();

    ifstream ifile;
    ifile.open("struct.dat", ios::in | ios::binary);
    
    Persona in;
    readData(ifile, &in); 
    cout << "Nombre: "<<in.nombre << endl;
    cout << "Dia : "<<in.dia << endl;
    ifile.close();
}