#include "def.h"

void getVocales(string filename){
    fstream file;
    file.open(filename, ios::in);
    //un array de cinco posiciones
    //para porde almacenar las ocurrencias
    //de las vocaeles
    int arr[5] = {0,0,0,0,0};
    int* ptr = arr;
    if(file.is_open()){
        char c;
        while(c != EOF){
            c = file.get();
            //de acuerdo a que vocal es
            //incrementamos su valor
            //en el array
            switch(c){
                case 'a':
                case 'A':
                    arr[0]++;
                    break;
                case 'e':
                case 'E':
                    arr[1]++;
                    break;
                case 'i':
                case 'I':
                    arr[2]++;
                    break;
                case 'o':
                case 'O':
                    arr[3]++;
                    break;
                case 'u':
                case 'U':
                    arr[4]++;
                    break;
                    
            }
        }
        file.close();
    }else{
        cout << "ERROR\n";
    }
    char o = 'a';
    //mostramos en consola las ocurrencias
    for(int i =0; i < 5; i++){
        if(i==0) o = 'a';
        if(i==1) o = 'e';
        if(i==2) o = 'i';
        if(i==3) o = 'o';
        if(i==4) o = 'u';
        
        cout << o <<" -> "<< *(arr + i) << endl;
    }
    
}

