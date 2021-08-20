#include <iostream>
#include <string>

using namespace std;

int main(){

    int h[] ={1,21,32,43,54,65,76,87,98,109, 1032};
    int l[21];
    for(int i = 0; i < (sizeof(h)/sizeof(h[0])); i++){
        cout << h[i] << endl;
    }
    for(int i=0; i < (sizeof(l)/sizeof(l[0])); i++){
        l[i] = i;
        cout << l[i] <<endl;
    }

}