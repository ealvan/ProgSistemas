#include "def.h"

void ejer6(){
    int altura = 0; //la altura de la consola   
    struct winsize w;//estrutura qque acoge los datos
    //las cargamos de los datos, cabe destacar que esta libreria
    //solo funcion en linux
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    //obtenemos el altura
    altura = (int)(w.ws_row);//recuperamos la altura

    fstream file;
    //data.txt contiene varias lineas de texto 
    //para comprobar el comportamiento del ejercicio 6
    file.open("data.txt", ios::in );
    //limpiamos la consola para que se muestre
    //el texto en toda la consola y no tenga comandos
    //que es usuario uso antes de ejecutar el programa
    system("clear");
    if(file.is_open()){
        //line recupera linea a linea 
        //los datos
        string line;
        int c;
        //mientras el file este abierto
        while(file){            
            //iniciamos el contador en 0
            c = 0;
            //obtenemos las lineas
            //y que no sobrepase la altura de la consola
            while(getline(file, line) && c <= altura){
                //la imprimimos
                cout << line << endl;
                //incrementamos el numero de lineas
                c++;
            }
            //pedimos que teclee cualquier tecla, para
            //que prosigamos con la siguiente lectura
            getchar();
            //limpiamos las anteriores lineas
            system("clear");
        }    
    }else{
        //si no se puedo abrir
        cout << "ERROR\n";
    }
}