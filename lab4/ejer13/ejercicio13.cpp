/*
• Crear un programa en C++ que permita 
de nomeros aleatorios utilizando la 
funcion rand(), srand() y time() 
para diversas usos del programa compilado 

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
    int valor = 0;
    srand(time(NULL));

    for(int i =0; i <= 20; i++){
        valor = 5 +rand()%(10-5);
        cout << "Calificacion simulada: "<<i<<valor<< "    ";
        if(i%2==0)cout << endl;
    }
    return 0;
}