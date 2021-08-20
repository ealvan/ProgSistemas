#include <iostream>
#include <fstream>
#include <string>
//Escribe las instrucciones para 
//realizar cada una de las 
//siguientes operaciones:
struct Tdato{
        int b;
        char s[100];
};
using namespace std;
int main(){
    //codigo inicial:
    
    int x, n, a[10]={1,2,3,4,5,6,7,8,9,0};
    double f;
    char nombre[]="Ejercicios ficheros binarios";
    ifstream f1;
    ofstream f2;
    f1.open("entrada.dat",ios::in  | ios::binary);
    f2.open("salida.dat", ios::out | ios::binary);

    //a. Escribir el dato entero x en el fichero.
    x = 10000;
    f2.write((char*)&x, sizeof(x));

    //b. Escribir el dato double f en el fichero.
    f = 3.141516322423;
    f2.write((char*)&f, sizeof(f));

    //c. Escribir los 5 primeros 
    //   elementos del array a en el fichero.
    f2.write((char *)&a[0],5*sizeof(int));

    //d. Escribir los 10 primeros caracteres 
    //   de la cadena nombre en el fichero.
    f2.write(nombre,10);

    //e. Escribir el dato de tipo Tdato p en el fichero.
    Tdato p = {123213, "hola amigos"};
    f2.write(reinterpret_cast<char*>(&p),sizeof(Tdato));
    f2.close();

    //f. Leer un dato entero del fichero 
    //   y almacenarlo en la variable x.
    f1.open("f1.dat", ios::binary);
    f1.read((char *)&x,sizeof(int));
    cout << x<< endl;

    //g. Leer un dato double del fichero 
    //   y almacenarlo en la variable f.
    f1.read((char *)&f,sizeof(double));
    cout << f << endl;

    //h. Leer 5 enteros y almacenarlos en el array a.
    f1.read((char *)&a[0],5*sizeof(int));
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << endl;

    //i. Leer 10 caracteres y almacenarlos
    //   en la cadena nombre.
    f1.read(nombre,10);
    cout << nombre << endl;
    //j. Leer un dato de tipo Tdato y almacenarlo en la variable p
    f1.read((char *)&p,sizeof(Tdato));
    f1.close();
    cout << p.b << endl;
    cout << p.s << endl;
}
