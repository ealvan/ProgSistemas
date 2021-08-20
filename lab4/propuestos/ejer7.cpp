#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<string> partir(const string &s, char delim);
int displaySubconjuntos(int* arr, int n);
void pedirNumeros(int* size);
void llenar(int* ptr_arr,int size);

int main(){
    int sizeConjunto;

    pedirNumeros(&sizeConjunto);

    int *conjunto = new int[sizeConjunto];

    llenar(conjunto, sizeConjunto);

    displaySubconjuntos(conjunto, sizeConjunto);

    return 0;
}
vector<string> partir(const string &s, char delim){
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
 
    return elems;
}

int displaySubconjuntos(int* arr, int n){
    vector<string> list;

    for (int i = 0; i < (int) pow(2, n); i++){
        string subset = "";
        for (int j = 0; j < n; j++){

            if ((i & (1 << j)) != 0)
                subset += to_string(*(arr+j)) + "|";
        }
        if (find(list.begin(), list.end(), subset) == list.end())
            list.push_back(subset);
    }
 
    
    for (string subset : list){
        
        vector<string> arr = partir(subset, '|');
        for (string str: arr)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
void pedirNumeros(int* size){
    cout << "Escribe el numero 'n': ";
    cin >> *size;
    if(cin.fail()){
        cout << "Lo sentimos, no admitimos este valor";
        return;
    }
}
void llenar(int* ptr_arr,int size){
    int i = 1;
    for(int*ptr = ptr_arr; ptr <= &ptr_arr[size-1] ; ptr++){
        *ptr = i;
        i++;
    }
}
