#include "def.h"
//input general de un equipo general
void inputGeneral(string &name, int &vi, int &der, int& miembros){
    cout << "Cuantos miembros hay en el "<<name<<" : "<<endl;
    cin >> miembros;
    cout << "Cuantas son sus victorias? : "<<endl;
    cin >> vi;
    cout << "Cuantas son sus derrotas ? : "<<endl;
    cin >> der;
    cout << endl;
};
//input basket, expecializado para los de basket
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
//input futbol, expecializado para los de futbol
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
//input de jugadores de FUTLBOL del equipo
void inputJugadores(void* jugador, char t, int i){
    switch(t){
        case 'B':{
            ((JugadorBasket*)jugador);//my ptr cast
            cout << "Ingrese el jugador "<<i<<" : "<<endl;
            cout << "Nombre : ";
            cin >> ((JugadorBasket*)jugador) -> nombre;
            cout << "Nro de Camiseta: ";
            cin >> ((JugadorBasket*)jugador) -> camiseta;
            }
            break;
           
        case 'F':{
            ((JugadorBasket*)jugador);//my ptr cast
            cout << "Ingrese el jugador "<<i<<" : "<<endl;
            cout << "Nombre : ";
            cin >> ((JugadorBasket*)jugador)-> nombre;
            cout << "Nro de Camiseta: ";
            cin >> ((JugadorBasket*)jugador) -> camiseta;
            }
            break;
        default:
            break;
    }
}
//input para los juagadores, sean de futbol o 
//de basket
void pedirJugadores(void* ptr,char t, int miembros){
    if(miembros > 15){
        cout << "Solo soportamos hasta 15 jugadores"<<endl;
        return;
    }
    switch(t){
        case 'F':{
            EFutbol* f = ((EFutbol*)ptr);
            JugadorFultbol* ptrPlayer = f->miembros;
            
            for(int i =0; i< miembros; i++){
                inputJugadores((ptrPlayer+i),'F',i+1);
            }}    
            break;
        case 'B':{
            EBasket* b = ((EBasket*)ptr);
            JugadorBasket* ptrGamerB = b->miembros;
            for(int i =0; i < miembros; i++){
                inputJugadores((ptrGamerB+i),'B',i+1);
            }}
            break;
    }
}
//funcion switch, que deacuerdo a
//tipo de equipo(Futbol o basker)
//te pregunta los datos
void inputSwitch(int &op){
    struct EBasket eBasket;
    struct EFutbol eFutbol;
    
    cout << "De que equipo deseas ingresar informacion? :"
    <<"\n (1) Basket\n (2) Fulbol \n (3) Salir"<<endl;
    cin >> op;

    switch(op){
        case 1:
        //los bloques de codigo en los cases
        //son para que las variables no salten
        //al siguiente case, es decir "jumped error"
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
            
        }
            
            break;
        case 2:{
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
            }
            break;
        case 3:
            cout << "Salio del programa con exito, tenga un buen dia!"<<endl;
            break;
        default:
            cout << "Los sentimos, solo aceptamos 1 y 2 como opciones permitidas"<<endl;
    }
}