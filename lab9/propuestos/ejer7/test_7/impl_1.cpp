#include "def.h"

//nos da un array de los strings que hicieron
//un match(coincidencia o ocurrencia)
//con la expresion regular 
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
//nos otorfa el numero de ocurrencias
//que se encontraron en el strings "str"
//con la expresion regular "reg"
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
//nos dice cuantas haches intercaladas hay
//en una palabra
int countHaches(string word){
    
    int hs = 0;
    for(int i =0; i < word.length(); i++){
        if(word[i] == 'h' | word[i] == 'H'){
            hs++;//contamos las haches
            //sin importar la combinacion ch
            //o que este al inicio
        }
    }
    //aqui empezamos a descontar las haches

    //si empieza con h, no cuenta esa hache
    if(word[0] == 'h' | word[0] == 'H'){
        hs--;
    }

    //si hay una o varias "ch" no cuenta
    regex ch("ch|CH|cH|Ch");
    //nos da cuantas ocurrencias
    //hay de "ch", en la palabra
    int size = getSize(word, ch);
    if(size != 0){
        hs = hs - size;
    }
    //retornamos el numero de haches
    //de esa palabra
    return hs;
}

void implementacion_1(){
    //expresion regular que hara match con todas
    //las palabras dado el contenido de un archivo
    regex reg("\\w+"); 
    //registro de cuantas hacehs hay en el archivo
    int generalCountHaches =0;
    
    //string que recibe una palabra
    string word;
    //es abrimos el archivo
    fstream file;
    file.open("test.txt", ios::in);

    //si se abre
    if(file.is_open()){
        string line;//la linea
        int cant;//la cantidad de palabras
        //leeer linea a linea
        while(getline(file, line)){
            //cantidad de palabras en la actual liena
            cant = getSize(line, reg);
            //matches recibe el array de palabras
            string* matches = storeMatches(line, reg, cant);
            //
            int currentHaches =0;
            for(int i =0; i < cant; i++){
                currentHaches += countHaches(*(matches + i));
            }
            generalCountHaches += currentHaches;
        }
    }
    cout << "El numero de haches es : " << generalCountHaches << endl;
}

