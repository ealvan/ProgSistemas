#include <iostream>
#include <exception>
using namespace std;
class Test{
    public:
        Test() {
            cout << "Hello WORLD"<<endl;
        }
        ~Test(){
            cout << "Destroy"<<endl;
        }
};
struct A{
    ~A(){
        cout << "Destroy A"<<endl;
    }
};
struct B{
    ~B(){
        cout << "Destroy B"<<endl;
    }
};
    

int main(){

    try{
        A a;//first in push my stack
        B b;//second in push my stack
        //then when I destroy all
        throw 10;
        //delete structures in stack.pop() first in
        //the head stack
    }catch(int i ){
        cout << "Capturado : "<< i << endl;
    }

}