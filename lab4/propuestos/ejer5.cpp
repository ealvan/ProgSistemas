#include <iostream>
#include <string>
#include <cmath>


using namespace std;
void printArray(int* ptrarr,int size);
bool esPar(int par);
void pedir10numeros(int* ptrArr,int size, int*par);
bool esNumeroPerfecto(int num);
bool esPerfecto(long long int n);
int inverse(int n);
void funcion3();
void funcion2();
void funcion1();
void displayMenu();

int main(){
    int op;
    bool seguimos = true;
    do{
        displayMenu();
        cin >> op;

        switch (op){
        case 1:
            funcion1();
            cout << endl;
            break;
        case 2:
            funcion2();
            cout << endl;
            break;
        case 3:
            funcion3();
            cout << endl;
            break;
        case 4:
            seguimos = false;
            break;
        default:
            cout << "No aceptamos la opcion "<<op<<endl;
            break;
        }
    }while(seguimos);
    return 0;
}
/*
Funcion 1
Escriba una función en la que se introduzcan
10 enteros y determine cuáles de estos
enteros son pares y cuales son impares.
*/
void funcion1(){
    const int size = 10;
    int *arr = new int[size];
    int pares = 0;       
    pedir10numeros(arr,size,&pares);
    int* arrPar = new int[pares];
    int* arrImpar = new int[size-pares];
    int i=0,j =0;
    for(int* ptr = arr; ptr <= &arr[size-1]; ptr++){
        int aux = *ptr;
        if(esPar(aux)){
            arrPar[i] = aux;
            i++;
        }else{
            arrImpar[j] = aux;
            j++;
        }
    }
    cout <<"Numeros PARES"<<endl;
    printArray(arrPar,pares);
    cout <<"Numeros IMPARES"<<endl;
    printArray(arrImpar,size - pares);
}
void pedir10numeros(int* ptrArr,int size, int*par){
    int count = 1;
    for(int* ptr = ptrArr; ptr <= &ptrArr[size -1]; ptr++ ){
        cout << "Inserte el numero "<<(count)<<":";
        cin >> *ptr;
        if(esPar(*ptr)){
            (*par)++;//no *par++, ni *(par)++,SOLO (*par)++
        }
        count++;
    }
}
bool esPar(int par){
    if(par % 2 == 0){
        return true;
    }
    return false;
}
void printArray(int* ptrarr,int size){
    for(int* ptr = ptrarr; ptr <= &ptrarr[size-1];ptr++){
        cout << *ptr << " ";
    }
    cout << endl;
}
//FUNCION 2
/*
Un número entero es un “número perfecto” si sus factores,
incluyendo al 1 (pero excluyendo en el número mismo),
suman igual que el número. Ejemplo: 6 es un numero 
perfecto porque 6= 1+2+3. Escriba una función que 
regrese los primeros 100 números perfectos. 
Esta función debe tener una función anidada
que determine al número perfecto.
*/
void funcion2(){ 
    //lambda: una funcion dentro de otra funcion
    //"nested function"
    auto esPerfecto = [](int n)
    {   
        int sum = 0;
        for(int i = 1 ; i < n; i++){
            if(n%i == 0){
                sum += i;
            }
        }
        if(sum == n){
            return true;
        }
        return false;
    };
     for(int i = 1 ; i <100; i++){
         if(esPerfecto(i)){
             cout << i<<" es numero perfecto"<<endl;
         }
     }
    
}

void funcion3(){
    int n;
    cout << "Ingrese el numero: ";
    cin >> n;
    //validar
    if(cin.fail()){
        cout << "Solo aceptamos numeros enteros..."<< endl;
        return;
    }
    if(n < 1000 || n > 9999){
        cout << "Solo aceptamos numeros enteros de 4 digitos"<<endl;
        return;
    }
    cout << "El numero inverso de "<< n<< " es : " << inverse(n)<<endl;
}
int inverse(int n){
    string origin = to_string(n);
    string inverso="";
    for(int i = origin.size()-1; i >= 0 ; i--){
        inverso += origin[i];
    }
    return stoi(inverso);
}

void displayMenu(){
    int size = 4;
    string menu[size]={
        "1) Decir Par o impar de 10 numeros",
        "2) Dar los numeros perfectos en los 100 primeros numeros",
        "3) Calcular el inverso un numero entero de 4 digitos\n"  
        "4) Salir"       
    };
    for(int i = 0; i < size ; i++){
        cout << menu[i] << endl;
    }
    cout << "Ingrese su opcion: ";
}




