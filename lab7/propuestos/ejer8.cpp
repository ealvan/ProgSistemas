#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip>
#include <tuple>
using namespace std;
//implementacion de estrucutas
struct Persona{
    string nombre;
    string direccion;
    string tel;
    int edad;
    void display(){
        cout <<
        "Nombre: "<<nombre<<endl<<
        " Direccion: "<< direccion<<endl<<
        " Telefono: "<<tel<<endl<<
        " Edad: "<<edad<<endl;
    }
};

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

int main(){
    int op;
    int n = 50;
    Persona people[n];
    getDataGlob(people, 50);
    do{
        displayMenu();
        pedirOP(op);
        switch(op){
            //las llaves en los case's
            //son para que las variables 
            //no salten entre caso
            //y caso, de tal forma que se queden en ese bloque
            case 1:
                {
                    cout << "Lista de Nombres: "<<endl;
                    for(int i =0; i< n; i++){
                        if(people[i].nombre == "")
                            break;
                        cout <<"#"<<(i+1)<<" "<<people[i].nombre<<endl;
                    }
                }
                break;
            case 2:
                {
                    int edad;
                    cout << "Ingrese la edad a buscar: ";
                    cin >> edad;
                    cout << "Lista de personas con "<<edad<<" años: "<<endl;
                    for(int i =0; i< n; i++){
                        if(people[i].nombre == "")
                            break;
                        if(people[i].edad == edad){
                            cout <<"#"<<(i+1)<<" ";
                            people[i].display();
                        }
                            
                            
                    }
                }
                break;
            case 3:
                {
                    char init;
                    cout << "Ingrese la inicial a buscar: ";
                    cin >> init;
                    cout << "Lista de personas con inicial "<<init<<" : "<<endl;
                    for(int i =0; i< n; i++){
                        if(people[i].nombre == "")
                            break;
                        if(people[i].nombre[0] == init)
                            people[i].display();
                    }
                }
                break;
            case 4:
                cout << "El programa termino, tenga un buen dia!"<<endl;
                break;
            default:
                cout << "No reconocemos esta opcion..."<<endl;
                break;
        }
        cout << endl;

    }while(op !=4);
}