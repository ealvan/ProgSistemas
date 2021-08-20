#include <iostream>
#include <fstream>
using namespace std;

struct Persona{
    char nom[50];
    char dir[50];
    char email[50];
    int dia,mes,anio;
};

int main(){
    const int SIZE = 4;
    Persona agenda[SIZE] = {
        {"edsel","av!_1","eamil1@gmail.com", 11, 05, 2001},
        {"Matt","av!_2","ema2@gmail.com", 11, 05, 2001},
        {"Mateo","av!_3","ema3@gmail.com", 11, 05, 2001},
        {"Larry","av!_4","ema4@gmail.com", 11, 05, 2001},
    };
    fstream f;
    f.open("records.dat", ios::out | ios::binary);
    if(f.is_open()){
        f.write(reinterpret_cast<char*>(agenda),SIZE*sizeof(Persona));
        f.close();
    }

    Persona agenda_2[SIZE];
    f.open("records.dat", ios::in | ios::binary);
    if(f.is_open()){
        f.read(reinterpret_cast<char*>(agenda_2), SIZE *sizeof(Persona));
        f.close();
    }
    int c;
    for(Persona& item: agenda_2 ){
        if(c < 4){    
            cout << item.nom << endl;
            cout << item.dir << endl;
            cout << item.mes << endl;
            cout << item.anio <<" "<<item.mes << " "<<item.dia << endl;
            c++;
        }else{
            break;
        }
    }

}