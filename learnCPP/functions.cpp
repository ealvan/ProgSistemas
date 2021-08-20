#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void sayHi(string name, int age1);

double quarter(int num){
    return pow(num, 4);
}


int main(){
    sayHi("Mike", 22);
    sayHi("Mr Bean", 21);
    sayHi("HoloLulue",19);

    double answer = quarter(12.0);
    cout << "NUM ** 4 is : " << quarter(12) << endl;
    cout << "NUM ** 4 is : " << answer << endl;


    return 0;
}

void sayHi(string name, int age){
    cout << "Hello "<< name << " you are " << age << endl;
}