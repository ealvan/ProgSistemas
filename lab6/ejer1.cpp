#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

void pascal(int n);
int* makeRow(int *arr, int& size);


//funcion principal
int main(){
    pascal(6);
    
}

//haciendo filas
int* makeRow(int *arr, int& size){
    int init = *(arr);//1
    int end = *(arr + size -1);//1
    
    int *newRow = new int[size+1];
    
    
    for(int i = 1; i < size ; i++){
        int val = *(arr+i) + *(arr + i -1);
        *(newRow+i) = val;
    }
    *newRow = init;
    
    *(newRow + size) = end;
    size = size+1;
    return newRow;
}
//haciendo la piramide
void pascal(int n){
    int size = 1;
    int initArr[size] = {1};
    int *ptr = initArr;
    cout << *ptr << endl;

    for(int i =0; i< n; i++){
        ptr = makeRow(ptr, size);
        for(int j = 0; j < size; j++){
            cout <<*(ptr + j)<< " ";
        }
        cout << endl;
    }
}