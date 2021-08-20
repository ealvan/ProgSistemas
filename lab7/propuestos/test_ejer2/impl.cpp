#include "def.h"

//genera un nombre con nombres y apellidos
string genName(){
    int size = 7;
    string arr []={
        "Juan",
        "Pepe",
        "Jose",
        "Daniel",
        "Frank",
        "Chatt",
        "Matt",
    };
    int s = 4;
    string lastname[s] = {
        "Valdez",
        "Ticona",
        "Gonzales",
        "Morales",
    };
    //random de nombres o apellidos
    int r = rand() % (size) ;// 0 a 6
    int l = rand() % (s);
    return arr[r] +" "+ lastname[l];
}

//nos da un numero random double
double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
//generar estado del cliente
string genEstado(){
    int size = 3;
    string states[] = {
        "MOROSO",
        "ATRASADO",
        "APAGADO"
    };
    int r = rand()%size;
    return states[r];

}

//imprime en pantalla
void display(int n, struct Cliente c[]){
    cout << "Data de Clientes Random ..."<<endl;
    for(int i =0; i< n; i++){
        cout << "Cliente #"<<(i+1)<<": "<<endl;
        c[i].display();
    }
}

//nos genera datos para nuestros clientes
void generate(int n){
    struct Cliente clientes[n];
    for(int i =0; i < n; i++){
        clientes[i].nombre = genName();
        clientes[i].nroUnit = (rand()%12+1);
        clientes[i].precio = fRand(2, 100);
        clientes[i].estado = genEstado();
    }
    display(n , clientes);
}
