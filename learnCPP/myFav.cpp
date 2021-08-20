#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main(){
    string color, pluralNoun, celebrity;
    cout << "Type your color: " << endl;
    getline(cin , color);
    cout << "Type your plural Noun: " << endl;
    getline(cin , pluralNoun);
    cout << "Type your celebrity: " << endl;
    getline(cin , celebrity);

    cout << "Roses are "<< color << endl;
    cout << pluralNoun << " are Blue. "<<  endl;
    cout << "I love "<< celebrity << endl;

    return 0;
}