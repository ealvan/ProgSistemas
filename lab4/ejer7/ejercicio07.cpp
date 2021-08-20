#include <iostream>
#include <cstdlib>
//dar un numero de random!
using namespace std;

int main(){

    int a = rand() ;

    cout << (a%10 +1) << endl;

    cout << "RAND MAX para este equipo tiene un valor de: "<<RAND_MAX<< endl;
    return 0;
}