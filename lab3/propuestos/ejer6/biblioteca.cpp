#include <iostream>
#include <string>
using namespace std;
class Candado{
    private:
        int claves[3];//tres llaves son con las que se incializa el candado
        int estadoActual[3];//estos son los del usuario
        //cada vez qeu altere el estado actual de las rueditas de la maleta
    public:
        Candado(int keys[]){
            //inicializamos el array
            for(int i =0; i<3; i++){
                claves[i] = keys[i];
                //al principio, el estado actual es de cero en
                //cada ruedita de la maleta
                estadoActual[i] = 0;
            }
        }
        //index, lugar del array, value el valor
        void alterarDigito(int index, int value){
            //si no cumple con ninguna de las condiciones
            //dadas por el candado
            if(index < 0 || index > 10 || value > 9 || value < 0){
                return;
            }
            //alterar el el digito
            estadoActual[index] = value;
        }
        bool puedeAbrir(){
            //si alguna clave es diferente a otra
            for(int i =0; i< 3; i++){
                if(estadoActual[i] != claves[i]){
                    return false;//tretornamos false
                }
            }
            //retornamos true si todo es igual
            return true;
        }
        bool mismaCombinacionActual(Candado candado){
            //dado un candado, verificamos si
            //cada digito de el estado actual de un candado
            //es igual al otro candado
            for(int i =0; i< 3; i++){
                if(candado.estadoActual[i] != estadoActual[i]){
                    return false;//si alguno es diferente
                }
            }
            //Si todo es igual
            return true;
        }
};