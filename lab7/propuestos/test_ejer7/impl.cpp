#include "def.h"

//input de getData
void getData(Persona* persona){
    int size = 4;
    string str[size]={
        "Ingrese el nombre: ",
        "Ingrese Año de Nacimiento: ",
        "Ingrese Mes de Nacimiento: ",
        "Ingrese Dia de Nacimiento:  ",
    };
    cout << str[0];
    cin >> persona -> nombre;
    cout << str[1];
    cin >> persona -> bourne.anio;
    cout << str[2];
    cin >> persona -> bourne.mes;
    cout << str[3];
    cin >> persona -> bourne.dia;
    
}
//imprimir en consola
void display(Persona *p){
    cout << "Datos de la persona: "<<endl;
    cout << p->nombre<<endl;
    p-> bourne.display("Fecha de Nacimiento");
}
//envuelve a getData
void getDataGlob(Persona* ptr, int n){
    for(int i =0; i < n; i++){
        cout << "Persona #"<<(i+1)<<": "<<endl;
        getData((ptr+i));
    }
}
//pedir mes
void getRequestMes(int* month){
    cout << "Que mes de desea consultar?(0:exit)";
    cin >> *month;
}
