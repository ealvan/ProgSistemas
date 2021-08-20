#include <iostream>
#include <stdlib.h>     
#include <ctime>
using namespace std;


class MyClass{   
    public:
        int a;
        int b;
        MyClass();
        MyClass(int x, int y){
            a = x;
            b = y;
        }
        void display(){
            cout << a << " ; "<< b<<endl;
        }
};
int main(){
    MyClass obj(12,-12);

    MyClass *ptr = &obj;

    obj.display();
    ptr->a=-100;
    ptr->display();
}