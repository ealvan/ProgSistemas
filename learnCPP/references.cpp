#include <iostream>
#include <string>

using namespace std;
int main(){
    int a = 123;
    int &b = a;
    a=12;
    cout << "VALUES: "<<endl;
    cout << a << endl;
    cout << b << endl;

    cout << "ADDRESS: " << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << endl;
    
    const string g = "GHOLA";
    const string &ref = g;
    cout << "VALUES: "<<endl;
    cout << g << endl;
    cout << ref << endl;

    cout << "ADDRESS: " << endl;
    cout << &g <<endl;
    cout << &ref <<endl;
    


}