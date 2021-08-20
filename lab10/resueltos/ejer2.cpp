#include <iostream>
using namespace std;
//como se usa catch para capturar todas las excepciones?

int main(){
    try{
        throw "All expcetion that you can be throw!";
    }catch(int i){
        cout << "Catching only integers values in message"<<endl;
    }catch(...){
        cout << "Catching all exceptions !!"<<endl;
    }
}

