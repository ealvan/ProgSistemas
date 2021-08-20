/*
• Crear un programa en c++ que permita la yisualizacion
 y use de un menu con seis opciones:
  "Ingreso",
  "Modificacion",
   "Consultas", 
   "Reportes",
    "Utilidades" 
    y "Salir", 
en cada uno mostrar un mensaje correspondientp 


*/

#include <iostream>
using namespace std;

 
int main(){

    string arr[]={
        "1. Ingreso",
        "2. Modificacion",
        "3. Consultas", 
        "4.Reportes",
        "5. Utilidades" ,
        "0. Salir"
    };
    int op;
    cout << arr[0]<<endl;
    cout << arr[1]<<endl;
    cout << arr[2]<<endl;
    cout << arr[3]<<endl;
    cout << arr[4]<<endl;
    cout << arr[5]<<endl;
    
    cout << "Ingrese una opcion: ";
    cin >> op;
    switch(op){
        case 1:
            cout << "Usted tiene 2500 s/"<<endl;
            break;
        case 2:
            cout << "No se puede modifcar nada"<<endl;
            break;      
        case 3:
            cout << "Usted no rpesenta consultas"<<endl;
            break;  
        case 4:
            cout << "Usted no rpesenta reportes"<<endl;
            break; 
        case 5:    
            cout << "Este servicio esta bloqueado por el momento"<<endl;
            break; 
        default:
            cout << "Nose reconoce opcion ..."<<endl;
        
    }

    return 0;
}