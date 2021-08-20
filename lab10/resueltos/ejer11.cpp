// Crear un programa en C++ que permita insertar un throw en un tercer nivel de try,
// mostrando que el catch que lo procesa está en el primer nivel
#include <iostream>
using namespace std;
int main() {
    try {
        try {
            try {
                throw 'x'; 
            }
            catch(int i) {}
            catch(float k) {}
        }
        catch(unsigned int x) {}
        
    }
    catch(char c) {
        cout << "El valor de c es: " << c << endl;
    }
    return 0;
}