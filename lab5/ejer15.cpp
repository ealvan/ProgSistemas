/*
Escribir un rpograma que demuestre que
los parametros psados por un arreglo
tambien es lo mismo que utilizar punteros
*/
#include <iostream>

using namespace std;

int fun(int ptr []){
    int x = 10;
    cout << "Size of pointer : "<< (int)sizeof(*ptr)<< endl;
    ptr = &x;
    cout << "*ptr : "<< *ptr<<endl;
    return 0;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    
    cout << "Valor con putneror: " << (int)sizeof(arr) << endl;
    fun(arr);

    return 0;
}