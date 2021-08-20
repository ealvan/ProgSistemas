#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

//definir el maxima capacidad del array
const int MAX = 100; 
//declaracion de funciones
bool findSillaMatriz(double arr[MAX][MAX], int n);
void printMatriz(double arr[MAX][MAX], int f, int c);


int main(){
    double arr[MAX][MAX] = {
        {1,     5,   3},
        {0.4,   2,   6},
        {0.10,  1,   9}  };
    int n = 3;
    printMatriz(arr,n,n);
    if (findSillaMatriz(arr, n) == false)
       cout << "No se encontro ningun punto de silla en la matriz "<<endl;
    return 0;
}
void printMatriz(double arr[MAX][MAX], int f, int c){
    for(int i =0; i < f; i++){
        for(int j =0; j < c; j++){
            cout << setw(4)<<arr[i][j]<< " ";
        }
        cout << endl;
    }
}
bool findSillaMatriz(double arr[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        double minFila = arr[i][0];
        int indexCol = 0;
        for (int j = 1; j < n; j++){
            if (minFila > arr[i][j]){
                minFila = arr[i][j];
                //guardamos tambien, su columna
                indexCol = j;
            }
        }
        //al final, tendremos el indice de la columna
        //del valor mas pequeño en la fila
        int k;
        //recorremos por columnas
        for (k = 0; k < n; k++){
            //si ha alguien menor, en la columna
            // que el minimo de la fila
           if (minFila < arr[k][indexCol]){
               //cortamos, y ya no se incrementa k
               //hasta la siguiente vuelta
                break;
            } 
        }

        //si hay punto de silla
        if (k == n){
           cout << "Punto de silla : " << minFila<<endl;
           return true;
        }
    }
 
    // si no hay punto de silla
    return false;
}