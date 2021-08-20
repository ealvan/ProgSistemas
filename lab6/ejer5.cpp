#include <iostream>
#include <string>
#include <stdlib.h>     
#include <ctime>
#include <iomanip>
using namespace std;
const int MAX = 20;
void pedirDatos(int& r, int& c);
int** randomMatrix(int r, int c, int** ptrMaestro);
int randomNumber(int,int );
void printMatriz(int f, int c, int **ptrMaestro ,string name);
int** multiplicar(int **a , int **b, int r, int c, int m);
int** initArray(int r, int c, int** master);

int main(){

    //Matriz a
    int col1, fil1;
    pedirDatos( fil1, col1);
    int **a;
    a = initArray(fil1, col1, a);
    a = randomMatrix(fil1, col1,a);
    cout << "La matriz A sera de "<<fil1 <<"x"<<fil1<<endl;
    printMatriz(fil1,col1, a,"A");

    
    int fil2;
    int col2;

    //Matriz b
    pedirDatos( fil2, col2);

    int **b;
    b = initArray(fil2, col2 , b);
    b = randomMatrix(fil2, col2,b);
    cout << "La matriz B sera de "<<fil2 <<"x"<<col2<<endl;
    printMatriz(fil2, col2, b,"B");

    if(col1 == fil2){
      int** mult = multiplicar(a, b, fil1, col2, col1); 
      printMatriz(fil1, col2 ,mult,"A*B");
    }else{
        cout << "No es posible multiplicar estas matrices "<< endl;
    }
}

int** multiplicar(int **a , int **b, int r, int c,int m){
    int **mult;
    mult = initArray(r,c,mult);
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            for(int k = 0; k < m; ++k){
                *(*(mult+i) + j ) += a[i][k] * b[k][j];
            }
        }
    }
   return mult;
}

void printMatriz(int f, int c, int **ptrMaestro ,string name){
    cout << "Matriz "<<name <<": " <<endl;
    for(int i =0; i < f; i++){
        int val =0;
        for(int j =0; j < c; j++){
            val = *( *(ptrMaestro + i) + j);
            cout << setw(3)<< val << " ";
        }
        
        cout << endl;
    } 
}

void pedirDatos(int& r, int& c){
    cout << "Numero de filas: :"<< endl;
    cin >> r;
    cout << "Numero de columnas :"<< endl;
    cin >> c;
}
int** randomMatrix(int r, int c, int** ptrMaestro){
    for(int i = 0; i< r; i++){
        for(int j =0; j < c; j++){
            *(*(ptrMaestro + i) + j) = randomNumber(j+15,i);
        }
    }
    return ptrMaestro;
}

int randomNumber(int a, int b ){
    srand(time(0));
    int random = rand()%(a)+b;
    return random;
}
int** initArray(int r, int c, int** master){
    master = new int*[r];
    for(int i = 0; i < r; i++){
        master[i] = new int[c];
        for(int j =0; j < c; j++){
              *(*(master+i)+j) = 0;
        }
    }
    return master;
}