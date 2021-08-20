#include "def.h"

void ejer4(){
    string filename;
    cout << "Para salir del programa escriba exit"<<endl
    << "Si quiere seguir leyendo el documento presion Intro o tecla enter"<<endl;;
    cout << "Ingrese fichero : ";
    cin >> filename;

    fstream file;
    file.open(filename, ios:: in);

    if(file.is_open()){
        string line;
        
        do{ 
            int count = 0;
            
            while(getline(file, line) && count < 25){
                cout <<"line "<<(count+1)<<" "<< line << endl;
                count++;
            }
            
            line = "";
            getline(cin, line);
            cin.ignore();

            if(!line.empty()){
                cout << "Usted salio del programa exitosamente"<<endl;
                exit(0);
            }
            
        }while(!file.eof());
        file.close();
    }
    cout << "El programa termino. Tenga un buen dia."<< endl;
}