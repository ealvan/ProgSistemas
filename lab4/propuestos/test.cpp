#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
//variable global
bool primerLanzamiento = true;

//retorna la suma de dados
int lanzarDados(){
    srand(time(0));
    int dado1 = rand()%6+1;
    int dado2 = rand()%6+1;
    string dec;
    cout << "Desea hacer su tirada Si(S)/No(N): ";
    cin >> dec;
    int suma = dado1+dado2;
    cout << "Su tirada es: "<< suma<<endl;
    
    return (dec == "S" || dec == "s")?(suma):-1;
}
int main(){
    
    int m =lanzarDados();

    while(m != -1){
        m = lanzarDados();
    }
}