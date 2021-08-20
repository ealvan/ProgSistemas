#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){

    ofstream file;
    file.open("frases.txt");
    
    if(file.is_open()){
        string data;
        cout << "Teclee als frases del texto: ";
        getline(cin, data);
        file << data;
    }else{
        cerr << "No se pudo abrir el archivo " << endl;
    }
    file.close();

    ifstream file_1;
    file_1.open("frases.txt" );
    if(file_1.is_open()){
        string line;
        while(getline(file_1, line)){
            cout << line << endl;
        }    
        file_1.close();
    }

}