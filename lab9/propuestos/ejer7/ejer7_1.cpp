#include <iostream>
#include <fstream>
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
int countHaches(string word){
    
    int hs = 0;
    for(int i =0; i < word.length(); i++){
        if(word[i] == 'h' | word[i] == 'H'){
            hs++;
        }
    }
    //si empieza con h, no cuenta
    if(word[0] == 'h' | word[0] == 'H'){
        hs--;
    }
    //si hay una o varias "ch" no cuenta
    regex ch("ch|CH|cH|Ch");
    int size = getSize(word, ch);
    if(size != 0){
        hs = hs - size;
    }
    return hs;
}
int main(){

    regex reg("\\w+"); 
    int generalCountHaches =0;
    string word;
    fstream file;
    file.open("test.txt", ios::in);
    if(file.is_open()){
        string line;//la linea
        int cant;//la cantidad de palabras
        while(getline(file, line)){
            cant = getSize(line, reg);
            string* matches = storeMatches(line, reg, cant);
            int currentHaches =0;
            for(int i =0; i < cant; i++){
                currentHaches += countHaches(*(matches + i));
            }
            generalCountHaches += currentHaches;
        }
    }
    cout << "El numero de haches es : " << generalCountHaches << endl;
}