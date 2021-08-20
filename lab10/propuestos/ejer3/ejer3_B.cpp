/*
Para los siguientes casos, proponer y explicar dos ejemplos en C++
considerando:
    b) Excepciones por tipos de datos incorrectos (ejemplo, al solicitar un dato
    numérico el usuario digita letras). 
*/
#include <iostream>
#include <exception>
using namespace std;

class ErrorInt: public exception{
    private:
        string razon;
    public:
        ErrorInt(string raz): razon(raz){ }
        virtual const  char* what()const throw(){
            return razon.c_str();
        }
};


int main(){
    cout << "Ingrese un numero entero: ";
    int num;
    try{
        cin >> num;
        if(cin.fail()){
            throw ErrorInt("ERROR: Solo aceptamos enteros!!!");
        }
    }catch(ErrorInt & e ){
        cout << e.what() << endl;
    }
}



