#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
//declarar funciones
void permutar(string a, int l, int r);


int main(){
    string str;
    int number;
    cout << "Ingrese el numero permutar: ";
    cin >> number;
    str = to_string(number);
    int n = str.size();
    permutar(str, 0, n-1);
    return 0;
}


//vamos a permutar con recursividad
void permutar(string a, int l, int r){
    if (l == r){
        cout<< a <<endl;
    }else{
        for (int i = l; i <= r; i++){
            swap(a[l], a[i]);
            permutar(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}