#include "def.h"


void display(Persona *p){
    cout << "Datos de la persona: "<<endl;
    p->display();
}
void getDataGlob(Persona ptr[], int n){
    //"isInput" nos da si todavia queremos inputs
    bool isInput = true;
    int per=0;
    int size = 4;
    //menu
    string str[size]={
        "Ingrese el nombre: ",
        "Ingrese Direccion: ",
        "Ingrese Telefono: ",
        "Ingrese Edad: ",
    };
    string data;//aqui es una var intermedia
    while(isInput && per < n){
        cout << str[0];
        getline(cin, data);//obtenemos toda la linea
        //pero cuando llegue el newline, termina el input
        //cuandp indica linea vacia
        if(data.empty()){
            //ya no queremos inputs
            isInput = false;
            break;//rompemos
        }else{
            //Si no es vacio, ponemos los datos
            ptr[per].nombre = data;
        }
        cout << str[1];
        getline(cin, ptr[per].direccion);
        cout << str[2];
        getline(cin, ptr[per].tel);
        cout << str[3];
        cin >> ptr[per].edad;  
        //lo mas importante es cin.ignore()
        //es decir ignorar lo que aun no se ha terminado de procesar 
        //por el buffer, por ejemplo el newline
        //a la siguiente vuelta de bucle procesara ese newline
        //si usamos cin.ignore()
        //lo no procesara a la siguiente vuelta
        cin.ignore();        
        per++;
    }
}
void displayMenu(){
    int size = 5;
    string arr[size]={
        "Menu General del Programa : ",
        "Opcion 1): Mostrar la lista de todos los nombres.",
        "Opcion 2): Mostrar las personas de una cierta edad.",
        "Opcion 3): Mostrar las personas cuya inicial sea la que el usuario indique.",
        "Opcion 4): Salir del programa",
    };
    for(string* ptr = arr; ptr <= &arr[size-1]; ptr++){
        cout << *ptr << endl;
    }
}
void pedirOP(int &op){
    cout << "Ingrese su opcion: ";
    cin >> op;
}
