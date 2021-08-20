#include "def.h"

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
void implementacion_2(){
    //expreRegular que hace match con las palabras en el textp
    regex reg("\\w+"); 
    //contador de palabras
    int countWords  =0;
    string word;
    fstream file;
    //abrimos el archivo de texto
    file.open("test.txt", ios::in);

    if(file.is_open()){
        string line;//la linea
        int cant;//la cantidad de palabras
        while(getline(file, line)){
            //capturamos la cntidad de ocurrencias
            cant = getSize(line, reg);
            //cpaturamos el puntero de array
            string* matches = storeMatches(line, reg, cant);
            bool wordHaches = 0;
            //y contamos las palabras y ya no sus haches
            //solo hasta "i < cant", por que luego
            //la memoria subsiguiente ya no nos pertenece
            for(int i =0; i < cant; i++){
                wordHaches = esIntercalable(*(matches + i));
                //si es una palabra intercambiable
                if(wordHaches){
                    //contar esa palabara
                    countWords++;
                }
            }
        }
    }
    //mostramos el numero de palabras
    cout << "El numero de palabras intercalables es : " << countWords << endl;

}