#include <iostream>

using namespace std;


double division(double dividendo, double divisor){
    
    double result = 0;
    try{
        if(divisor == 0){
            throw "Dividir por cero, no es posible";
        }
        result = dividendo/divisor;
    }catch(const char* e){
        throw;
    }
    return result;
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
    }catch(...){
        cout << "Exception innesperada ..."<<endl;
    }

    return 0;
}