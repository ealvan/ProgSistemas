#include "def.h"
void printInfoFutbol(EFutbol a, EFutbol b){
    cout << "Informacion sobre los equipos ...."<<endl;
    cout << "•	Listado de los mejores anotadores de triples de cada equipo."<<endl;
    cout << "   1. "<<a.bestJugGol<<endl;
    cout << "   2. "<<b.bestJugGol<<endl;
}
void printInfoBasket(EBasket a, EBasket b){
    cout << "Informacion sobre los equipos ...."<<endl;
    cout << "•	Listado de los mejores anotadores de triples de cada equipo."<<endl;
    cout << "   1. "<<a.bestJugTrip<<endl;
    cout << "   2. "<<b.bestJugTrip<<endl;
}
void inputGeneral(string &name, int &vi, int &der, int& miembros){
    cout << "Cuantos miembros hay en el "<<name<<" : "<<endl;
    cin >> miembros;
    cout << "Cuantas son sus victorias? : "<<endl;
    cin >> vi;
    cout << "Cuantas son sus derrotas ? : "<<endl;
    cin >> der;
    cout << endl;
};

void inputBasket(EBasket* basket){
    int size = 4;
    string strs[]={
     "• Número de pérdidas de balón : ",
     "• Número de rebotes cogidos : ",
     "• Nombre del mejor anotador de triples : ",
     "• Número de triples del mejor anotador de triples : ",
    };
    cout << strs[0];
    cin >> basket->perBal;
    cout << strs[1];
    cin >> basket->rebReg;
    cout << strs[2];
    cin >> basket->bestJugTrip;
    cout << strs[3];
    cin >> basket->numBestJugTrip;
}
void inputFulbol(EFutbol* fultbol){
    int size = 4;
    string strs[]={
        "• Número de empates : ",
        "• Número de goles a favor : ",
        "• Nombre del goleador del equipo : ",
        "• Número de goles del goleador : ",
    };
    
    cout << strs[0];
    cin >> fultbol->empates;
    cout << strs[1];
    cin >> fultbol->golesAfavor;
    cout << strs[2];
    cin >> fultbol->bestJugGol;
    cout << strs[3];
    cin >> fultbol->numJugGol;

}
//aqui usamos void pointers, los cuales
//los parseamos, para mas flexibilidad en el codigo
void inputJugadores(void* jugador, char t, int i){
    switch(t){
        case 'B':{
            ((JugadorBasket*)jugador);//my ptr cast
            cout << "Ingrese el jugador "<<i<<" : "<<endl;
            cout << "Nombre : ";
            cin >> ((JugadorBasket*)jugador) -> nombre;
            cout << "Numero de ensestadas: ";
            cin >> ((JugadorBasket*)jugador) -> nroEnsestadas;
            cout << "Nro de Camiseta: ";
            cin >> ((JugadorBasket*)jugador) -> camiseta;
            }
            break;
           
        case 'F':{
            ((JugadorFultbol*)jugador);//my ptr cast
            cout << "Ingrese el jugador "<<i<<" : "<<endl;
            cout << "Nombre : ";
            cin >> ((JugadorFultbol*)jugador)-> nombre;
            cout << "Numero de Goles: ";
            cin >> ((JugadorFultbol*)jugador) -> nroGoles;
            cout << "Nro de Camiseta: ";
            cin >> ((JugadorFultbol*)jugador) -> camiseta;
            }
            break;
        default:
            break;
    }
}
//aqui usamos void pointers, los cuales
//los parseamos, para mas flexibilidad en el codigo
void pedirJugadores(void* ptr,char t, int miembros){
    if(miembros > 15){
        cout << "Solo soportamos hasta 15 jugadores"<<endl;
        return;
    }
    switch(t){
        case 'F':
            {
                EFutbol* f = ((EFutbol*)ptr);//casteamos punteros
                JugadorFultbol* ptrPlayer = f->miembros;
                
                for(int i =0; i< miembros; i++){
                    inputJugadores((ptrPlayer+i),'F',i+1);
                }
               
            }    
            break;
        case 'B':
        {
            EBasket* b = ((EBasket*)ptr);//casteamos punteros
            JugadorBasket* ptrGamerB = b->miembros;
            for(int i =0; i < miembros; i++){
                inputJugadores((ptrGamerB+i),'B',i+1);
            }
           
        }
            break;
    }
}

void inputSwitch(int &op){
    struct EBasket eBasket;
    struct EBasket eBasket1;
    struct EFutbol eFutbol;
    struct EFutbol eFutbol1;

    cout << "De que equipo deseas ingresar informacion? :"
    <<"\n (1) Basket\n (2) Fulbol \n (3) Salir"<<endl;
    cin >> op;

    do{
        
        switch(op){
            //las llaves en los case's
            //son para que las variables 
            //no salten entre caso
            //y caso, de tal forma que se queden en ese bloque
            case 1:
                {
                    inputGeneral(
                        eBasket.general.nombre,
                        eBasket.general.victorias,
                        eBasket.general.derrotas,
                        eBasket.general.miembros);
                    EBasket* ptr1 = &eBasket;
                    inputBasket(ptr1);
                    pedirJugadores(ptr1,'B',eBasket.general.miembros);
                    if(eBasket.general.miembros < 15){
                        eBasket.display();
                    }
                    inputGeneral(
                        eBasket1.general.nombre,
                        eBasket1.general.victorias,
                        eBasket1.general.derrotas,
                        eBasket1.general.miembros
                    );
                    EBasket* ptr2 = &eBasket1;
                    inputBasket(ptr2);
                    pedirJugadores(ptr2, 'B', eBasket1.general.miembros);
                    if(eBasket1.general.miembros < 15){
                        eBasket1.display();
                    }
                    printInfoBasket(eBasket1,eBasket);
                    
                    cout << "EL GANADOR es : "<<endl;
                    if(eBasket1.puntos() > eBasket.puntos()){
                        cout << "El SEGUNDO EQUIPO"<<endl;
                    }else{
                        cout << "El PRIMER EQUIPO"<<endl;
                    }
                }
                break;
            case 2:
                {
                    inputGeneral(
                        eFutbol.general.nombre,
                        eFutbol.general.victorias,
                        eFutbol.general.derrotas,
                        eFutbol.general.miembros);
                    EFutbol* ptr2 = &eFutbol;
                    inputFulbol(ptr2);
                    
                    pedirJugadores(ptr2,'F',eFutbol.general.miembros);
                    if(eFutbol.general.miembros < 15){
                        eFutbol.display();
                    }
                    inputGeneral(
                        eFutbol1.general.nombre,
                        eFutbol1.general.victorias,
                        eFutbol1.general.derrotas,
                        eFutbol1.general.miembros  
                    );
                    EFutbol* ptr3 = &eFutbol1;
                    inputFulbol(ptr3);
                    pedirJugadores(ptr3,'F',eFutbol1.general.miembros);
                    printInfoFutbol(eFutbol1,eFutbol);

                    if(eFutbol1.general.miembros < 15){
                        eFutbol1.display();
                    }
                    cout << "EL GANADOR es  : "<<endl;
                    if(eFutbol1.puntos() > eFutbol.puntos()){
                        cout << "El SEGUNDO EQUIPO"<<endl;
                    }else{
                        cout << "El PRIMER EQUIPO"<<endl;
                    }
                }
                break;
            case 3:
                cout << "Salio del programa con exito, tenga un buen dia!"<<endl;
                break;
            default:
                cout << "Los sentimos, solo aceptamos 1 y 2 como opciones permitidas"<<endl;
        }
        
    }while(op != 3 );

}
