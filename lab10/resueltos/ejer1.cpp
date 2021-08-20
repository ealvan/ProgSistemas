#include <iostream>
using namespace std;

int main(){
    
    int x = -1;
    try{
        if(x <= 0){
            throw x;
            cout << "Se ejecutara ?"<<endl;//no se ejecuta

        }
    }catch(int e){
        cout << "Catching exception : "<<e << endl;
    }
    cout << "Remainder of program"<<endl;
}