#include <iostream>

using namespace std;
/*
Hacer puntero doble  
Hacer puntero triple 

*/
int main(){
    int a = 21;
    int *p = &a;
    int **pt = &p;
    int ***ptr = &pt;
    int ****ptr1 = &ptr;
    cout << "Direccion : " << *p<<endl;
    cout << "Direccion : " << **pt<<endl;
    cout << "Direccion : " << **ptr<<endl;
}