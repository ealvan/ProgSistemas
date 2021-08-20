/*
crear un programa
que muestre que se puede 
apuntar a valores que no tienen
tipo
*/
#include <iostream>

using namespace std;

void incrementar(void* data, int ptrsize){
    
    if(sizeof(data) == sizeof(char)){
        char *ptrchar;
        ptrchar = (char*)(data);
        (*ptrchar)++;
        cout << "Puntos datos para un char: "<< endl;
    }else if (sizeof(data) == sizeof(int)){
        int *ptrint;
        ptrint = (int*)(data);
        (*ptrint)++;
        cout << "Puntos datos para un int: "<< endl;
    }
}
void alumno(){
    char c = 'x';
    int x = 10;
    incrementar(&c, sizeof(c));
    cout << "El nuevo valor de 'c' es: " << c << endl;
    incrementar(&x, sizeof(x));
    cout << "El nuevo valor de 'x' es: " << x << endl;
    
}

int main(){
    alumno();
}
