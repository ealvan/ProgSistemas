#include <iostream>
#include <fstream>
#include <regex>
#include <map>
using namespace std;


string* storeMatches(string str, regex reg, int n){

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
//cuantas ocurrencias nos da, de un terminado expresion regular
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
//nos da todo el contenido del file
string getAllContenido(string filename){
    fstream file;
    file.open(filename, ios::in);
    string elcontenido = "";
    if(file.is_open()){        
        filebuf* content = file.rdbuf();
        
        //la longituud del file
        size_t size = content->pubseekoff (0,file.end,file.in);
        content->pubseekpos (0,file.in);

        char *contenido = new char[size];
        
        //cargar el contenido a el ptr con esa longitud
        content->sgetn(contenido,size );
        elcontenido = contenido;

    }else{
        cout << "ERROR\n"<<endl;
    }
    
    return elcontenido;
}
//nos da la lista de todas las palabras
//en el texto
string* getWords(string filename, int& nroWords){
    fstream file;
    regex reg("\\w+");//las palabras
    
    string allContenido = getAllContenido(filename);

    nroWords = getSize(allContenido, reg);
    string* matches = storeMatches(allContenido, reg, nroWords);

    return matches;
}


string getPalabrasUnicas(string* words, int len){
    int ocur = 0;
    map<string,int> mp;
    for(int i =0; i < len; i++){
        mp[*(words + i)] = 0;//inicalizamos
    }
    for(int i = 0; i< len; i++){
        mp[*(words + i)]++;//ahora aumentamos
    }
    string enviar ="Lista de Palabras con sus ocurrencias : \n";
    map<string, int>::iterator it = mp.begin();
    while(it != mp.end()){
        string word = it->first;
        int count = it->second;
        //cout << word << " - " << count << endl;
        //ponemos todo el contenido en un string
        enviar += word + " - " + to_string(count) +'\n';
        it++;
    }  
    return enviar;
}
void filterWords(string fileIN,string fileOUT ,int& nroWords){
    string* lista = getWords(fileIN, nroWords);
    ofstream file;
    file.open(fileOUT,ios::out);
    if(file.is_open()){   
        string content = getPalabrasUnicas(lista, nroWords);
        //escribimos el contenido en uns tring
        file << content;
        file.close();
    }
}


int main () {
    int nroWords = 0;
    filterWords("origin.txt","result.txt", nroWords);
}