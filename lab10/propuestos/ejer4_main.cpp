#include "ejer4_impl.cpp"
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