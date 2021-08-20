#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
//variable global
bool primerLanzamiento = true;
int lanzarDados();
int ganoOperdio_en_Primera(int intento);
bool seguimosEnelJuego(int intento);





int main(){
    int punto = 0;
    bool seguimos = true;
    int lanzamiento = lanzarDados();//primer lanzamiento
    int dec =12 ;
    while(seguimos){
        if(lanzamiento == -1){
            return 0;
        }
        if(dec != 0){
            dec = ganoOperdio_en_Primera(lanzamiento);
        }
        if(primerLanzamiento){
            if(dec == 0){
                //perdio el jugador
                cout << "Usted ha PERDIDO el juego, saco "<<lanzamiento<<endl;
                seguimos = false;
            }else if(dec == 1){
                //gano el jugador
                cout << "Usted ha GANADO! el juego, saco "<<lanzamiento<<endl;
                seguimos = false;
            }
            primerLanzamiento = false;
        }else{
            
            if(dec == -1){
                punto = lanzamiento;
                cout << "Usted aun no ha perdido, el casino marca su punto..."<<endl;
                cout <<"Su punto es: " << punto <<endl;
                lanzamiento = lanzarDados();//preguntamos si desea lanzar el dado
                dec = 0;
            }
            if(seguimosEnelJuego(lanzamiento)){
                //sqguimos si nos sale cualquier nuemro
                //menos el 7
                if(dec == 0 && punto != 0){
                    if(lanzamiento == punto){
                        cout << "Usted ha ganado! :) el juego, saco "<<lanzamiento<<endl;
                        cout <<"y su punto es: " << punto <<endl;
                        seguimos = false;
                    }else{
                        lanzamiento = lanzarDados(); 
                    }
                }
            }else if(lanzamiento == 7){
                //perdemos pues nos salio un 7
                cout << "Usted ha perdido :( el juego, saco "<< lanzamiento <<endl;
                seguimos = false;
            }
        }   
    }
    cout << "Tenga un buen dia!!!"<<endl;
    return 0;
}
//retorna la suma de dados
int lanzarDados(){
    srand(time(0));
    int dado1 = rand()%6+1;
    int dado2 = rand()%6+1;
    string dec;
    cout << "Desea hacer su tirada Si(S)/No(N): ";
    cin >> dec;
    int suma = dado1+dado2;
    cout << "Su tirada es: "<< suma<<endl;
    
    return (dec == "S" || dec == "s")?(suma):-1;
}
int ganoOperdio_en_Primera(int intento){
    switch (intento){
    case 2:
    case 3:
    case 12:
        return 0;//perdio el jugador
    case 7:
    case 11:
        return 1;//gano el jugador
    }
    return -1;//seguimos en el juego
}
//seguimos intentando hasta que nos salga
// un 7 o el "punto"
bool seguimosEnelJuego(int intento){
    switch (intento){
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
        return true;
    case 7:
        return false;
    default:
        return true;
    }
}
