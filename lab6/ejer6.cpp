#include <iostream>
#include <string>
#include <stdlib.h>     
#include <ctime>
#include <iomanip>
using namespace std;


//Declaracion de Funciones...
void displayMenu();
void wrapperTriangular();
int isTriangular(int** arr, int r, int c);
void wrapperSimetrica();
bool esSimetrica(int** arr,int square);
void wrapperTranpuesta();
void pedirnumeros(int** arr, int r, int c);
int** randomMatrix(int r, int c, int** ptrMaestro);
int randomNumber(int a, int b );
void pedirDatos(int& r, int& c);
void printMatriz(int f, int c, int **ptrMaestro ,string name);
int** initArray(int** master,int r, int c);
int** transpuesta(int** arr,int r, int c);


int main(){
    int op;
    bool seguimos = true;
    do{ 
        displayMenu();
        cout << "Deme su opcion por favor: ";
        cin >> op;
        switch(op){
            case 1:
                wrapperTranpuesta();
                break;
            case 2:
                wrapperSimetrica();
                break;
            case 3:
                wrapperTriangular();
                break;
            case 4:
                cout << "Usted salio con exito del programa"<<endl;
                cout << "Tenga un buen dia !!"<< endl;
                seguimos = false;
                break;
            default:
                cout << "Np tenemos disponible esta decision"<<endl;    
        }

    }while(seguimos);
}


int** initArray(int** master,int r, int c){
    master = new int*[r];
    for(int i =0; i < r; i++){
        *(master+i) = new int[c];
    }

    return master;
}
int** transpuesta(int** arr,int r, int c){

    int** transpuesta;
    transpuesta = initArray(transpuesta, c,r);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            *(*(transpuesta + j) + i) = *(*(arr + i ) + j);
        }
    }
    return transpuesta;
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
int randomNumber(int a, int b ){
    srand(time(0));
    int random = rand()%(a)+b;
    return random;
}


int** randomMatrix(int r, int c, int** ptrMaestro){
    for(int i = 0; i< r; i++){
        for(int j =0; j < c; j++){
            *(*(ptrMaestro + i) + j) = randomNumber(j+15,i);
        }
    }
    return ptrMaestro;
}

void pedirnumeros(int** arr, int r, int c){
    for(int i = 0; i< r; i++){
        for(int j =0; j < c; j++){
            cout << "Deme el valor del indice arr["<<i<<"]"<<"["<<j<<"]: ";
            cin >> *(*(arr + i) + j);
        }
    }
}

void wrapperTranpuesta(){
    int** arr1;
    int  r, c;
    pedirDatos(r,c);
    
    arr1 = initArray(arr1,r,c);
    
    //arr1 = randomMatrix(r,c,arr1);
    pedirnumeros(arr1,r,c);
    printMatriz(r, c , arr1, "Original");

    int**trans = transpuesta(arr1,r,c);

    printMatriz(r, c , trans, "Transpuesta");
}


//nos dice si es simetrica o no
bool esSimetrica(int** arr,int square){
    for(int i =0; i < square; i++ ){
        for(int j =0; j < square; j++){
            if(*(*(arr+i)+j) != *(*(arr+j)+i)){
                return false;
            }            
        }
    }
    return true;
}


void wrapperSimetrica(){
    int  r;
    int** arr;
    cout << "Dame el nro de filas y columnas: ";
    cin >> r;
    arr = initArray(arr,r,r);
    //arr = randomMatrix(r,r,arr);
    pedirnumeros(arr,r,r);
    bool es = esSimetrica(arr,r);
    if(es){
        cout <<" La siguiente matriz es simetrica"<<endl;
        printMatriz(r,r,arr,"Original");
        int** trans = transpuesta(arr,r,r);
        printMatriz(r,r,trans,"Transpuesta");
    }else{
        cout << "Una matriz es simetrica, si su tranpuesta es igual a la original..."<<endl;
        cout <<" La siguiente matriz no Antisimetrica"<<endl;
        printMatriz(r,r,arr,"Original");
    }
}

//nos dice si es triangular
int isTriangular(int** arr, int r, int c){
    int c1 =0,c2 = 0;
    for(int i =0; i < r; i++ ){
        for(int j =0; j < c; j++){
            if(i == j){
                if(*(*(arr+i)+j) == 0){
                    return 0;//false, ni es superio ni inferior
                    //la diagonal si o si debe tener numeros
                    //diferentes de cero
                }
            }
            if(j > i){
                if(*(*(arr+i)+j) != 0){
                    c1++;
                }
            }else if( j < i){
                if(*(*(arr+i)+j) != 0){
                    c2++;
                }
            }           
        }
    }
    if(c1 == 0){
        return -1;//matriz superior
    }else if(c2 == 0){
        return 1;//matriz inferior
    }else{
        return 0;//no es nada
    }
     
}

void wrapperTriangular(){
    int** arr;
    int r,c;
    pedirDatos(r,c);
    arr = initArray(arr,r,c);
    pedirnumeros(arr,r,c);
    
    int isTri = isTriangular(arr,r,c);
    if(isTri == 0){
        cout << "Este no es ni triangular Superior ni Inferior"<< endl;
    }else if(isTri == 1){
        cout << "Esta Matriz es Triangular Superior"<< endl;
    }else{
        cout << "Esta Matriz es Triangular Inferior"<< endl;
    }
    printMatriz(r,c,arr, "Original");

}

void displayMenu(){
    int size = 5;
    string arr[size]={
        "Menu General del Programa : ",
        "Opcion 1): La transpuesta de A (At).",
        "Opcion 2): Si A es simétrica o antisimétrica.",
        "Opcion 3): Si A es una matriz triangular superior o triangular inferior."
        "\nOpcion 4): Salir del programa"
    };
    for(string* ptr = arr; ptr <= &arr[size-1]; ptr++){
        cout << *ptr << endl;
    }
}