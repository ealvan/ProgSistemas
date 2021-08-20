#include <iostream>
#include "biblioteca.cpp"
using namespace std;

int main(){
    Sala s1 = Sala("Sala A",8,12,true);    
    Sala s2 = Sala("Sala A",18,20,false);
    Sala s3 = Sala("Sala A",12,15,true);
    //los foros maximos
    int foro[] = {200, 50, 100, 150};
    //cantidad de salas
    Sala salas[] = {s1, s2, s3};
    //recorremos cada foro
    for(int i = 0; i < sizeof(foro)/sizeof(foro[0]); i++){
        int foroDelEvento = foro[i];
        //recorremos cada sala
        cout << "Evento "<<(i+1)<<": "<<foro[i]<<endl;
        for(int j = 0; j < 3; j++){
            //si se puede hacer el evento en una sala
            //por su capacidad
            if(foroDelEvento <= salas[i].obtenerCapacidad()){
                //mostramos datos
                salas[i].displayDatos();
                cout << endl;
            }
        }
    }
    return 0;
}   