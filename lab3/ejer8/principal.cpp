#include "biblioteca.h"
int main(){
    Alumnos obj1;
    obj1.id = 7;
    int i =0;

    while( i < 5 ){
        Alumnos obj2;
        obj2.id = i;
        i++;
        //cuando se llama un obj, y termina su vida, existe
        //un plan para que haga una ultima cosa a la hora de su muerte
    }//el alcance de obj2 , finaliza aqui

    return 0;
}//el alcance de obj1 , finaliza aqui