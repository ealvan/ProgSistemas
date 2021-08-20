#include <iostream>
#include <string>

using namespace std;

int main (){
    int in;
    cout << "Type one number: ";
    cin >> in;
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Your number is: " << in<<endl;
    switch(in){
        case 1:
            cout << "Its number one"<<endl;
            break;
        case 2:
            cout << "Es el 2"<<endl;
            break;
        case 3:
            cout << "Es el 3"<<endl;
        default:
            cout <<"My default case"<<endl;
            break;
    }

}