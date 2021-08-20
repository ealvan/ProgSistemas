#include <iostream>
#include <string>
#include <cmath>

using namespace std;
//declaracion de funciones
double Suma(double x, double y);//2 parametros
double Multiplicacion(double x, double y);//2 
double Resta(double x, double y);//2
double Division(double x, double y);//2
double ExponencialCuadrado(double x);//1 parametro
double DivEspecial(double x);//1
double RaizCuadrada(double x);//1
double Porcentaje(double x);//1

void pedirNumero(double * a);
void calcular(int op, double a , double b);
void displayMenu();

int main(){
    double a,b;
    int c;

    // pedirNumero(&a);
    // pedirNumero(&b);
    bool seguimos = true;
    do{
        displayMenu();
        cin >> c;
        if(cin.fail()){
            cout << "El valor insertado no es un numero "<<endl;
            seguimos = false;
        }else if(c==9){
            seguimos = false;
            cout << "Salio con exito de la calculadora"<<endl;
        }else{
            if(c >= 5 && c < 9){
                pedirNumero(&a);
                calcular(c,a,-1);
            }else if(c>0 && c < 5){
                pedirNumero(&a);
                pedirNumero(&b);
                calcular(c,a,b);           
            }
        }
        
    }while(seguimos);

    cout << "Tenga un buen dia!"<<endl;
    return 0;
}
void displayMenu(){
    int size = 9;
    string menu[size] = {
        "1) Suma",
        "2) Resta",
        "3) Multiplicacion",
        "4) Division",
        "5) Exponencial al cuadrado",
        "6) Division Especial(1/x)",
        "7) Raiz Cuadrada",
        "8) Porcentaje", 
        "9) Salir",
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
    double result=-1;
    switch(op){
        case 1:
            result = Suma(a,b) ;
            break;
        case 2:
            result = Resta(a,b) ;
            break;
        case 3:
            result = Multiplicacion(a,b) ;
            break;
        case 4:
            result = Division(a,b) ;
            break;
        case 5:
            result = ExponencialCuadrado(a) ;
            break;
        case 6:
            result = DivEspecial(a) ;
            break;
        case 7:
            result =  RaizCuadrada(a) ;
            break;
        case 8:
            result = Porcentaje(a)  ;
            break;
        default:
            cout << "Opcion no disponible" << endl;
    }
    cout << "El resultado de la operacion seleccionada es: "<< result << endl;
}
double Suma(double x, double y){
    double z;
    z = x+y;
    return z;
}
double Multiplicacion(double x, double y){
    return x*y;
}
double Resta(double x, double y){
    return x-y;
}

double Division(double x, double y){
    double division = -1;
    if(y != 0){
        division = x/y;
    }
    return division;
}
double ExponencialCuadrado(double x){
    return pow(x,2);
}
double DivEspecial(double x){
    double special = pow(x,-1);
    return special;
}
double RaizCuadrada(double x){
    double raizC = pow(x,0.5);
    return raizC;
}
double Porcentaje(double x){
    double percent = x/100;
    return percent;
}

