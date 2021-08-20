#include <iostream>
#include <fstream>

using namespace std;
int main(){
    fstream file;
    file.open("ed.txt", ios::out);
    if(file.is_open()){
        file << "Hello Matt\n";
        file << "#my first file in cpp";
        file << endl;
        file.close();
    }

    file.open("ed.txt", ios::out);
    if(file.is_open()){
        file << "Hello2"<<endl;
        file.close();
    }
}