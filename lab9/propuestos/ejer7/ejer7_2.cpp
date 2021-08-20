#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
string* storeMatches(string str, regex reg,int n){
    //inicializamos niestro pointer iterador
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    //definimos el ultimo
    sregex_iterator lastMatch;
    //allocamos memoria para "n" palabras
    string *matches = new string[n];
    //nuestro indice
    int c =0;
    //mientras no llegemos al ultimo math
    while(currentMatch != lastMatch){
        //almacenamos el valor del puntero
        smatch match = *currentMatch;
        // almacenamos el puntero
        matches[c] = match.str();
        //aumentar el la direccion de currentMatch
        currentMatch++;
        c++;
    }
    return matches;
}   

int getSize(string str, regex reg){
    //inicializamos niestro pointer iterador
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    //definimos el ultimo
    sregex_iterator lastMatch;
    //nuestro contador de palabras
    int c =0;
    while(currentMatch != lastMatch){
        c++;
        currentMatch++;
    }
    //retornar la cantidad de palabras con match
    return c;
} 
//cuenta las haches
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
//nos dice si es intercambiable
bool esIntercalable(string word){
    //si hay varias h's legitimas
    //es decir quitando las ch's, que comienzen
    //con "h" o "H"
    int hs = countHaches(word);
    //y aun asi hay h's legitimas
    if(hs > 0){
        //significa que la palabra
        //es intercalada
        return true;
    }
    return false;//cualquier otro caso, es False
}
int main(){
    regex reg("\\w+"); 
    int countWords  =0;
    string word;
    fstream file;
    file.open("test.txt", ios::in);
    if(file.is_open()){
        string line;//la linea
        int cant;//la cantidad de palabras
        while(getline(file, line)){
            cant = getSize(line, reg);
            string* matches = storeMatches(line, reg, cant);
            int wordHaches = 0;
            for(int i =0; i < cant; i++){
                wordHaches = esIntercalable(*(matches + i));
                if(wordHaches){
                    //contar esa palabara
                    countWords++;
                }
            }
        }
    }
    cout << "El numero de palabras intercalables es : " << countWords << endl;
}