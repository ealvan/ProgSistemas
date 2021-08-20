#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string filename, linea;

    cout << "Dame el nombre: ";
    getline(cin, filename);
    
    ifstream file(filename.c_str());
    if(file.fail()){
        cout << "Hello esto paso algo raro..."<<endl;
    }

    while(! file.eof()){
        getline(file,linea);
        if(!file.eof()){
            cout << linea << endl; 
        }else{
            break;
        }
    }
    file.close();
    return 0;
}