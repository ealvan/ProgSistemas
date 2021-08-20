/*
hacer arrays dinamicos de acuerdo
a un tamaño dado
por el usuario
*/

#include <iostream>

using namespace std;

int* createArr(int n){
    return new int[n];
}


int main(){
    int *arr = createArr(10);
    cout << *arr << endl;//0
    cout << *(arr+1) << endl;//0
    cout << arr << endl;
}