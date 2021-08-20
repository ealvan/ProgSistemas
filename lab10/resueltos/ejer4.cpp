#include <iostream>
using namespace std;

int main(){

    try{
        throw 'A';
    }catch(int e){
        cout << e << endl;
    }
}