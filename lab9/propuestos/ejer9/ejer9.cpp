#include <iostream>
#include <fstream>
using namespace std;

bool ISLETRA(char c) {
    if(c == ' ')
        return false;
    if(c == '\t')
        return false;
    if(c == '\n')
        return false;
    if(c == '\v')
        return false;
    if(c == '\f')
        return false;
    
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (int(c) >=0 | int(c) <= 9) ){
        return true;
    }
    return false;
}


int characters(string filename){
    fstream file;
    file.open(filename, ios::in );
    char c;
    bool is;
    string letra;
    int words = 1000;
    int index = 0;
    bool ignore = false;
    string* ptr = new string[words];
    
    if(file.is_open()){
        while(c != EOF){
            c = file.get();
            
            is = ISLETRA(c);
            if(is){
                letra += c;
                ignore = false;
            }else{
                if(!ignore){
                    *(ptr + index) = letra;
                    letra = "";
                    index++;
                    ignore = true;
                }
            }
        }
    }
    
    return index;

}
int main(){
    int words = characters("data.txt");
    cout << "Numero de palabras de  : "<< words << endl;
}