#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char l;
    long i, lon;
    fstream fich("prueba.dat",ios::in | ios::out | ios::trunc | ios::binary);
    fich << "Abaraquedabra"<<flush;

    fich.seekg(0L, ios::end);

    lon = fich.tellg();

    for(i = 0L; i< lon; i ++){
        fich.seekg(i, ios::beg);
        fich.get(l);
        if(l == 'a'){
            fich.seekp(i, ios::beg);
            fich << 'e';
        }
    }
    cout << "Salida"<< endl;
    fich.seekg(0L, ios::beg);
    for(i = 0L; i < lon; i++){
        fich.get(l);
        cout << l;
    }
    cout << endl;
    fich.close();

}