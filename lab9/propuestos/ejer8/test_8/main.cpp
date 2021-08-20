#include "def.h"

int main(int args, char *argv[]){
    //el argv[0] es el archivo ejecutable
    string inputfile = argv[1];//el origen de los datos
    string outputfile = argv[2];//el destino de los datos
    cout << argv[1]<<" " << argv[2]<<endl;//imprimimos los argumentos
    ifstream file;//para leer
    ofstream outFile;//para escribir
    //si no tenemos un inputfile
    //no podemos leer nada
    if(!inputfile.empty()){
        //abrimos
        outFile.open(outputfile, ios::out);
        file.open(inputfile, ios::in);

        char in;
        //mientras haya contenido en el archivo
        while(in != EOF){
            //obtener caracter a caracter
            in = file.get();
            //escribir caracter a caracter
            outFile.put(in);
        }
        //cerramos
        outFile.close();
        file.close();
    }else{
        cout << "Necesitamos argumentos para la ejecucion"<<endl;
        cout <<"/.run <file1.txt> <fil2.txt>"<<endl;
    }
    
}