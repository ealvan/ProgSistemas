#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip>
#include <tuple>
using namespace std;
struct JugadorBasket{
    string nombre;
    int camiseta;
    int nroEnsestadas;
    void display(){
        cout <<
        "Nombre : "<< nombre <<"\t"<<
        "Nro Camiseta: "<< camiseta <<"\t"<<
        "Nro de ensestadas: " << nroEnsestadas << endl;
    }
    
};
struct JugadorFultbol{
    string nombre;
    int camiseta;
    int nroGoles;
    void display(){
        cout <<
        "Nombre : "<<nombre<<"  "<<
        "Nro Camiseta: "<<camiseta<<"  "<<
        "Nro de goles: "<<nroGoles<<endl;
    }
};
struct Equipo{
    string nombre;
    int victorias;
    int derrotas;
    int miembros;

    void display(){
        cout << endl<<"Info general de Equipo : "<<endl;
        cout << "Nombre: "<<nombre<<endl
        << "Nro Victorias: "<<victorias<<endl
        << "Nro Derrotas: "<< derrotas<<endl
        << "Nro de miembros: "<< miembros<<endl;
    }
    
};


struct EBasket{
    int perBal;
    int rebReg;
    string bestJugTrip;
    int numBestJugTrip;
    Equipo general;
    JugadorBasket miembros[15];
    //maximo de 15 jugadores, entre suplentes
    //y oficiales
    int puntos(){
        int p = 3*perBal + rebReg;
        return p;
    }
    void display(){
        general.display();
        cout 
        << "• Número de pérdidas de balón : "<<perBal<<endl
        << "• Número de rebotes cogidos : "<<rebReg<<endl
        << "• Nombre del mejor anotador de triples : "<< bestJugTrip<<endl
        << "• Número de triples del mejor anotador de triples : "<< numBestJugTrip<<endl;
        cout <<"Lista de Jugadores : "<<endl;
        displayMiembros();
    }
    void displayMiembros(){
        for(int i =0; i < general.miembros; i++){
            miembros[i].display();
        }
        cout << endl;
    }
    
};
struct EFutbol{
    int empates;
    int golesAfavor;
    string bestJugGol;
    int numJugGol;
    Equipo general;
    JugadorFultbol miembros[15];
    //maximo de 15 jugadores, entre suplentes
    //y oficiales
    int puntos(){
        int p = 3*golesAfavor + empates;
        return p;
    }
    void display(){
        general.display();
        cout 
        << "• Número de empates : "<<empates<<endl
        << "• Número de goles a favor : "<<golesAfavor<<endl
        << "• Nombre del goleador del equipo : "<< bestJugGol<<endl
        << "• Número de goles del goleador : "<< numJugGol<<endl;
        cout <<"Lista de Jugadores : "<<endl;
        displayMiembros();
    }
    void displayMiembros(){
        for(int i =0; i < general.miembros; i++){
            miembros[i].display();
        }
        cout << endl;
    }
    
};