#include <exception>
#include <iostream>
#include <string>
using namespace std;

//anidamiento de try's
int main(){
    try{
        try{
            throw 12;
        }catch(int a) {
            cout << a << endl;//aqui termina
            throw;//
        }
    }catch(int b){
        cout << b<<"<<" << endl;
    }
}