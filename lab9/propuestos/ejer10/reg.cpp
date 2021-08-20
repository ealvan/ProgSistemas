#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    std::ifstream f("file.txt");

    if (f.is_open()){
        filebuf* content = f.rdbuf();
        
        string elcontenido;

        size_t size = content->pubseekoff (0,f.end,f.in);
        content->pubseekpos (0,f.in);

        char *contenido = new char[size];
        content->sgetn(contenido,size );
        elcontenido = contenido;

        cout << elcontenido << endl;

    }
        
}