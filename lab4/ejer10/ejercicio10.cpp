#include <iostream>
#include <cstdlib>
using namespace std;
/*
• Crear un programa en C++ que permita
 crear un limite inferior y un limite
  superior que va 
  del 1 al 99, 
  del 25 al 99 y 
  del 0 al 50 

*/
int main(){
    int valor =0;
    valor = rand()%99 +1;
    cout << "rand()%100  +1  " <<valor<<endl;
    valor = rand()%75 +25;
    cout << "rand()%100 +25  " <<valor<<endl;
    valor = rand()%51 +0;
    cout << "rand()%51 +0  " <<valor<<endl;
    
    //si quieres de m ....a.....n
    //tu debes...
    // int wishValue = rand()(n-m)+m;
    return 0;
}