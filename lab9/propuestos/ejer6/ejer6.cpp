#include <sys/ioctl.h> //ioctl() y TIOCGWINSZ
#include <unistd.h> // para STDOUT_FILENO
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int altura = 0;    
    struct winsize w;//estrutura qque acoge los datos
    //las cargamos de los datos, cabe destacar que esta libreria
    //solo funcion en linux
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    //obtenemos el altura
    altura = (int)(w.ws_row);

    fstream file;
    file.open("data.txt", ios::in );
    system("clear");
    if(file.is_open()){
        string line;
        int c;
        while(file){            
            c = 0;
            while(getline(file, line) && c <= altura){
                cout << line << endl;
                c++;
            }
            getchar();
            system("clear");
        }    
    }else{
        cout << "ERROR\n";
    }

}