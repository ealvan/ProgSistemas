#include <iostream>
#include <string>
using namespace std;

int main(){
    string hello = "GHOLA MHUNDO!!\n";
    for(int i=0; i< hello.length(); i++){
        char current = hello[i];
        cout << current << endl;
    }
    cout << "Modificando STRING"<<endl;
    for(int i =0; i< hello.size(); i++){
        if(i%2 ==0){
            hello[i] = '+';
        }else{
            hello[i] = '-';
        }
    }

    for(int i =0; i< hello.size(); i++){
        cout << hello[i] <<endl;
    }
    

    cout << "GHOLA MUNDO !!"<<endl;
    string ghola = "GHOLA WORLD";
    //el indice donde se encuentra el string o char
    int initIndex = ghola.find("W");
    //desde el indice donde esta W, toma los 5 primeros caracteres
    string suvstr = ghola.substr(initIndex,5);
    cout << "El substring is : " << suvstr <<endl;

    return 0;

};