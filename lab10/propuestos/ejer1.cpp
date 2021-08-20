#include <iostream>

using namespace std;


double division(double dividendo, double divisor){
    if(divisor == 0){
        throw "Dividir por cero, no es posible";
    }
    return dividendo/divisor;
}

int main(){

    double dsor=0, ddendo=0;
    cout << "Ingrese dividendo: ";
    cin >> dsor;
    cout << "Ingrese divisor: ";
    cin >> ddendo;

    try{
        double res = division(dsor, ddendo);
        cout << "Resultado : "<< res <<endl;
    }catch(const char* e){
        cout << "Excepcion:  "<< e << endl;
    }

    return 0;
}