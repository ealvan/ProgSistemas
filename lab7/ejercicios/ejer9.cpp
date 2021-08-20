#include <iostream>

using namespace std;

struct Persona {
        char nombre[15];
        char apellido[15];
        int edad;
        char sexo{15};
        int telefono;       
    };


int main(){
    //no es anonima la estructura
    Persona amigos[5];
    for(int i =0; i < 5; i++){
        cout << "Ingrese su : ";
        cin >> amigos[i].nombre;
        cout << "Ingrese su : ";
        cin >> amigos[i].apellido;
        cout << "Ingrese su : ";
        cin >> amigos[i].edad;
        cout << "Ingrese su : ";
        cin >> amigos[i].sexo;
        cout << "Ingrese su : ";
        cin >> amigos[i].telefono;

        cout << endl;
    }
    cout << "El registro de las personas registradas son : "<<endl;
    for(int i =0; i< 5; i++){
        cout << " "<<amigos[i].nombre;
        cout << " "<<amigos[i].apellido;
        cout << " "<<amigos[i].edad;
        cout << " "<<amigos[i].sexo;
        cout << " "<<amigos[i].telefono<<endl<<endl;;
    }
    return 0;
}