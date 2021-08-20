#include <iostream>

using namespace std;




int main(){
    struct {
        string nombre;
        char letra;
        float nota;
        int edad;
    }persona;

    persona.nombre = "Juan";
    persona.letra = 'J';
    persona.nota = 7.5;
    persona.edad = 20;

    cout << "La edad es : "<<persona.edad<<endl;

    return 0;
}