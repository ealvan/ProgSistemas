#include <iostream>
using namespace std;

int divide(int a , int b){
    if(b == 0){
        throw "Divide by 0,is a crime";
    }
    return a/b;
}

int main(){
    try{
         
        divide(12,0);
    }catch(const char* e){
        cout << e << endl;
        cout << "Exit, you can't continue"<<endl;
    }
}