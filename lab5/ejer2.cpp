/*
Enunciado 
Crear un programa en C++ que permita hacer lo siguiente:
 Enviar un valor por referencia a una funcion 
 para obtener el cuadrado de dicho valor,
  visualizar la direccion a la que 
  hace referencia dicha variable dentro de la funci6n 

*/
#include <iostream>

using namespace std;

int cuadrado(int);
int main(){
    int n = 12;
    cout << "Valor de n : "<< n<<endl;
    cout << "Valor de n : "<< cuadrado(n)<<endl;
    cout << "Valor de su direccion : "<< &n<<endl;
    return 0;
}
int  cuadrado(int n){
   
    
    cout << "Valor de ptr : "<< &n<<endl;
     
    n *=n;
    return n;
}