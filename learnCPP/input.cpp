#include <iostream>
#include <string>

using namespace std;

int main(){
    string name;
    cout << "Ingrese su nombre: ";
    cin >> name;
    cout << "Hola amigo " << name << "¡"<< endl;
    int a, b;
    cout << "Ingrese el 1er numero: ";
    cin >> a;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Ingrese su 2do numero: ";
    cin >> b;

    int result = a +b;
    cout << "Resultado: " << result; 
}