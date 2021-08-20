#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int vnd=0;
    int vusr =0;
    int contador=0;
    srand(time(NULL));

    vnd = rand()%10+1;
    cout <<"Este programa genera un valor entre 1 y 10, tiene dos oprtunidades...";

    do{
        contador +=1;
        cout << "Escriba un numero entre 1 y 10: "<<endl;
        cin >> vusr;
        if(vusr == vnd){
            cout << "Ganaste!!!"<<endl;
            break;
        }else{
            cout << "El nuemro no es ese "<<endl;
        }

    }while(contador < 2);

    if(contador == 2){
        cout << "Perdiste"<<endl;

    }
    return 0;

}