#include <iostream>
#include <string>
using namespace std;

int main(){
    int a = 12;
    int &b = a;
    //gurdar la direccion donde se almacena "12" 
    //osea la varible "a"o "b"
    // int *addr = a; -> esto esta mal, 
    //por que "*addr" solo almacenar direcciones!, y no valores en si
    int *addr = &a;//estoy recuperando la direccion
    int *addr1 = &b;//estoy recuperando la misma direccion
    cout << *addr << endl;
    //cuando es *addr estamos recuperando el valor almacenado en la direccion addr 
    //cuando solo imprmimos el "addr"
    cout << addr << endl;//cuando solo estamos viendo la dirrecion

    cout << &addr << endl; 
    //cuando es "&addr" solo estamos
    //recuperando el address donde se guarda 
    // la variables "addr"
    cout << "ANALIZANDO POINTERS !" << endl;
    int m = 1;
    int &n = m; //ahora estamos haciendo una referencia

    int *address = &m; //almacenamos la dirrecion donde esta el valor de "m"
    // cout << m << endl;//imprimmos el valor de m

    //imprimimos la direccion donde se alcena el valor de "m"
    cout << "DIRECCION de m: "<< address << " -> "<< &m <<endl;
    //imprimimos el valor que almacena la direccion almacenada en "address"
    cout << "VALOR de m : "<< *address << endl; 


    //RECORRIENDO UN ARRAY CON ADDRESS
    cout << "RECORRIENDO UN ARRAY CON ADDRESS" << endl;
    int arr[] = {1 , 2 ,3 , 5, 4};
    int *addr2;//es donde se ubica un object, 
    //no es necesario poner &arr, te dara error
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        addr2 = arr + i;
        cout << *addr2 << endl;
    }
    cout << "ADDRESS TO LOOP STRINGS" << endl;
    string chains[] = {"a", "b", "c"};
    string *addrChain;
    for (int i =0; i< sizeof(chains)/sizeof(chains[0]); i++){
        addrChain = chains + i;
        cout << *addrChain << endl;
    }
}