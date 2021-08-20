#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iomanip> //para setprecision()
using namespace std;
//la estrucutra cliente
struct Cliente{
    string nombre;
    int nroUnit;
    double precio;
    string estado;
    void display(){
        cout << "Nombre : "<<nombre<<endl
        << "Numero de unidades : "<<nroUnit<<endl
        << "Precio Unitario : "<<setprecision(4)<<precio <<"$"<< endl
        << "Estado : "<<estado<<endl
        << "Total de Factura: "<< setprecision(4)<<nroUnit*precio<<endl<<endl;
    }
};
//Decalracion de funciones
string genName();
double fRand(double fMin, double fMax);
string genEstado();
void display(int n, struct Cliente c[]);
void displayMorosos(int n, Cliente cli[]);
void displayPagadosN(int n, Cliente cli[],double total);
void generate(int n);

int main(){
    srand(time(NULL));
    int n;
    cout << "Ingrese numero de clientes a generar: ";
    cin >> n;
    generate(n);

}



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
    
    int r = rand() % (size) ;// 0 a 6
    int l = rand() % (s);
    return arr[r] +" "+ lastname[l];
};

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
string genEstado(){
    int size = 3;
    string states[] = {
        "MOROSO",
        "ATRASADO",
        "PAGADO"
    };
    int r = rand()%size;
    return states[r];

}
//Display los general
void display(int n, struct Cliente c[]){
    cout << "Data de Clientes Random ..."<<endl;
    for(int i =0; i< n; i++){
        cout << "Cliente #"<<(i+1)<<": "<<endl;
        c[i].display();
    }
}
//Display losd e estado MOROSOS
void displayMorosos(int n, Cliente cli[]){
    cout << "Data de Clientes MOROSOS ..."<<endl;
    for(int i =0; i< n; i++){
        if(cli[i].estado == "MOROSO"){
            cli[i].display();
        };
    }
}
//Display losd e estado PAGADO
void displayPagadosN(int n, Cliente cli[],double total){
    cout << "Data de Clientes PAGADOS "<< " mayor a " << total <<": "<<endl;
    for(int i =0; i< n; i++){
        if(cli[i].estado == "PAGADO"){
            //cantidad total de la factura > limite
            if(cli[i].nroUnit*cli[i].precio > total){
                cli[i].display();
            }
        };
    }
}
//generar datos
void generate(int n){
    struct Cliente clientes[n];
    for(int i =0; i < n; i++){
        clientes[i].nombre = genName();
        clientes[i].nroUnit = (rand()%12+1);
        clientes[i].precio = fRand(2, 100);
        clientes[i].estado = genEstado();
    }
    displayMorosos(n,clientes);
    displayPagadosN(n, clientes, 200.12);
}