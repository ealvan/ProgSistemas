/*
• Crear un programa en C++ que permita 
la creaci6n de dos n6meros aleatorios utilizando la
fund& srand() conjuntamente con la
fund& rand(), comprobar el resultado varias veces 
*/

#include <iostream>
#include <cstdlib>

using namespace std;
int main(){

    int v1,v2,v3;
    for(int i =0; i<=3;i++){
        cout << "Corrida "<<i<<endl;
        v1 = rand();
        cout << "Sin semilla: "<<v1 << endl;
        srand(40);
        v2 = rand();
        cout << "Valor 2: "<<v2<<endl;
        v3 = rand()%100 + 1;
        cout << "Valor 3: "<<v3<<endl;
        srand(1);
    }
    return 0;
}