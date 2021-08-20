#include <iostream>
#include <fstream>

using namespace std;



int main(int args, char *argv[]){
    string inputfile = argv[1];
    string outputfile = argv[2];
    cout << argv[1] << argv[2]<<endl;
    ifstream file;
    ofstream outFile;
    
    outFile.open(outputfile, ios::out);
    file.open(inputfile, ios::in);
    char in;
    while(file){
        in = file.get();
        outFile.put(in);
    }
    outFile.close();
    file.close();
}