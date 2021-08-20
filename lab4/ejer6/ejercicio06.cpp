/*
Ejercicios 
• Crear un programa en C++ que muestre
 un menu con 4 opciones: 
 "Fundcion 1", 
 "Funicion 2", 
 "Funcion 3" 
 , "Fundcion 4",
  cada una debe implementar una fund& que muestre el mensaje: "Fund& X"
   donde X es el n6mero de funci6n: 
*/
#include <iostream>
using namespace std;

void funcion1();
void funcion2();
void funcion3();
void funcion4();


 
int main(){

    string arr[]={
        "Fundcion 1", 
        "Funicion 2", 
        "Funcion 3" ,
        "Funcion 4",};
    int op;
    bool repetir = true;

    do{
        cout << arr[0]<<endl;
        cout << arr[1]<<endl;
        cout << arr[2]<<endl;
        cout << arr[3]<<endl;
        
        cout << "Elija una opcion : ";
        cin >> op;
        switch(op){
            case 1:
                funcion1();
                break;
            case 2:
                funcion2();
                break;      
            case 3:
                funcion3();
                break;  
            case 4:
                funcion4();
                break; 
            case 0: 
                repetir = false;
                break; 
            default:
                cout << "Tomaste opcion equivocada "<<endl; 
        }
    }while(repetir);
    return 0;
}
void funcion1(){
    cout << "Funcion 1"<<endl;
}
void funcion2(){
    cout << "Funcion 2"<<endl;
}
void funcion3(){
    cout << "Funcion 3"<<endl;
}
void funcion4(){
    cout << "Funcion 4"<<endl;
}