#include <iostream>
#include <fstream>
using namespace std;

int main(){    
    string name;
    string line;
    cout << "Dime el nombre del fichero: ";
    getline(cin, name);
    ifstream file(name.c_str());
    if(file.fail()){
        cout << "Not find file"<<endl;
        exit(1);
    }else{
        if(!file.eof()){
            getline(file,line);
            if(line.empty()){
                cout << "Fuchero vacio"<<endl;
                exit(1);
            }
        }
        cout << "El fichero tiene contenido" << endl;
        cout << line << endl;
        file.close(); 
    }
    return 0;
}