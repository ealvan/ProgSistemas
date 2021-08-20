
#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip>
#include <tuple>
using namespace std;
//implementacion de estrucutras 
struct JugadorBasket{
    string nombre;
    int camiseta;
    void display(){
        cout <<
        "Nombre : "<<nombre<<"\t"<<
        "Nro Camiseta: "<<camiseta<<endl;
    }
};
struct JugadorFultbol{
    string nombre;
    int camiseta;
    void display(){
        cout <<
        "Nombre : "<<nombre<<"\t"<<
        "Nro Camiseta: "<<camiseta<<endl;
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
    void display(){
        general.display();
        cout 
        << "• Número de pérdidas de balón : "<<perBal<<endl
        << "• Número de rebotes cogidos : "<<rebReg<<endl
        << "• Nombre del mejor anotador de triples : "<< bestJugTrip<<endl
        << "• Número de triples del mejor anotador de triples : "<< numBestJugTrip<<endl;
        cout << endl<<"Lista de Jugadores : "<<endl;
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
    void display(){
        general.display();
        cout 
        << "• Número de empates : "<<empates<<endl
        << "• Número de goles a favor : "<<golesAfavor<<endl
        << "• Nombre del goleador del equipo : "<< bestJugGol<<endl
        << "• Número de goles del goleador : "<< numJugGol<<endl;
        cout << endl<<"Lista de Jugadores : "<<endl;
        displayMiembros();
    }
    void displayMiembros(){
        for(int i =0; i < general.miembros; i++){
            miembros[i].display();
        }
        cout << endl;
    }
};
