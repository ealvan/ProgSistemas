#include <iostream>
using namespace std;
void func(int *ptr, int n)throw (int*, int){
    if(ptr == NULL)
        throw ptr;
    if(n == 0)
        throw n;
    throw "Exception ocurred";
}
int main(){
    try{
        func(NULL, 0);    
    }
    catch(int * e){
        cout << "Catching exception from func()1 "<< endl;
        
    }
    catch(int n){
        cout << "Catching exception from func() 2"<< endl;

    }
    catch(...){
        cout << "Catching exception from func() 3"<< endl;
    }
    return 0;
}