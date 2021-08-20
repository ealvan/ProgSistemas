#include <iostream>

using namespace std;

void getMin_and_Max(int arr[], int* min, int* max,int size){
    int *ptr;
    for(ptr = arr+1; ptr <= &arr[size-1]; ptr++){
        if(*ptr > *max){
            *max = *ptr;//change addres of  max
        }
        if(*ptr < *min){
            *min = *ptr;//ptr is address
        }
    }
}
void get_Min_and_Max(int arr[], int*min, int*max, int size){

    for(int *ptr = arr+1; ptr <= &arr[size - 1]; ptr++){
        if(*ptr > *max){
            //cambiando esta el valor que
            //tiene esa direccion
            *max = *ptr;//arr[0] = *ptr;
        }
        //como arr[0] ahora es 1
        //como arr[1] ahora es 1
        //como el ptr min y ptr max tienen la misma
        //direccion, entonces si cambia el ptr_max, tambien cambia el ptr min
        //nunca entra en el if, ps siempre value < value-> false
        if(*ptr < *min){
            *min = *ptr;
        }
        //pero as cambiar de valor continuamente,
        //cambia siempre al valor maximo
        //lo cual nos deja con ambos punteros en el valor maximo!!!
    }

}
int main(){
    // int arr[] = {-1 , 1, 2, 3, 4};
    // int min =  arr[0];
    // int max =  arr[0];
    // int size = sizeof(arr)/sizeof(arr[0]);
    // getMin_and_Max(arr,&min, &max, size);
    // cout <<"Menor : "<< min <<endl;
    // cout <<"Mayor : "<< max <<endl;
    // cout << size << endl;
    // delete []arr;
    //////////////////////////
    int arr[] = {-1 , 1, 2, 3, 4};
    int* min =  &arr[0];
    int* max =  &arr[0];
    int size = sizeof(arr)/sizeof(arr[0]);
    get_Min_and_Max(arr,min, max, size);
    cout <<"Menor : "<< *min <<endl;
    cout <<"Mayor : "<< *max <<endl;
    cout << size << endl;
    
    return  0;
}