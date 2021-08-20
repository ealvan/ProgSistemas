#include "def.h"


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
        //rdbuf nos otorga un puntero filebuf
        //disponible en <fstream>     
        filebuf* content = file.rdbuf();
        
        //la longituud del file desde el inicio hasta el final
        size_t size = content->pubseekoff (0,file.end,file.in);
        //establecemos el puntero de posición interno en posición absoluta
        content->pubseekpos (0,file.in);
        //deacuerdo al size, allocamos memoria
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
    regex reg("\\w+");//expreRegular de las palabras
    //cargamos todo el contenido
    string allContenido = getAllContenido(filename);
    //obtenmos cuantas palabras hay
    nroWords = getSize(allContenido, reg);
    //obtenemos el puntero del array
    string* matches = storeMatches(allContenido, reg, nroWords);
    //retornamos ese puntero
    return matches;
}


string getPalabrasUnicas(string* words, int len){
    int ocur = 0;
    //un mapa solo permite una 
    //ocurrencia de una palabra
    //significando que son utiles para esta tarea
    map<string,int> mp;
    
    for(int i =0; i < len; i++){
        mp[*(words + i)] = 0;//inicializamos
    }
    for(int i = 0; i< len; i++){
        mp[*(words + i)]++;//ahora aumentamos conforme se encuentre
        //las ocurrencias en el array de palabras
    }
    //y escribimos nuestrs resultados en un string
    string enviar ="Lista de Palabras con sus ocurrencias : \n";
    //capturamos el inicio en un iterador de mapas
    map<string, int>::iterator it = mp.begin();
    while(it != mp.end()){
        //capturamos el la palabra
        string word = it->first;
        //el nro de ocurrencias
        int count = it->second;
        //cout << word << " - " << count << endl;
        //ponemos todo el contenido en un string
        //y escribimos en el string
        enviar += word + " - " + to_string(count) +'\n';
        it++;//seguimos con el siguiente par del mapa
    }  
    //enviamos el string con los resultados 
    return enviar;
}
void filterWords(string fileIN,string fileOUT ,int& nroWords){
    string* lista = getWords(fileIN, nroWords);
    ofstream file;
    file.open(fileOUT,ios::out);
    if(file.is_open()){ 
        //recibimos los resultados  
        string content = getPalabrasUnicas(lista, nroWords);
        //escribimos el contenido en uns tring
        file << content;
        file.close();
    }
}

