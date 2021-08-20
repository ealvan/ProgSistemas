/*
hacer
raiz cuadrada
y potencia
con punteros y msotrar
que se puede retornar multiples valores
*/
#include <iostream>
#include <cmath>
using namespace std;

void fun(int n, int*cuadrado, double* raizcuadrada){
    *cuadrado = n*n;
    *raizcuadrada = sqrt(n);
}

int main(){
    int n = 100;
    int* sq = new int;
    double* sq_root = new double;
    fun(n, sq, sq_root);
    cout << *sq << " " << *sq_root << endl;

    return 0;
}