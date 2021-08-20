/*Crear acceso aleatorio a un
  archivo que lamacena los meses*/
//meses.dat alamcena kos nombres de los meses
#include <iostream>
#include <fstream>
using namespace std;

int main(){    
    int i ;
    char mes[][20] = {
        "febrero",
        "marzo",
        "abril",
        "mayo",
        "junio",
        "julio",
        "agosto",
        "septiembre",
        "octubre",
        "noviembre" , 
        "diciembre",
    };
    string inf="meses.dat";
    string outf ="meses.dat";
    char cad[20];
    ofstream fout(inf.c_str(),ios::out, |ios::binary);
    cout << "Crear archivo en nombres de meses : ";
    for(int i =0; i < 12 ; i++){
        fout.write(mes[i],20);
    }
    fout.close();
    ifstream f_in(outf.c_str(), ios::in | ios::binary);
    cout << "acceso secuencial : "<<endl;
    f_in.read(cad,20);
    do{
        cout << cad << endl;
        f_in.read(cad,20);
    }while(!f_in.eof());
    f_in.clear();
    cout << "acceso aleatorio : "<<endl;
    for(int i = 11; i >= 0; i--){
        f_in.seekg(20*i,ios::beg);
        f_in.read(cad,20);
        cout << cad <<endl;
    }
    f_in.seekg(0, ios::end);
    int pos = f_in.tellg();
    cout << "Numero de registro: "<< (pos/20)<<endl;
    f_in.close();

    return 0;
}