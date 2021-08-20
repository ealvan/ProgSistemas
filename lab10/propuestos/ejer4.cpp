/*
Considerar una función raíces que calcula las raíces cuadradas de una ecuación
cuadrática. Diseñar una función de modo que se lancen excepciones si no
existen raíces reales o el primer coeficiente es cero. El tipo de excepción es
error y los valores serán No_raices_reales y primer_coeficiente_cero.
*/
#include <iostream>
#include <exception>
#include <string>
#include <cmath>
using namespace std;
//clase que hereda de exception
class Error:public exception{
    private:
        int razon;
    public:
        Error(int mot) : exception(), razon(mot) {}
        const char* what() const throw();
};
//implementando what()
const char* Error::what() const throw() {
    switch(razon) {
        case 1:
            return "No_raices_reales";
        case 2:
            return "primer_coeficiente_cero";
        default:
            return "Error inesperado";
    }
    
}
void solverEcuacionCuadratica(double arr[3], double& sol1, double& sol2){
    //ax^2 + bx + c
    //arr[a,b,c] en arr[3]
    double a = arr[0];
    double b = arr[1];
    double c =  arr[2];
    if(a == 0){
        throw Error(2);
    }
    double determinante =  pow(b,2)-4*a*c;
    if(determinante < 0){
        //si es negativo no tiene soluciones reales
        throw Error(1);
    }
    sol1 = (-b + sqrt(determinante))/2*a;
    sol2 = (-b - sqrt(determinante))/2*a;
}
int main(){
    cout << "Ingrese la ecuacion cuadratica\n"
    <<"Ejemplo : Ax^2 + Bx + C\n"
    <<"Ingrese los coeficientes de esta forma\n"
    << "\"A B C\" : "<<endl;

    double arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    double sol1, sol2;

    try{
        solverEcuacionCuadratica(arr, sol1, sol2);
        cout << "Raiz 1: "<< sol1<< endl;
        cout << "Raiz 2: "<< sol2<< endl;
        
    }catch(Error & e ){
        cout << "Exception : "<<e.what() << endl;
    }

    return 0;
}