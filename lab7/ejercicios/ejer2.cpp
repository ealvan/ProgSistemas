
#include <iostream>

using namespace std;
enum Color{
    rojo,verde,azul
};
struct Libro
{
     char titulo[20] ;    
     int anio;
     char autor[20] ;
     
     Color color;
};
void datosLibro(Libro libro[3]){
    for(int i =0; i < 3; i++){
        cin.getline(libro[i].titulo, 20);
        cin.getline(libro[i].autor, 20);
        cin.ignore();
    }
    libro[0].color = rojo;
    libro[1].color = verde;
    libro[2].color = azul;
    
}
void mostrarLibro(Libro libro[3]){
    for(int i =0; i<  3; i++){
        cout << libro[i].titulo<<endl;
        cout << libro[i].autor<<endl;
        cout << libro[i].anio<<endl;
        cout << libro[i].color<<endl;
    }
}
int main(){
    Libro libro[3];
    datosLibro( libro);
    mostrarLibro(libro);
}