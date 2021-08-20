#include <iostream>
#include <string>

using namespace std;

double Suma(double x, double y);
double Producto(double x, double y);
void pedirNumero(double * a);
void calcular(int op, double a , double b);
void displayMenu();


int main(){
    double a,b;
    int c;

    pedirNumero(&a);
    pedirNumero(&b);

    displayMenu();
    cin >> c;

    calcular(c,a,b);

    return 0;
}
void displayMenu(){
    int size = 2;
    string menu[size] = {
        "1) Suma",
        "2) Priducto",
    };
    
    for(string* ptr = menu; ptr <= &menu[size-1]; ptr++){
        cout << *ptr << endl;        
    }
    cout << "Que operacion desea realizar?: ";
}
void pedirNumero(double * a){
    cout << "Escriba un numero : ";
    cin >> *a;
}
void calcular(int op, double a , double b){
    switch(op){
        case 1:
            cout << "El resultado de la suma es: "<< Suma(a,b)<<endl;
            break;
        case 2:
            cout << "El resultado del producto es: "<< Producto(a,b)<<endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
    }
}
double Suma(double x, double y){
    double z;
    z = x+y;
    return z;
}
double Producto(double x, double y){
    return x*y;
}