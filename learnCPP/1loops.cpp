#include <iostream>
#include <string>

using namespace std;
int main(){
    string dec = "NO";

    while(dec != "SI" && dec != "YES"){
        cout << "Enter SI or YES right now!: ";
        cin >> dec;
    }
}