/*
cout << "Usted no rpesenta utilidades"<<endl;
• Crear un programa en C++ que permita la visualizacion
 de un menu de cuatro opciones: 
 "Opcion 1", 
 "Option 2",
  "Option 3" 
  , "Opcion 4"
 consecutivamente hasta que se seleccione la opcion "SALIR". Nor 
*/

#include <iostream>
using namespace std;

 
int main(){

    string arr[]={"Opcion 1",
    "Opcion 2",
    "Opcion 3", 
    "Opcion 4",
    "Opcion 5" ,
    "Opcion 0"};
    int op;
    bool repetir = true;

    do{
        cout << arr[0]<<endl;
        cout << arr[1]<<endl;
        cout << arr[2]<<endl;
        cout << arr[3]<<endl;
        cout << arr[4]<<endl;
        cout << arr[5]<<endl;
        cout << "Elija una opcion : ";
        cin >> op;
        switch(op){
            case 1:
                cout << "Tomaste la "<< arr[0]<<endl;
                break;
            case 2:
                cout << "Tomaste la "<< arr[1]<<endl;
                break;      
            case 3:
                cout << "Tomaste la "<< arr[2]<<endl;
                break;  
            case 4:
                cout << "Tomaste la "<< arr[3]<<endl;
                break; 
            case 5:    
                cout << "Tomaste la "<< arr[4]<<endl;
                repetir = false;
                break; 
            default:
                cout << "Tomaste la "<< arr[5]<<endl;
            
        }
    }while(repetir);
    return 0;
}