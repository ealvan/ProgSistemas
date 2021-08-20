#include <iostream>
using namespace std;

int main(){
    //converson de tipos
    //como ejemplificar una expcetion 
    //con una conversion de tipos
    //la conversion de tipos implicitps
    //no ocurre en lso try catch
    //por ejemplo 'a' es 65
    //y no se castea a 65
    try{
        throw 'a';
    }catch(int x){
        //no se ejecuta esto
        cout << "Capturado "<<x << endl;
    }catch(...){
        cout << "Catch everything"<<endl;
    }
    return 0;
}