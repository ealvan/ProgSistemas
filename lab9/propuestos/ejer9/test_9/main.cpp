#include "impl.cpp"

int main(){
    //recuperamos el numero de palabras
    int words = characters("data.txt");
    //las mostramos en consola
    cout << "Numero de palabras  : "<< words << endl;
}