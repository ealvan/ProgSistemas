#include <iostream>
#include <string>
#include <regex>
using namespace std;

string* storeMatches(string str, regex reg,int n){

    sregex_iterator currentMatch(str.begin(), str.end(), reg);

    sregex_iterator lastMatch;
    string *matches = new string[n];
    int c =0;
    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        matches[c] = match.str();
        currentMatch++;
        c++;
    }
    return matches;
}   
int getSize(string str, regex reg){

    sregex_iterator currentMatch(str.begin(), str.end(), reg);

    sregex_iterator lastMatch;
    int c =0;
    while(currentMatch != lastMatch){
        c++;
        currentMatch++;
    }
    return c;
} 

int main () {
    string test = "chaCHochi cho nio1212a 1232131 cHanCho";
    regex reg("\\w+");
    int cant = getSize(test, reg);
    cout << cant << endl;
    string* matches = storeMatches(test, reg, cant);
    for(int i =0; i < cant; i++){
        cout << *(matches+i) << endl;
    }
    return 0;
}