#include "ejer5_def.h"
void openFile(){
    fstream f;
    string path = "";
    cout << "Ingrese el path: "<<endl;
    cin >> path;
    if(cin.fail()){
        throw InputException(1);
    }
    f.open(path);

    if(!f.good()){
        throw ProcessorException(2);
    }
    string line;
    while(getline(f, line)){
        cout << line << endl;
    }
    
}


void lanzandoExcepciones(){
    cout << "Lanzando todas las excepciones"<<endl;
    for(int i =0; i < 5; i++){
        try{
            //throw ComputerException("Exception A");
            
            if(i == 1) throw ProcessorException(1);
            if(i == 3) throw InputException(2);
            if(i == 4) throw ComputerException("Exception de la Computadora\n");
            
        }
        catch(InputException& e ){
            cout << "Exception : "<<e.what()<<endl;
        }
        catch(ProcessorException& e ){
            cout << "Exception : "<<e.what()<<endl;
        }
        catch(ComputerException& e ){
            cout << "Exception : "<<e.what()<<endl;
        }
    }
}
void ejer5(){
    cout << "Excepciones ..."<<endl;
    lanzandoExcepciones();
    try{
        openFile();
    }catch(ProcessorException& e){
        cout << "Exception : "<<e.what()<<endl;
    }
}