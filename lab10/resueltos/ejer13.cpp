#include <iostream>
#include <fstream>
/*
Crear un programa en C++ que permita copiar un fichero que genere una
excepción si el fichero origen no existe o el archivo de destino no puede ser
abierto
*/
using namespace std;
// Clase derivada de "exception" para manejar excepciones
// de copia de ficheros.
class CopiaEx: public exception {
    public:
        CopiaEx(int mot) : exception(), motivo(mot) {}
        const char* what() const throw();
    private:
        int motivo;
};
const char* CopiaEx::what() const throw() {
    switch(motivo) {
        case 1:
            return "Fichero de origen no existe";
        case 2:
            return "No es posible abrir el fichero de salida";
    }
    return "Error inesperado";
} // (1)
void CopiaFichero(const char* Origen, const char *Destino) {
    unsigned char buffer[1024];

    int leido;
    ifstream fe(Origen, ios::in | ios::binary);
    if(!fe.good())
        throw CopiaEx(1); // (3) Fichero de origen no existe
    ofstream fs(Destino, ios::out | ios::binary);
    if(!fs.good()) 
        throw CopiaEx(2); // (4) No es posible abrir el fichero de salida

    do {
        fe.read(reinterpret_cast<char *> (buffer), 1024);
        leido = fe.gcount();
        fs.write(reinterpret_cast<char *> (buffer), leido);
    } while(leido);

    fe.close();
    fs.close();
}

int main() {
    char Desde[] = "excepcion.cpp"; // Este fichero
    char Hacia[] = "excepcion.cpy";
    try {
        CopiaFichero(Desde, Hacia);
    
    }catch(CopiaEx &ex) {
        cout << ex.what() << endl;
    
    } // (2)
    return 0;
}
